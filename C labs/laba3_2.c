#include <stdio.h>
#include <stdlib.h>
int main()
{   char fl;
    do{ 
        int q;
        do{
            int d,m,y,r,vis,n,day;
            float f1,f2;
            char t;
            vis =0;
            printf("Enter your date (d,m,y):");
            r=scanf("%d %d %d%c",&d, &m, &y, &t);
            if (r!=4 || t!='\n'){
                printf("Invalid data, please enter only 3 numbers\n");
                q=1;
                fflush(stdin);
            }else if (d<=0 ||m<=0 || y<=0){
                printf("Numbers must be more than 0\n");
                q=1;
            }else if(d>31 || m>12 || y>9999){
                printf("Non-existent date\n");
                q=1;
            }else if((m==4 || m==6 || m==9 || m==11) && d>=31){
                printf("Non-existent date, some months contain less than 31 days\n");
                q=1;
            }else{
                if(y%100!=0 && y%4==0){
                    vis=1;
                }else if(y%100==0 && y%400==0){
                    vis=1;
                } 
                if(vis!=0 && m==2 && d>=30){
                    printf("February has 29 days in a leap year\n");
                    q=1;
                }else if(vis==0 && m==2 && d>28){
                    printf("In a common year February has 28 days\n");
                    q=1;
                }else{
                    if (m>2){
                        n=0;
                    }else if (vis!=0){
                        n=1;
                    }else if (vis==0){
                        n=2;
                    }
                    f1=365.25*y;
                    f2=30.56*m;
                    day=((int)f1 + (int)f2 + d + n) % 7;
                    if (day==0){
                        printf("Day of the week on this date is Monday\n");
                    }else if (day==1){
                        printf("Day of the week on this date is Tuesday\n");
                    }else if (day==2){
                        printf("Day of the week on this date is Wednesday\n");
                    }else if (day==3){
                        printf("Day of the week on this date is Thursday\n");
                    }else if (day==4){
                        printf("Day of the week on this date is Friday\n");
                    }else if (day==5){
                        printf("Day of the week on this date is Saturday\n");
                    }else if (day==6){
                        printf("Day of the week on this date is Sunday\n");
                    }
                    q=0;
                }
            }
        }while(q!=0);
        fflush(stdin);
        printf("Do you whant to restart the programm ? If yes - press Enter (or any other key to exit the programm)");    
        fl=getchar();
    }while(fl == '\n');
return 0;
}