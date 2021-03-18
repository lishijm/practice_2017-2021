#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/poll.h>
#include <linux/irq.h>
#include <asm/irq.h>
#include <linux/interrupt.h>
#include <asm/uaccess.h>
#include <mach/regs-gpio.h>
#include <mach/hardware.h>
#include <linux/platform_device.h>
#include <linux/cdev.h>
#include <linux/miscdevice.h>
#include <linux/sched.h>
#include <linux/gpio.h>

#define DEVICE_NAME     "buttons"

static unsigned long led_table [] = {
    S3C2410_GPB(5),
    S3C2410_GPB(6),
    S3C2410_GPB(7),
    S3C2410_GPB(8),
};

static unsigned int led_cfg_table [] = {
    S3C2410_GPIO_OUTPUT,
    S3C2410_GPIO_OUTPUT,
    S3C2410_GPIO_OUTPUT,
    S3C2410_GPIO_OUTPUT,
};


struct button_irq_desc {
    int irq;
    int pin;
    int pin_setting;
    int number;
    char *name; 
};

static struct button_irq_desc button_irqs [] = {
    {IRQ_EINT8 , S3C2410_GPG(0) ,  S3C2410_GPG0_EINT8  , 0, "KEY0"},
    {IRQ_EINT11, S3C2410_GPG(3) ,  S3C2410_GPG3_EINT11 , 1, "KEY1"},
    {IRQ_EINT13, S3C2410_GPG(5) ,  S3C2410_GPG5_EINT13 , 2, "KEY2"},
    {IRQ_EINT14, S3C2410_GPG(6) ,  S3C2410_GPG6_EINT14 , 3, "KEY3"},
    {IRQ_EINT15, S3C2410_GPG(7) ,  S3C2410_GPG7_EINT15 , 4, "KEY4"},
    {IRQ_EINT19, S3C2410_GPG(11),  S3C2410_GPG11_EINT19, 5, "KEY5"},
};
static volatile char key_values [] = {'0', '0', '0', '0', '0', '0'};

static DECLARE_WAIT_QUEUE_HEAD(button_waitq);

static volatile int ev_press = 0;


static irqreturn_t buttons_interrupt(int irq, void *dev_id)
{
    struct button_irq_desc *button_irqs = (struct button_irq_desc *)dev_id;
    int down;

    // udelay(0);
    down = !s3c2410_gpio_getpin(button_irqs->pin);

    if (down != (key_values[button_irqs->number] & 1))

    { // Changed

        key_values[button_irqs->number] = '0' + down;

        s3c2410_gpio_setpin(led_table[button_irqs->number], !down);
        ev_press = 1;
        wake_up_interruptible(&button_waitq);
    }
    
    return IRQ_RETVAL(IRQ_HANDLED);
}


static int s3c24xx_buttons_open(struct inode *inode, struct file *file)
{
    int i;
    int err = 0;
    
    for (i = 0; i < sizeof(button_irqs)/sizeof(button_irqs[0]); i++)

    {
        if (button_irqs[i].irq < 0)

        {
            continue;
        }
        err = request_irq(button_irqs[i].irq, buttons_interrupt, IRQ_TYPE_EDGE_BOTH, 
                          button_irqs[i].name, (void *)&button_irqs[i]);
        if (err)
            break;
    }

    if (err)

    {
        i--;
        for (; i >= 0; i--)

        {
            if (button_irqs[i].irq < 0)

            {
                continue;
            }
            disable_irq(button_irqs[i].irq);
            free_irq(button_irqs[i].irq, (void *)&button_irqs[i]);
        }
        return -EBUSY;
    }

    ev_press = 1;
    
    return 0;
}


static int s3c24xx_buttons_close(struct inode *inode, struct file *file)
{
    int i;
    
    for (i = 0; i < sizeof(button_irqs)/sizeof(button_irqs[0]); i++)

    {
        if (button_irqs[i].irq < 0)

        {
            continue;
        }
        free_irq(button_irqs[i].irq, (void *)&button_irqs[i]);
    }

    return 0;
}


static int s3c24xx_buttons_read(struct file *filp, char __user *buff, size_t count, loff_t *offp)
{
    unsigned long err;

    if (!ev_press)

    {
        if (filp->f_flags & O_NONBLOCK)
            return -EAGAIN;
        else
            wait_event_interruptible(button_waitq, ev_press);
    }
    
    ev_press = 0;

    err = copy_to_user(buff, (const void *)key_values, min(sizeof(key_values), count));

    return err ? -EFAULT : min(sizeof(key_values), count);
}

