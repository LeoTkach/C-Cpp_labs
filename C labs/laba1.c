#include <stdio.h>
#include <math.h>
char roman(int a){
    while (a>0){
        if (a - 1000 >=0){
        printf("M");
        a-=1000;
        }else if (a - 900 >=0){
        printf("CM");
        a-=900;
        }else if (a-500 >=0){
        printf("D");
        a-=500;
        }else if (a-400 >=0){
        printf("CD");
        a-=400;
        }else if (a-100 >=0){
        printf("C");
        a-=100;
        }else if (a-90 >=0){
        printf("XC");
        a-=90;            
        }else if (a-50 >=0){
        printf("L");
        a-=50;
        }else if (a-40 >=0){
        printf("XL");
        a-=40;            
        }else if (a-10 >=0){
        printf("X");
        a-=10;
        }else if (a-9 >=0){
        printf("IX");
        a-=9;            
        }else if (a-5 >=0){
        printf("V");
        a-=5;
        }else if (a-4 >=0){
        printf("IV");
        a-=4;            
        }else if (a-1 >=0){
        printf("I");
        a-=1;
        }
    }
}
int main(){
    int i;
    do{
        int a,y;
        char c;
        printf("Enter your number:");
        y=scanf("%d%c", &a, &c);
        if(y!=2 || c!='\n'){
            printf("Invalid data\n");
            fflush(stdin);
            i=1;
        }else if (a<=0 || a>3999){
            printf("Your number is incorrect\n");
            i=1;
        }else{
            roman(a);
            i=0;
        }  
    }while(i!=0);
    return 0;
}