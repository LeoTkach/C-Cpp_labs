#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int validn(){
    int a;
    char b;
    int q; 
    do{
        printf("Enter amount of elements: ");
        int y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            q=1;
        }else if(a<=0 || a- 20>0){
            printf("Amount of elements must be at least 1 and not greater than 20\n");
            q=1;
        }else{
            q=0;
            return a;
        }
    }while(q==1);
}
int validl(){
    int a;
    char b;
    int q; 
    do{
        printf("Enter the string length: ");
        int y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            q=1;
        }else if(a<=0 || a- 20>0){
            printf("Amount of elements must be at least 1 and not greater than 20\n");
            q=1;
        }else{
            q=0;
            return a;
        }
    }while(q==1);
}
int random(int a, int b){
    return (a+rand()%(b+1));
}
int main (){
    char w;
    do{
        int n,l,i;
        n=validn();
        l=validl();        
        char a[n][l+1];
        printf("\nIf you want to generate strings, press 1 (or any other key to enter them manually) ");
        char tu=getchar();
        if (tu=='1'){
            printf("\nUnsorted strings:\n");
            for(int i=0;i<n;i++){
                int b=0;
                do{
                    int ch=random(65,122);
                    if((ch>64 && ch<91) || (ch>96 && ch<123)){  
                        a[i][b]=ch;
                        b+=1;
                    }
                }while(b<l);
                a[i][l]='\0';
            }
            for(int i=0;i<n;i++){
                printf("The %d string is: %s\n",i+1,a[i]);
            }
            fflush(stdin);
        }else{
            for (i=0;i<n;i++){
                int v;
                do{
                    v=0;
                    printf("Enter the %d string: ",i+1);
                    scanf("%s",&a[i]);
                    if(strlen(a[i])!=l){
                        printf("You must enter the same number of characters as you entered before.\n");
                        fflush(stdin);
                        v=1;
                    }else{
                        for (int j=0;j<l;j++){
                            if (a[i][j]<65|| (a[i][j]>90 && a[i][j]<97) || a[i][j]>122){
                                v=1;
                            }
                        }
                        if (v==1){
                            printf("You should enter only english letters.\n");
                        }
                        fflush(stdin);
                    }
                }while(v==1);
            }
        }
        char (*mp)[l+1] = a;
        for (int  i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (strcmp(a[i],a[j])==1){
                    for (int o=0;o<l;o++){
                        char tmp=a[i][o];
                        *( *(mp + i) + o)=*( *(mp + j) + o);
                        *( *(mp + j) + o)=tmp;
                    }
                }
            }
        }
        printf("\nSorted strings:\n");
        for (int  i=0;i<n;i++){
            printf("The %d string is: ",i+1);
            for (int j=0;j<l;j++){
                printf("%c",*(*(mp+i)+j));
            }
            printf("\n");
        }
        printf("\nDo you whant to restart the programm ? If yes - press Enter (or any other key to exit the programm)\n");
        w=getchar();
    }while(w=='\n');
    return 0;
}