static unsigned int s3c24xx_buttons_poll( struct file *file, struct poll_table_struct *wait)
{
    unsigned int mask = 0;
    poll_wait(file, &button_waitq, wait);
    if (ev_press)
        mask |= POLLIN | POLLRDNORM;
    return mask;
}


static struct file_operations dev_fops = {
    .owner   =   THIS_MODULE,
    .open    =   s3c24xx_buttons_open,
    .release =   s3c24xx_buttons_close, 
    .read    =   s3c24xx_buttons_read,
    .poll    =   s3c24xx_buttons_poll,
};

static struct miscdevice misc = {
 .minor = MISC_DYNAMIC_MINOR,
 .name = DEVICE_NAME,
 .fops = &dev_fops,
};

static int __init dev_init(void)
{
    int ret;
 
    int i;

    for (i = 0; i < 4; i++) 
    {
        s3c2410_gpio_cfgpin(led_table[i], led_cfg_table[i]);
        s3c2410_gpio_setpin(led_table[i], 0);
    }


 ret = misc_register(&misc);

 printk (DEVICE_NAME"\tinitialized\n");

 return ret;
}

static void __exit dev_exit(void)
{
 misc_deregister(&misc);
}

module_init(dev_init);
module_exit(dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("FriendlyARM Inc.");

header.h
#include <linux/soundcard.h>
#include<wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<dirent.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/time.h>
#include<sys/select.h>
#include<sys/ioctl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define BUFSIZE 4096
#define up 1
#define down 2
#define changed 1;
#define not_change 2;

struct node
{
    char name[50];
    struct node *prev;
    struct node *next;
};

struct data
{
    int cmd;
    int up_or_down;
    int chg_flag;
    int pid;
    struct node *name;
};

struct node *head;
struct node *last;
struct node *random_head;
struct node *random_last;

double_cir_list.c双向循环链表来实现
void clear()
{
    char c;
    while((c = getchar()) == '\n')
    {
        ;
    }
}

void init_list()
{
    head = (struct node *)malloc(sizeof(struct node));
    head->prev = head;
    head->next = head;
    last = head;
}

void init_random()
{
    random_head = (struct node *)malloc(sizeof(struct node));
    random_head->prev = head;
    random_head->next = head;
    random_last = random_head;
}
void insert_random(char *name)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    memset(new->name,0,sizeof(new->name));
    strcpy(new->name,name);
    random_last->next = new;
    new->next = random_head;
    new->prev = random_last;
    random_last = new;
}
void insert(char *name)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    memset(new->name,0,sizeof(new->name));
    strcpy(new->name,name);
    head->prev = new;
    last->next = new;
    new->next = head;
    new->prev = last;
    last = new;
}

void display()
{
    struct node *ptr = head->next;
    while(ptr != head)
    {
        printf("%s ",ptr->name);
        ptr = ptr->next;
    }
    printf("\n");
}
void display2()
{
    struct node *ptr = head->prev;
    while(ptr != head)
    {
        printf("%s ",ptr->name);
        ptr = ptr->prev;
    }
    printf("\n");
}

void display_random()
{
    struct node *ptr = random_head->next;
    while(ptr != random_head)
    {
        printf("%s ",ptr->name);
        ptr = ptr->next;
    }
    printf("\n");
}

void choice()
{
    printf("input your choice:                                    \n ");
    printf("         k1:play              k2:pause                \n ");
    printf("         k3:next              k4:prev                 \n ");
    printf("         k5:voice add         k6:voice reduce         \n ");
    printf("******************************************************\n ");
    printf("                                                      \n ");
}

int modul()
{
    int n;
    system("clear");
    printf("choose play modul:                                     \n");
    printf("                 1:play by list                        \n");
    printf("                 2:the next you don't kown             \n");
    printf("                 3:one circle                          \n");
    scanf("%d",&n);
    while(n<0||n>3)
    {
        scanf("%d",&n);
    }
    return n;
}

void voice_add(int voice)
{
    int m = 1;
    int n = 1;
    for(m = 1;m<voice/5;m++)
    {
        for(n = 1;n<m;n++)
        {
            printf("+");
        }
        printf("%d\n",5*m);
    }
}

void voice_reduce(int voice)
{
    int m = 1;
    int n = 1;
    for(m = 1;m<voice/5;m++)
    {
        for(n = 1;n<m;n++)
        {
            printf("-");
        }
        printf("%d\n",5*m);
    }
}

