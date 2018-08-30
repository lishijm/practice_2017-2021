#include "stdafx.h"
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>

const int icount = 15;        //迭代次数
const float c = -0.3128;        //实部
const float d = 0.756;          //虚部
double m_real, m_image;　　　　//Mandelbro集

CvScalar colortab[21];

class Complex
{
public:
    double real;
    double image;
    
    Complex(double r=0, double i=0){real = r, image = i;}
};    

Complex operator+(const Complex& a, const Complex &b)
{
    Complex c;
    c.real = a.real + b.real;
    c.image = a.image + b.image;
    return c;
}

Complex operator*(const Complex& a, const Complex &b)
{
    Complex c;
    c.real = a.real * b.real - a.image * b.image;
    c.image = a.image * b.real + a.real * b.image;
    return c;
}

double Model(Complex a)
{
    return sqrtf(a.real * a.real + a.image * a.image);
}

double Iteration(Complex a, int n)
{
    if(n==0)
        return Model(a);
    else
    {
        Complex temp = a*a ;
        temp.real += c;
        temp.image += d;　　　　　　
//　　　 temp.real += m_real;　　把这两句代替前面的两句就是mandelbrot集了
//　　　 temp.image += m_image;
　　　　 return Iteration(temp, n-1);
　　}
}

CvScalar dye(double dist)
{
    if(dist < 1.0/4096)
        return colortab[0];
    else if(dist < 1.0/1024)
        return colortab[1];
    else if(dist < 1.0/256)
        return colortab[2];
    else if(dist < 1.0/64)
        return colortab[3];
    else if(dist < 1.0/16)
        return colortab[4];
    else if(dist < 1.0/4)
        return colortab[5];
    else if(dist < 1)
        return colortab[6];
    else if(dist < 4)
        return colortab[7];
    else if(dist < 16)
        return colortab[8];
    else if(dist < 64)
        return colortab[9];
    else if(dist < 256)
        return colortab[10];
    else if(dist < 1024)
        return colortab[11];
    else if(dist < 4096)
        return colortab[12];
    else if(dist < 16384)
        return colortab[13];
    else if(dist < 65536)
        return colortab[14];
    else if(dist < 262144)
        return colortab[15];
    else if(dist < 1048576)
        return colortab[16];
    else if(dist < 4194304)
        return colortab[17];
    else if(dist < 16777216)
        return colortab[18];
    else if(dist < 67108864)
        return colortab[19];
    else return colortab[20];
}

int _tmain(int argc, _TCHAR* argv[])
{
    colortab[0] = CV_RGB(28, 28, 28);
    colortab[1] = CV_RGB(130, 130, 130);
    colortab[2] = CV_RGB(85, 26, 139);
    colortab[3] = CV_RGB(224, 102, 255);
    colortab[4] = CV_RGB(255, 187, 255);
    colortab[5] = CV_RGB(0,0,205);
    colortab[6] = CV_RGB(72, 118, 255);
    colortab[7] = CV_RGB(0, 191, 255);
    colortab[8] = CV_RGB(0, 255, 255);
    colortab[9] = CV_RGB(0, 255, 127);
    colortab[10] = CV_RGB(0, 255, 0);
    colortab[11] = CV_RGB(50, 205, 50);
    colortab[12] = CV_RGB(173, 255, 47);
    colortab[13] = CV_RGB(255, 185, 15);
    colortab[14] = CV_RGB(255, 215, 0);
    colortab[15] = CV_RGB(255, 255, 0);
    colortab[16] = CV_RGB(255, 69, 0);
    colortab[17] = CV_RGB(255, 140, 0);
    colortab[18] = CV_RGB(255, 211, 155);
    colortab[19] = CV_RGB(255, 231, 186);
    colortab[20] = CV_RGB(255, 239, 213);

    IplImage* img = cvCreateImage(cvSize(500,500), 8, 3);

    for (int Y=0; Y<img->height; Y++)
    {
        for (int X=0; X<img->width; X++)
        {
            float x = (X - img->width/2) / 200.0;
            float y = (Y - img->height/2) / 200.0;

            m_real = x;
　　　　　　　m_image = y;
　　　　　　　Complex a(x,y);
            float dist = Iteration(a, icount);
            CvScalar color = dye(dist);

            cvSet2D(img, Y, X, color);
        }
    }

    cvNamedWindow("Julia");
    cvShowImage("Julia", img);
    cvWaitKey(0);

    //保存图片
    char* path = "C:\\Users\\Administrator\\Desktop\\Julia.bmp";
    cvSaveImage(path, img);
    cvReleaseImage(&img);
}