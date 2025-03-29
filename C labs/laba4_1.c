#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define _USE_MATH_DEFINES
#include <math.h>
float validx1(){
    float a;
    char b=' ';
    int y;
    int v=0; 
    do{
        printf("Enter x1:");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if(fabs(a)-1e8>0){
            printf("x1 must be from -1e8 to 1e8\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float validx2(){
    float a;
    char b=' ';
    int y;
    int v=0; 
    do{
        printf("Enter x2:");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if(fabs(a)-1e8>0){
            printf("x2 must be from -1e8 to 1e8\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float validdx(){
    float a;
    char b=' ';
    int y;
    int v=0; 
    do{
        printf("Enter dx:");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if(fabs(a)-1e8>0){
            printf("dx must be from -1e8 to 1e8\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float valide(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter epsilon:");
        y=scanf("%e%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>=1) || (a<=1e-7)){
            printf("Epsilon must be from 1e-7 to 1\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float taylor(float x,float e){
    float d=1;
    float n=1;
    float res=1;
    float c=-1;
    do{
        d*=(((-1)*x*x)/(2*(n)*(2*n-1)));
        n+=1;
        res+=d;
        c*=-1;
    }while(fabs(d)>e);
    return res;
}
int main(){
    char w;
    do{
        float x1 , x2, dx, e,y;
        x1=validx1();
        x2=validx2();
        dx=validdx();
        e=valide();
        if (x1==x2){
            printf("x1 cannnot be equal x2\n");
        }else if(dx==0){
            printf("dx cannot be equal 0\n");
        }else if(x2-x1>0 && dx<0){
            printf("if x2 > x1, dx must be > 0\n");
        }else if(x1-x2>0 && dx>0){
            printf("if x1 > x2, dx must be < 0\n");
        }else if(fabs(dx)<0.001){
            printf("|dx| must be greater than 0.001\n");    
        }else{
            printf("---cosx---       ---cos(x)---      ---cos(Taylor)---     ---cos(x)-cos(Taylor)---\n");
            float t=x1;
            while((x2>x1 && t<=x2) || (x2<x1 && t>=x2)){
                float costay=taylor((t*M_PI)/180,e);
                float cosn = cos((t*M_PI)/180);
                printf("%f           %f            %f               %f       \n", t, cosn, costay, costay-cosn);
                t+=dx;
            }
        }
        fflush(stdin);
        printf("Do you want to restart the programm ? If yes - press Enter (or any other key to exit the programm)");
        w=getchar();
    }while (w=='\n');
    return 0;
}