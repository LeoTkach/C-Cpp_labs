#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int choosee(){
    int a;
    char b;
    int q;
    printf("1. cos(y/x) - 2sin(1/x) + 1/x = 0\n");
    printf("2. sin(lnx) - cos(lnx) + ylnx = 0\n\n"); 
    do{
        printf("Choose the equation: ");
        int y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            q=1;
        }else if(a<=0 || a>=3){
            printf("You can choose 1 or 2 equation\n");
            q=1;
        }else{
            q=0;
            return a;
        }
    }while(q==1);
}
int choosem(){
    int a;
    char b;
    int q;
    printf("\n1. Bisection method\n");
    printf("2. Newton method\n\n");    
    do{
        printf("Choose the method of solving: ");
        int y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            q=1;
        }else if(a<=0 || a>=3){
            printf("You can choose 1 or 2 method\n");
            q=1;
        }else{
            q=0;
            return a;
        }
    }while(q==1);
}
float valida1(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter a1: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a < -1e7 ) || (a==0)){
            printf("a1 must be from -1e7 to 1e7 and cannot equal 0\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float valida3(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter a1: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a <= 0)){
            printf("a1 must be bigger than 0 and less than 1e7\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float valida2(float a1){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter a2: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a <= a1 ) || (a==0)){
            printf("a2 must be bigger than a1 and less than 1e7 and cannor equal 0\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float validy(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter y: ");
        y=scanf("%e%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a < -1e7 )){
            printf("y must be from -1e7 to 1e7\n");
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
        printf("Enter epsilon: ");
        y=scanf("%e%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a > 1) || (a<=0)){
            printf("Epsilon must be from 0 to 1\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float coss(float y, float x){
    return (cos(y/x) - 2*sin(1/x) + 1/x);
}
float sinn(float y,float x){
    return (sinf(logf(x)) - cos(logf(x)) + y*logf(x));
}
float (*funcs[2])(float, float)={coss, sinn};
int main(){
    char w;
        do{
        float ans;
        int q=choosee(), m=choosem();
        if (q==1){
            float a1=valida1(), a2=valida2(a1), y=validy(), e=valide();
            if (m==1){
                while(fabs(a2-a1)>e){
                    float x=(a1+a2)/2;
                    if((funcs[0](y,a1)>0) && (funcs[0](y,x)>0) && (funcs[0](y,a2)>0)){
                        a2=x;
                    }else if(funcs[0](y,a1)*(funcs[0](y,x)>0)){
                        a1=x;
                    }else{
                        a2=x;
                    }
                }
                ans=a1;
                if (fabs(funcs[0](y,ans))>0.001){
                    printf("There is no root on this interval.\n");
                }else{
                    printf("Answer: %f\n",ans);
                    printf("f(%f)=%f\n",ans,funcs[0](y,ans));
                }
            }else{
                float x=a2, f=funcs[0](y,x), fp=((funcs[0](y,x+0.0001)-funcs[0](y,x))/0.0001), del=f/fp;
                int sch=0;
                while (fabs(del)>e){
                    f=funcs[0](y,x);
                    fp=((funcs[0](y,x+0.00001)-funcs[0](y,x))/0.00001);
                    del=f/fp;
                    x-=del;
                    sch+=1;
                    if (sch>300){
                        del=0;
                    }
                }
                ans=x;
                //printf("Answer: %f\n",ans);
                if ((sch>300) || (ans<a1) || (ans>a2)){
                    printf("There is no root on this interval.\n");
                }else{
                    printf("Answer: %f\n",ans);
                    printf("f(%f)=%f\n",ans,funcs[0](y,ans));
                }
            }
        }else{
            float a1=valida3(), a2=valida2(a1), y=validy(), e=valide();
            if (m==1){
                while(fabs(a2-a1)>e){
                    float x=(a1+a2)/2;
                    if((funcs[1](y,a1)>0) && (funcs[1](y,x)>0) && (funcs[1](y,a2)>0)){
                        a2=x;
                    }else if(funcs[1](y,a1)*(funcs[1](y,x))>0){
                        a1=x;
                    }else{
                        a2=x;
                    }
                }
                ans=a1;
                if (fabs(funcs[1](y,ans))>0.001){
                    printf("There is no root on this interval.\n");
                }else{
                    printf("Answer: %f\n",ans);
                    printf("f(%f)=%f\n",ans,funcs[1](y,ans));
                }
            }else{
                double x=a2, f, fp, del=1;
                int sch=0;
                while (fabs(del)>e){
                    f=funcs[1](y,x);
                    fp=(((funcs[1](y,x+0.0000100047)-funcs[1](y,x-0.0000100047)))/(2*0.0000100047));
                    //printf("%f  %f   %f\n",fp,f,x);
                    del=f/fp;
                    x-=del;
                    sch+=1;
                    
                    if (x<0){
                        del=0;
                    }
                    if (sch>100){
                        del=0;
                    }
                }
                ans=x;
                if (sch>100){
                    printf("There is no root on this interval.\n");
                }else if(ans<0){
                    printf("There is no root on this interval.\n");
                }else{
                    printf("Answer: %f\n",ans);
                    printf("f(%f)=%f\n",ans,funcs[1](y,ans));
                }
            }
        }
        fflush(stdin);
        printf("\nDo you want to restart the programm ? If yes - press Enter (or any other key to exit the programm)");
        w=getchar();
    }while (w=='\n');
    return 0;
}