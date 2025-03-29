#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define _USE_MATH_DEFINES
#include <math.h>
int main(){
    char w;
    do{
        int y;
        float a,b,c;
        char t;
        printf("Enter coefficients of the equation (a,b,c): ");
        y=scanf("%f %f %f%c", &a, &b, &c, &t);
        if (y!=4 || t!='\n'){
            printf("Invalid data\n");
        }else{
            float p,q,d;
            p=b-(a*a/3);
            q=(2*a*a*a/27)-(a*b/3)+c;
            d=(p*p*p/27)+(q*q/4);
            if (d>0){
                float y1,u,v,k;
                k=((-1)*q/2+pow(d,0.5));
                if (k>=0){
                    u=pow(((-1)*q/2+pow(d,0.5)),1/3.);
                }else{  
                    u=pow(fabs((-1)*q/2+pow(d,0.5)),1/3.)*(-1);
                }
                if (u==0){
                    printf("Wrong coeficients, division by 0 happens\n");
                }else{
                    v=((-1)*p/(3*u));
                    y1=u+v-(a/3);
                    printf("x1 = %f\n", y1);  
                    printf("x2 = %f + I*%f\n",(-u-v)/2-(a/3), sqrt((3))*(u-v)/2);
                    printf("x3 = %f - I*%f\n",(-u-v)/2-(a/3), sqrt((3))*(u-v)/2);
                }
            } else if (d==0){
                if (p==0){
                    printf("Wrong coeficients, happens division by 0\n");
                }else{
                    float y1=(3*q)/p-(a/3);
                    float y2=(-3*q)/(2*p)-(a/3);
                    printf("x1 = %f\n",y1);
                    printf("x2 = %f\n",y2);
                    printf("x3 = %f\n",y2);
                }
            } else {
                float r=sqrt(-1*p*p*p/27);
                float f=acos(-1*q/(2*r));
                float y1=2*fabs(pow(r,1/3.))*cos(f/3)-(a/3);
                float y2=2*fabs(pow(r,1/3.))*cos((f+2*M_PI)/3)-(a/3);
                float y3=2*fabs(pow(r,1/3.))*cos((f+4*M_PI)/3)-(a/3);
                printf("x1 = %f\n",y1);
                printf("x2 = %f\n",y2);
                printf("x3 = %f\n",y3);
            }
        }
        fflush(stdin);
        printf("Do you whant to restart the programm ? If yes - press Enter (or any other key to exit the programm)");
        w=getchar();
    }while (w=='\n');
    return 0;
}