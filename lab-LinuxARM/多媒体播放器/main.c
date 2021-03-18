#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<linux/input.h>

#define DEV_PATH "/dev/fb0"
#define FB_SIZE 800*480*4

int *g_pfb=NULL;
int fd=-1;

int lcd_open(){
    fd=open(DEV_PATH,O_RDWR);
    if(fd<0){
        perror("open");
        return -1;
    }
    g_pfb=(int*)mmap(NULL,FB_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(g_pfb==MAP_FAILED){
        perror("mmap");
        close(fd);
        return -1;
    }
    return 0;
}

int lcd_close(){
    munmap(g_pfb,FB_SIZE);
    close(fd);
}

void lcd_draw_pix(uint32_t x,uint32_t y,uint32_t color){
    *(g_pfb +800*(479-y)+x) = color;
}

int lcd_draw_bmp(uint32_t x,uint32_t y,const char* bmp){
    uint32_t x_s=x;
    FILE* fp=fopen(bmp,"r");
    if(!fp){
        perror("fopen");
        return -1;
    }
    char bmp_info[14]={0};
    fread(bmp_info,1,14,fp);
    uint32_t bfsize=0;
    memcpy(&bfsize,bmp_info+2,4);
    uint32_t bofset=0;
    memcpy(&bofset,bmp_info+10,4);
    printf("size:%u offset:%u\n",bfsize,bofset);
    char bmp_info2[40]={0};
    fread(bmp_info2,1,40,fp);
    
    uint32_t bfwidth = 0;
    memcpy(&bfwidth,bmp_info2+4,4);
    
    uint32_t bofheight = 0;
    memcpy(&bofheight,bmp_info2+8,4);
    
    uint16_t bitcount = 0;
    memcpy(&bitcount,bmp_info2+14,2);

    printf("w:%u h:%u,bc:%u\n",bfwidth,bofheight,bitcount);
    char* p = (char*)calloc(1,bfsize-bofset);     //在堆区申请bfsize-bofset字节的空间来存放图像数据
    char*q = p;                                   //定义指针p和q指向的地址空间相同，方便后面释放空间
    if(!p){
        puts("申请内存失败！");
        fclose(fp);
        return -1;
    }
    fread(p,1,bfsize-bofset,fp);                 //以1个字节为单位读bfsize-bofset字节大小，存放在p指针的空间中
    uint32_t x_e = x+bfwidth;                    //定义x的结束值
    uint32_t y_e = y+bofheight;                  //定义y的结束值
    uint8_t r,g,b;
    uint32_t color;
    for(;y<y_e;y++){
        for(;x<x_e;x++){
            b = *p++;
            g = *p++;
            r = *p++;
            if(bitcount == 32){
                p++;
            }
            color = r<<16|g<<8|b<<0;          //因为显示方式不同，将r向前移动16位，将g向前移动8位
            lcd_draw_pix(x,y,color);
        }
        x = x_s; 
    }
    fclose(fp);
    free(q);
}

int picture(){
    system("./picture 1.bmp 2.bmp 3.bmp 4.bmp");
}

int audio(){
    system("./audio au.bmp");
}

int video(){
    system("./video au.bmp");
}

int main(int c,char** v){
    system("killall  -KILL  madplay");
    system("killall  -KILL  mplayer");
    lcd_open();
    lcd_draw_bmp(0,0,v[1]);
    while(1){
        int xtou,ytou,countp;
        struct input_event ev={0};
        int tsfd=open("/dev/input/event0",O_RDONLY);
        if(tsfd<0){
            perror("open");
            return -1;
        }
        read(tsfd,&ev,sizeof(struct input_event));
        if(ev.type==EV_ABS){
            if(ev.code==ABS_X){
                xtou=ev.value;
            }
            if(ev.code==ABS_Y){
                ytou=ev.value;
            }
        }
        if(ev.type==EV_KEY&&ev.code==BTN_TOUCH){
            if(ev.value==0){
                if(xtou<333){
                    picture();
                }
                if(xtou>333&&xtou<666){
                    audio();
                }
                if(xtou>666&&xtou<999){
                    video();
                }
            }
        }
    }
    return 0;
}