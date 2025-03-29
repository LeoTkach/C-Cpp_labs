#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int validn(){
    int a;
    char b;
    int q; 
    do{
        printf("Enter amount of elements:");
        int y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            q=1;
        }else if(a<=0 || a- 50>0){
            printf("Amount of elements must be at least 1 and not greater than 50\n");
            q=1;
        }else{
            q=0;
            return a;
        }
    }while(q==1);
}
float validel(int i){
    float a;
    char b;
    int y;
    int v;
    do{
        printf("Enter %d element of array:",i);
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if(fabs(a)-1e8>0){
            printf("|Element| must be from -1e8 to 1e8\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
int main(){
    char w;
    do{
        int i;
        int n;
        int j;
        n=validn();
        float numbers[n];
        for(i=0; i<n; i++){
            numbers[i]=(validel(i+1));
            //printf("%f\n",numbers[i]);
        }
        float t;
        for (i=0; i<n-1; i++){
            for(j=i+1; j<n; j++){
                if (numbers[i]>numbers[j]){
                    t=numbers[i];
                    numbers[i]=numbers[j];
                    numbers[j]=t;
                }
            }
        }
        printf("Sorted array in ascending order:\n");
        for (i=0; i<n; i++){
            printf("%f\n",numbers[i]);
        }
        printf("Sorted array in descending order:\n");
        for (i=0; i<n; i++){
            printf("%f\n",numbers[n-i-1]);
        } 
        fflush(stdin);
        printf("Do you whant to restart the programm ? If yes - press Enter (or any other key to exit the programm)");
        w=getchar();
    }while (w=='\n');
    return 0;
}