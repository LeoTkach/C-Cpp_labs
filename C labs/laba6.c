#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int validn(){
    int a;
    char b;
    int q; 
    do{
        printf("Enter amount of the equations: ");
        int y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            q=1;
        }else if(a<=0 || a- 20>0){
            printf("Amount of equations must be at least 1 and not greater than 20\n");
            q=1;
        }else{
            q=0;
            return a;
        }
    }while(q==1);
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
        }else if ((a >= 1) || (a<=0)){
            printf("Epsilon must be from 0 to 1\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
float valida(int i,int j){
    float a;
    char b;
    int y;
    int v;
    do{
        printf("Enter a%d%d: ",i+1,j+1);
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if(fabs(a)-1e8>0){
            printf("|Element| must be from -1e8 to 1e8\n");
            v=1;
        }else if((i==j) && (a==0)){
            printf("This element cannnot equal 0\n");
            v=1;
        }else{    
            v=0;
            return a;
        }
    }while(v==1);
}
float validb(int i){
    float a;
    char b;
    int y;
    int v;
    do{
        printf("Enter b%d: ",i+1);
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
        printf("\n");
        int n,i,j,y,v;
        float e;
        n=validn();
        e=valide();
        printf("\n");
        char t;
        float a[n][n];
        float b[n];
        for (i=0;i<n;i++){
            for(j=0;j<n;j++){
                a[i][j]=valida(i,j);
            }
            b[i]=validb(i);
            printf("\n");
        }
        int solv=0;
        for(i=0;i<n;i++){
            int sum =0;
            for(j=0;j<n;j++){
                if(j!=i){
                    sum+=a[i][j];
                }
            }
            if (fabs(a[i][i])<=fabs(sum)){
                solv=1;
            }
        }
        printf("Entered coefficients:\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%.2f ",a[i][j]);
            }
            printf("%.2f",b[i]);
            printf("\n");
        }
        if (solv==1){
            printf("This system cannot be solved\n");
        }else{
            float xp[n], x[n], delta[n], prop;
            for (i=0;i<n;i++){
                xp[i]=b[i]/a[i][i];
            }

            int f=0;
            while(f==0){
                for(i=0;i<n;i++){
                    float h=0;
                    for(j=0;j<n;j++){
                        if (j!=i){
                            h+=a[i][j]*xp[j];
                        }
                    }
                    x[i]=(b[i]-h)/a[i][i];
                    delta[i]=fabs(x[i]-xp[i]);
                    
                }
                prop=-1;
                for (i=0;i<n;i++){
                    if(delta[i]>=prop){
                        prop=delta[i];
                    }
                }
                //printf("%f %f %f\n",x[0], prop, e);
                if (prop>=e){
                    for(i=0;i<n;i++){
                        xp[i]=x[i];
                    }
                }else{
                    printf("\nRoots of the equations:\n");
                    for(i=0;i<n;i++){
                        printf("x%d=%.2f ",i+1,x[i]);
                    }
                    f=1;
                    printf("\n");
                }
            }
        }
        fflush(stdin);
        printf("Do you want to restart the programm ? If yes - press Enter (or any other key to exit the programm)");
        w=getchar();
    }while (w=='\n');
    return 0;
}