void clear_screen(int module,struct node *ptr)
{
    system("clear");
    display();
    if(module == 3)
    {
        printf("%s is playing,next is %s.\n",ptr->name,ptr->name);
    }
    else
    {
        printf("%s is playing,next is %s.\n",ptr->name,(ptr->next==head||ptr->next==random_head)?ptr->next->next->name:ptr->next->name);
    }
    choice();
}

file_index.c获取歌曲目录

void file_index()
{
    DIR * dir;
    struct dirent *ptr;
    dir = opendir("/home/songs/");
    while((ptr = readdir(dir)) != NULL)
    {
        if(strcmp(ptr->d_name,".") == 0)
        {
            continue;
        }
        if(strcmp(ptr->d_name,"..") == 0)
        {
            continue;
        }
        insert(ptr->d_name);
    }
}

void random_list()
{
    int random;
    int n = 5;
    int i = 0;
    struct node *ptr = head->next;
    while(n != 0)
    {
        srand(n);
        random = rand()%5;
        if(random == 0)
        {
             random++;
        }
        while(i != random)
        {
            ptr = ptr->next;
            if(ptr == head)
            {
                ptr = ptr->next;
            }
            i++;
        }
        i = 0;
        insert_random(ptr->name);
        n--;
    }
}

//my_mp3.c主函数

