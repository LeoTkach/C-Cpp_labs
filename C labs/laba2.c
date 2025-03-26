#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
int q;
do{   
    float a,b,c,S,P,ha,hb,hc,ma,mb,mc,bia,bib,bic;
    int y;
    char t;
    printf("Enter the sides of the triangle:");
    y=scanf("%f %f %f%c", &a, &b, &c, &t);
    if (y!=4 || t != '\n'){
        printf("Invalid data, please enter only 3 numbers\n");
        q=1;
        fflush(stdin);
    }else if (a<=0 || b<=0 || c<=0){
        printf("You enterd invalid values, a,b and c must be more than 0\n");   
        q=1;
    }else if (a+b<=c || b+c<=a || a+c<=b){
        printf("Numbers must match the triangle inequality\n");
        q=1;
    }else{
        P=(a+b+c);
        S=sqrt((P/2)*(P/2-a)*(P/2-b)*(P/2-c));
        ha=2*S/a;
        hb=2*S/b;
        hc=2*S/c;
        ma=(sqrt(2*b*b+2*c*c-a*a))/2;
        mb=(sqrt(2*a*a+2*c*c-b*b))/2;
        mc=(sqrt(2*b*b+2*a*a-c*c))/2;
        bia=2*(sqrt(b*c*(P/2)*(P/2-a)))/(b+c);
        bib=2*(sqrt(a*c*(P/2)*(P/2-b)))/(a+c);
        bic=2*(sqrt(b*a*(P/2)*(P/2-c)))/(a+b);
        printf("S=%f\n",S);
        printf("P=%f\n",P);
        printf("Ha=%f  Hb=%f  Hc=%f\n",ha, hb, hc);
        printf("Ma=%f  Mb=%f  Mc=%f\n",ma, mb, mc);
        printf("Ba=%f  Bb=%f  Bc=%f\n",bia, bib, bic);
        q=0;
    }
} while (q!=0);    

return 0;
}