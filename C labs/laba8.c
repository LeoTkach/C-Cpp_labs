#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define _USE_MATH_DEFINES
#include <math.h>
typedef struct resi{
    double re;
    double im;
}resist;
resist calc(double a, double b, double c, double d){
    resist res= {(a*c+b*d)/(c*c+d*d),(b*c-a*d)/(c*c+d*d)} ;
    return res;
}
float validr(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter R: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a < -1e7 )){
            printf("R must be from -1e7 to 1e7\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float validr1(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter R1: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a < -1e7 )){
            printf("R1 must be from -1e7 to 1e7\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float validr2(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter R2: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a < -1e7 )){
            printf("R2 must be from -1e7 to 1e7\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float validl(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter L: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a < -1e7 )){
            printf("L must be from -1e7 to 1e7\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float validc(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter C: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a < -1e7 )){
            printf("C must be from -1e7 to 1e7\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float validf1(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter fmin: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a < -1e7 )){
            printf("fmin must be from -1e7 to 1e7\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float validf2(float f1){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter fmax: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a < -1e7 ) || (a<=f1)){
            printf("fmax must be from -1e7 to 1e7 and bigger than fmin\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float validdf(float f1, float f2){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter df: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>1e7) || (a<-1e7 ) || (a==0)){
            printf("df must be from -1e7 to 1e7 and cannot equal 0\n");
            v=1;
        }else if ((f2>f1 && a<0)) {
            printf("df must be bigger than 0, when f2>f1\n");
            v=1;
        }else if ((f2<f1 && a>0)) {
            printf("df must be smaller than 0, when f2<f1\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float calf0(float l, float c){
    return 1/(2* M_PI*pow(l*c,0.5));
}
void cir1(){
    double r=validr(), l=validl(), C1=validc(), f1=validf1(), f2=validf2(f1), df=validdf(f1,f2);
    printf("f0=%f\n",calf0(l,C1));
    printf("      f                            Z\n");
    float f=f1;
    while((f2>f1 && f<=f2) || (f2<f1 && f>=f2)){
        double w=2* M_PI*f, a=l/C1, b=(-1.0)*(r/(w*C1)), c=r, d=(w*l-(1.0/(w*C1)));
        printf("%f             ", f);
        float ree=calc(a,b,c,d).re, imm=calc(a,b,c,d).im;
        if ((ree<1e-6) &&(imm<1e-6)){
            printf("%e + i%e      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else if(ree<1e-6){
            printf("%e + i%f      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else if(imm<1e-6){
            printf("%f + i%e      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else{
            printf("%f + i%f      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }
        f+=df;
    }
}
void cir2(){
    float r=validr(), l=validl(), C1=validc(), f1=validf1(), f2=validf2(f1), df=validdf(f1,f2);
    printf("f0=%f\n",calf0(l,C1));
    printf("      f                            Z\n");
    float f=f1;
    while((f2>f1 && f<=f2) || (f2<f1 && f>=f2)){
        double w=2* M_PI*f, a=l/C1, b=(r/(w*C1)), c=r, d=(w*l-(1.0/(w*C1)));
        printf("%f             ", f);
        float ree=calc(a,b,c,d).re, imm=calc(a,b,c,d).im;
        if ((ree<1e-6) &&(imm<1e-6)){
            printf("%e + i%e      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else if(ree<1e-6){
            printf("%e + i%f      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else if(imm<1e-6){
            printf("%f + i%e      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else{
            printf("%f + i%f      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }
        f+=df;
    }
}
void cir3(){
    float r1=validr1(), r2=validr2(), l=validl(), C1=validc(), f1=validf1(), f2=validf2(f1), df=validdf(f1,f2);
    printf("f0=%f\n",calf0(l,C1));
    printf("      f                            Z\n");
    float f=f1;
    while((f2>f1 && f<=f2) || (f2<f1 && f>=f2)){
        double w=2* M_PI*f, a=r1*r2, b=r1*(w*l-(1.0/(w*C1))), c=(r1+r2), d=(w*l-(1.0/(w*C1)));
        printf("%f             ", f);
        float ree=calc(a,b,c,d).re, imm=calc(a,b,c,d).im;
        if ((ree<1e-6) &&(imm<1e-6)){
            printf("%e + i%e      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else if(ree<1e-6){
            printf("%e + i%f      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else if(imm<1e-6){
            printf("%f + i%e      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else{
            printf("%f + i%f      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }
        f+=df;
    } 
}
void cir4(){
    float r1=validr1(), r2=validr2(), l=validl(), C1=validc(), f1=validf1(), f2=validf2(f1), df=validdf(f1,f2);
    printf("f0=%f\n",calf0(l,C1));
    printf("      f                            Z\n");
    float f=f1;
    while((f2>f1 && f<=f2) || (f2<f1 && f>=f2)){
        double w=2* M_PI*f, a=r1*r2+(l/C1), b=(w*l*r1-(r2/(w*C1))), c=(r1+r2), d=(w*l-(1.0/(w*C1)));
        printf("%f             ", f);
        float ree=calc(a,b,c,d).re, imm=calc(a,b,c,d).im;
        if ((ree<1e-6) &&(imm<1e-6)){
            printf("%e + i%e      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else if(ree<1e-6){
            printf("%e + i%f      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else if(imm<1e-6){
            printf("%f + i%e      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }else{
            printf("%f + i%f      \n",calc(a,b,c,d).re, calc(a,b,c,d).im);
        }
        f+=df;
    }
}
void (*cir[4])()={cir1, cir2, cir3, cir4};
int choosecir(){
    int a;
    char b;
    int q;
    printf("Calculation of resistance\n\n");
    do{
        printf("Choose a circuit (1,2,3,4): ");
        int y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            q=1;
        }else if(a<=0 || a>=5){
            printf("You can choose 1,2,3 or 4 circuit\n");
            q=1;
        }else{
            q=0;
            return a;
        }
    }while(q==1);
}
int main(){
    char w;
    do{
        int v=choosecir();
        if (v==1){
            cir[0]();
        }else if(v==2){
            cir[1]();
        }else if(v==3){
            cir[2]();
        }else{
            cir[3]();
        }
        fflush(stdin);
        printf("\nDo you want to restart the programm ? If yes - press Enter (or any other key to exit the programm)");
        w=getchar();
    }while (w=='\n');
    return 0;
}