int main()
{
    int voice = 50;
    int count = 0;
    int module;
    int ret;
    struct data *shmadd;
    struct node *ptr;
    int shmid;
    pid_t pid;
    char n;
    int cmd;
    int flg = 1;
    int flag;
    char sys_cmd[100];
    int buttons_fd;
    int MIX_FD;
    int iLeft = 0;
    int iRight = 0;
    int iLevel0 ,iLevel;
    iLeft = iRight = voice;
    char buttons[6] = {'0','0','0','0','0','0'};
    buttons_fd = open("/dev/buttons",0);
    MIX_FD= open("/dev/mixer", O_WRONLY);
    iLeft = iRight = voice;
    iLevel = (iRight << 8) + iLeft;
    ioctl(MIX_FD, MIXER_WRITE(SOUND_MIXER_VOLUME), &iLevel);
    if (MIX_FD == -1)
    {
        perror("Error:open /dev/mixer error");
        exit(1);
    }
    if(buttons_fd < 0) 
    {
        perror("open device buttons");
        exit(1);
    }
    module = modul();
    init_list();
    file_index();
    display();
    init_random();
    random_list();
    if((shmid = shmget(IPC_PRIVATE, BUFSIZE, 0644)) < 0)
    {
        perror("shmget");
        exit(1);
    }
    if((shmadd = (struct data *)shmat(shmid,0,0)) < (struct data *)0)
    {
        perror("shmat");
        exit(-1);
    }
    shmadd->up_or_down = down;
    shmadd->pid = 0;
    shmadd->chg_flag = 0;
    pid = fork();
    if(pid < 0)
    {
        printf("fork  error.\n");
        exit(1);
    }
    if(pid > 0)
    {
        while(1)
        {
            char current_buttons[6];
     int count_of_changed_key;
     int i;
     if(read(buttons_fd,current_buttons,(sizeof current_buttons)) != (sizeof current_buttons))
     {
         perror("read buttons:");
         exit(1);
     }
     for(i = 0,count_of_changed_key = 0;i < (sizeof buttons)/(sizeof buttons[0]);i++)
     {
         if(buttons[i] != current_buttons[i])
         {
             buttons[i] = current_buttons[i];
      if(buttons[i] != '0')
      {
          ;
      }
      if(buttons[i] == '0')
      {
          shmadd->cmd = i+1;
   shmadd->up_or_down = up;
      }
      count_of_changed_key++;
         }
     }
 }
    }
    if(pid == 0)
    {
        if(module == 1)
 {
            shmadd->name = head->next;
        }
 else 
 {
     if(module == 2)
     {
         shmadd->name = random_head->next;
     }
     else
     {
         module = 3;
         shmadd->name = head->next;
     }
 }
 while(1)
 {
     if(shmadd->up_or_down == up)
     {
         if(shmadd->cmd == 1)
  {
      shmadd->cmd =7;
      if(shmadd->pid)
      {
          kill(shmadd->pid,9);
      }
      if(count == 0)
      {
          if(fork() == 0)
          {
              shmadd->pid = getpid();
       clear_screen(module,shmadd->name);
       memset(sys_cmd,0,sizeof(sys_cmd));
       if(module == 3)
       {
           sprintf(sys_cmd,"madplay /home/songs/%s -r",shmadd->name->name);
           system(sys_cmd);
              }
       else
       {
           while(1)
           {
               system("clear");
               display();
               printf("%s is playing,next is %s.\n",shmadd->name->name,(shmadd->name->next==head)||(shmadd->name->next==random_head)?shmadd->name->next->next->name:shmadd->name->next->name);
               choice();
               memset(sys_cmd,0,sizeof(sys_cmd));
               sprintf(sys_cmd,"madplay /home/songs/%s",shmadd->name->name);
                      system(sys_cmd);
               sleep(1);
               shmadd->name = shmadd->name->next;
           }
       }
          }
      }
      else
      {
                        system("killall -CONT madplay");
             }
      count = 1;
  }
  if(shmadd->cmd == 2)
  {
      count = 1;
      system("killall -STOP madplay &");
      system("clear");
      display();
      printf("%s is pause.\n",shmadd->name->name);
      choice();
      shmadd->up_or_down = down;
  }
  if(shmadd->cmd == 3)
  {
      shmadd->cmd = 7;
      count = 1;
      shmadd->name = shmadd->name->next;
      if(shmadd->name == head||shmadd->name == random_head)
      {
          shmadd->name = shmadd->name->next;
      }
      system("killall -9 madplay");
      if(shmadd->pid)
      {
          kill(shmadd->pid,9);
      }
      system("clear");
      if(fork() == 0)
      {
          shmadd->pid = getpid();
   clear_screen(module,shmadd->name);
   if(module == 3)
   {
       memset(sys_cmd,0,sizeof(sys_cmd));
       sprintf(sys_cmd,"madplay /home/songs/%s -r",shmadd->name->name);
       system(sys_cmd);
          }
   else
   {
       while(1)
       {
           system("clear");
    display();
           printf("%s is playing,next is %s.\n",shmadd->name->name,(shmadd->name->next==head)||(shmadd->name->next==random_head)?shmadd->name->next->next->name:shmadd->name->next->name);
    choice();
    memset(sys_cmd,0,sizeof(sys_cmd));
           sprintf(sys_cmd,"madplay /home/songs/%s",shmadd->name->name);
                  system(sys_cmd);
           sleep(1);
           shmadd->name = shmadd->name->next;
       }
   }
      }
  }
  if(shmadd->cmd == 4)
  {
      shmadd->cmd = 7;
      count = 1;
      shmadd->name = shmadd->name->prev;
      if(shmadd->name == head||shmadd->name ==random_head)
      {
          shmadd->name = shmadd->name->prev;
      }
      system("killall -9 madplay");
      if(shmadd->pid)
      {
          kill(shmadd->pid,9);
      }
      system("clear");
      if(fork() == 0)
      {
          shmadd->pid = getpid();
   clear_screen(module,shmadd->name);
   if(module == 3)
   {
       memset(sys_cmd,0,sizeof(sys_cmd));
       sprintf(sys_cmd,"madplay /home/songs/%s -r",shmadd->name->name);
       system(sys_cmd);
          }
   else
   {
       while(1)
       {
           system("clear");
    display();
           printf("%s is playing,next is %s.\n",shmadd->name->name,(shmadd->name->next==head)||(shmadd->name->next==random_head)?shmadd->name->next->next->name:shmadd->name->next->name);
    choice();
    memset(sys_cmd,0,sizeof(sys_cmd));
           sprintf(sys_cmd,"madplay /home/songs/%s",shmadd->name->name);
                  system(sys_cmd);
           sleep(1);
           shmadd->name = shmadd->name->next;
       }
   }
      }
  }
  if(shmadd->cmd == 5)
  {
      clear_screen(module,shmadd->name);
      shmadd->cmd = 7;
      voice = voice + 5;
      voice_add(voice);
      iLeft = iRight = voice;
      iLevel = (iRight << 8) + iLeft;
                    ioctl(MIX_FD, MIXER_WRITE(SOUND_MIXER_VOLUME), &iLevel);
  }
  if(shmadd->cmd == 6)
  {
      clear_screen(module,shmadd->name);
      shmadd->cmd = 7;
      voice = voice - 5;
      voice_reduce(voice);
      iLeft = iRight = voice;
      iLevel = (iRight << 8) + iLeft;
                    ioctl(MIX_FD, MIXER_WRITE(SOUND_MIXER_VOLUME), &iLevel);
  }
     }
 }
    }
    close(buttons_fd);
    return 0;
}