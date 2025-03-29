#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
float res(float x, int k, float e){
    float d=1;
    float y=1;
    do{        
        d=((x/pow(y,k-1))-y)/k;
        if (fabs(d)<e){
            return y;
        }
        y+=d;
    }while (fabs(d)>=e);
}
int main(){
    char w;
    do{
        int q=0;
        do{
            int k;
            float x,e,d,y;
            char c;
            printf("Enter x, k, e: ");
            y=scanf("%f %d %e%c", &x, &k, &e, &c);
            if (y!=4 || c!='\n'){
                printf("Invalid data\n");
                q=1;
                fflush(stdin);
            }else if(k==0){
                printf("K cannot be 0\n");
                q=1;
            }else if (e<1e-7){
                printf("e cannot be smaller than 1e-7\n");
                q=1;          
            }else if(k>0){
                if (k%2==0 && x<0){
                    printf("If k is greater than 0 and even, x cannot be less than 0\n");
                    q=1;
                }else{
                    printf("%f\n", res(x,k,e));
                    q=0;
                }
            }else{
                if (k%2==0 && x<=0){
                    printf("If k is less than 0 and even, x must be greater than 0\n");
                    q=1;
                }else if (k%2==-1 && x==0){
                    printf("If k is less than 0 and odd, x cannot be 0\n");
                    q=1;
                }else{
                    printf("%f\n",1/res(x,(-1)*k,e));
                    q=0;
                }
            }
        }while(q!=0);
        printf("Do you whant to restart the programm ? If yes - press Enter (or any other key to exit the programm)\n");
        w=getchar();
    }while (w=='\n');
    return 0;
}