#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LEN 300
#define FILE_N_LEN 100
#define SIGN "Signature102927493"
typedef struct{
    char *name;
    float area;
    int population;
} City;

void create_file(){
    fflush(stdin);
    char fname[FILE_N_LEN];
    printf("Enter a file name: ");
    fgets(fname, FILE_N_LEN, stdin);
    int len = strlen(fname);
    if (fname[len - 1] == '\n') {
        fname[len - 1] = '\0';
    }
    FILE *fp;
    fp = fopen(fname, "r");
    if (fp == NULL) {
        fp = fopen(fname, "w");
        fprintf(fp,"%s\n",&SIGN);
        printf("File successfully created.\n");
    }else {
        printf("File with this name already exists\n");
    }
    fclose(fp);
}
void read_file(){
    fflush(stdin);
    char fname[FILE_N_LEN];
    printf("Enter a file name: ");
    fgets(fname, FILE_N_LEN, stdin);
    int len = strlen(fname);
    if (fname[len - 1] == '\n') {
        fname[len - 1] = '\0';
    }
    FILE *fp;
    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("There is no file with this name.\n");
    }else{
        char line[LINE_LEN];
        fgets(line, LINE_LEN, fp);
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        if (strcmp(line,SIGN)!=0){
            printf("This isn't the file that was created by this program\n");
        }else{
            printf("\n");
            while (fgets(line, LINE_LEN, fp) != NULL) {
                printf("%s", line);
            }
        }
    }
    fclose(fp);
}
void delete_file(){
    fflush(stdin);
    char fname[FILE_N_LEN];
    printf("Enter a file name: ");
    fgets(fname, sizeof(fname), stdin);
    int len = strlen(fname);
    if (fname[len - 1] == '\n') {
        fname[len - 1] = '\0';
    }
    FILE *fp;
    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("There is no file with this name.\n");
        fclose(fp);
    }else{
        char line[LINE_LEN];
        fgets(line, LINE_LEN, fp);
        // 
        int len1 = strlen(line);
        if (line[len1 - 1] == '\n') {
            line[len1 - 1] = '\0';
        }
        fclose(fp);
        if (strcmp(line,SIGN)!=0){
            printf("This isn't the file that was created by this program\n");
        }else if (remove(fname) == 0){
            printf("File was succesfully deleted\n");
        }
    }

}

float areac(){
    float a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter the area: ");
        y=scanf("%f%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a<=0) || (a>1e8 )){
            printf("Area must be bigger than 0 and smaller than 1e8\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
int popul(){
    int a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter the population: ");
        y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a<=0) || (a>1e8 )){
            printf("Population must be bigger than 0 and smaller than 1e8\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
typedef struct{
    int ad;
    int nap;
}reti;
reti create_record(){
    char fname[FILE_N_LEN];
    printf("Enter a file name: ");
    fflush(stdin);
    fgets(fname, FILE_N_LEN, stdin);
    int len = strlen(fname);
    if (fname[len - 1] == '\n') {
            fname[len - 1] = '\0';
    }
    FILE *fp;
    fflush(stdin);
    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("There is no file with this name.\n");
    }else{
        char line[LINE_LEN];
        fgets(line, LINE_LEN, fp);
         
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        if (strcmp(line,SIGN)!=0){
            printf("This isn't the file that was created by this program\n");
        }else{
            fclose(fp);
            fp = fopen(fname, "a");
            char city[40];
            printf("Enter the city name(not larger than 40 characters): ");
            fgets(city, 40, stdin);
            len = strlen(city);
            if (city[len - 1] == '\n') {
                city[len - 1] = '\0';
            }
            fflush(stdin);
            float area=areac();
            fflush(stdin);
            int population=popul();
            fprintf(fp, "%s, %.2f, %d\n", city, area, population);
        }
    }
    fclose(fp);
    reti r;
    r.ad=0;
    r.nap=0;
}

int startl(int lenf){
    int a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter start line: ");
        y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>lenf) || (a < 1)){
            printf("Start line must be bigger than 0 and smaller than tha last line of file\n");
            printf("File has %d lines\n",lenf);
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
int endl(int lenf, int c){
    int a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Enter end line: ");
        y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a>lenf) || (a < c)){
            printf("End line must be bigger than the start line and smaller than tha last line of file\n");
            printf("File has %d lines\n",lenf);
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
void read_records(){
    fflush(stdin);
    char fname[FILE_N_LEN];
    printf("Enter a file name: ");
    fgets(fname, FILE_N_LEN, stdin);
    int len = strlen(fname);
    if (fname[len - 1] == '\n') {
            fname[len - 1] = '\0';
    }
    FILE *fp;
    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("There is no file with this name.\n");
    }else{

        char line[LINE_LEN];
        fgets(line, LINE_LEN, fp);
         
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        if (strcmp(line,SIGN)!=0){
            printf("This isn't the file that was created by this program\n");
        }else{
            char line[LINE_LEN];
            int lenf = 0;
            while (fgets(line, LINE_LEN, fp) != NULL) {
                lenf++;
            }
            if(lenf==0){
                printf("There are no records in this file\n");
            }else{
                lenf+=1;
                int sl=startl(lenf-1),el=endl(lenf-1,sl);
                int cl = 0;
                rewind(fp);
                printf("\n");
                fgets(line, LINE_LEN, fp);
                while ((fgets(line, LINE_LEN, fp) != NULL)&& (cl+1<=lenf) ) {
                    if (cl+1 >= sl && cl+1 <= el) {
                        printf("%s", line);
                    }
                    if (cl+1 > el) {
                    }
                    cl++;
                }
                
            }

        }
    }
    fclose(fp);
}
void edit_record(){
    City new_record;
    fflush(stdin);
    char fname[FILE_N_LEN];
    printf("Enter a file name: ");
    fgets(fname, FILE_N_LEN, stdin);
    int len = strlen(fname);
    if (fname[len - 1] == '\n') {
        fname[len - 1] = '\0';
    }
    FILE *fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("There is no file with this name\n");
    }else{
        char line[LINE_LEN];
        fgets(line, LINE_LEN, fp);
         
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        if (strcmp(line,SIGN)!=0){
            printf("This isn't the file that was created by this program\n");
        }else{
            char name1[32],rname[32];
            printf("Enter the name of a city you want to change: ");
            fflush(stdin);
            scanf("%[^\n]", name1);
            int len = strlen(name1);
            char line1[LINE_LEN];
            City c1[100];
            float area;
            int population;
            int aw[100];
            int j=0,y=0;
            char name[100];
            while (fgets(line1, 200, fp) != NULL) {
                fflush(stdin);
                if (sscanf(line1, "%[^,], %f, %d", name, &area, &population) == 3) {
                    c1[j].name = strdup(name);
                    c1[j].area = area;
                    c1[j].population = population;
                }
                if (strcmp(c1[j].name, name1) == 0) {
                    aw[y] = j+1;
                    y = y + 1;
                }
                j = j + 1;
            }
            fclose(fp);
            if (y == 0) {
                printf("There are no records with such city name\n");
            } else {
                fflush(stdin);
                City c2;
                printf("Enter a new name of a city: ");
                scanf("%[^\n]", rname);
                c2.name = strdup(rname);
                c2.area=areac();
                c2.population=popul();
                fp = fopen(fname, "r");
                char temp_filename[] = "AAAAAA";
                FILE *temp_fp = fopen(temp_filename, "w");
                char line[300];
                int ne = 0;
                int v=0;
                y=0;
                while (fgets(line, 300, fp) != NULL) {
                    if ((aw[y] != v)) {
                        fputs(line, temp_fp);
                    } else {
                        fprintf(temp_fp, "%s, %.2f, %d\n", c2.name, c2.area, c2.population);
                        ne+=1;
                        y = y + 1;
                    }
                    v+=1;
                }
                fclose(fp);
                fclose(temp_fp);
                remove(fname);
                rename(temp_filename, fname);
                printf("Successfully modified %d records in file %s\n", ne, fname);
            }
        }
    }
}

typedef struct {
    int in;
} index;
index ar[100];
int sort_words(char *words[], int num_words,int vyb) {
    fflush(stdin);
    for (int i=0;i<num_words;i++) ar[i].in=i;
    for (int i = 0; i < num_words - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < num_words; j++) {
            if (vyb==1){
                if (strcmp(words[j], words[min_index]) < 0) {
                    min_index = j;
                }
            }else{
                if (strcmp(words[j], words[min_index]) > 0) {
                    min_index = j;
                }
            }
        }
        if (min_index != i) {
            char *temp = words[i];
            words[i] = words[min_index];
            words[min_index] = temp;
            int tmppp = ar[i].in;
            ar[i].in = ar[min_index].in;
            ar[min_index].in = tmppp;
        }
    }
    return 1;
}
int sort_area(float *array, int size, int ch1) {
    for (int i=0;i<size;i++) ar[i].in=i;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if(ch1==1){
                if (array[j] > array[j + 1]) {
                    float tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                    int tmppp = ar[j].in;
                    ar[j].in = ar[j + 1].in;
                    ar[j + 1].in = tmppp;
                }
            }else{
                if (array[j] < array[j + 1]) {
                    float tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                    int tmppp = ar[j].in;
                    ar[j].in = ar[j + 1].in;
                    ar[j + 1].in = tmppp;
                }
            }
        }
    }
    return 2;
}
int sort_popul(int *array, int size, int ch1) {
    for (int i=0;i<size;i++) ar[i].in=i;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if(ch1==1){
                if (array[j] > array[j + 1]) {
                    int tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                    int tmppp = ar[j].in;
                    ar[j].in = ar[j + 1].in;
                    ar[j + 1].in = tmppp;
                }
            }else{
                if (array[j] < array[j + 1]) {
                    int tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                    int tmppp = ar[j].in;
                    ar[j].in = ar[j + 1].in;
                    ar[j + 1].in = tmppp;
                }
            }
        }
    }
    return 3;
}
// ch1
int choice1(){
    int a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Select the sort order: 1 - ascending, 2 - descending: ");
        y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a<=0) || (a>2)){
            printf("You can choose only 1 or 2\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
int choice2(){
    int a;
    char b=' ';
    int y;
    int v=0;
    do{
        printf("Select the field to sort by: 1 - name of the city, 2 - area, 3 - population: ");
        y=scanf("%d%c",&a,&b);
        if(y!=2 || b!='\n'){
            printf("You entered invalid value, please try again.\n");
            fflush(stdin);
            v=1;
        }else if( (a<=0) || (a>3)){
            printf("You can choose only 1, 2 or 3\n");
            v=1;
        }else{
            v=0;
            return a;
        }
    }while(v==1);
}
reti sort_records(){
    fflush(stdin);
    reti ret;
    ret.ad=0;
    ret.nap=0;
    char fname[FILE_N_LEN];
    printf("Enter a file name: ");
    fgets(fname, FILE_N_LEN, stdin);
    int len = strlen(fname);
    if (fname[len - 1] == '\n') {
        fname[len - 1] = '\0';
    }
    FILE *fp;
    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("There is no file with this name.\n");
    }else{
        char line[LINE_LEN];
        fgets(line, LINE_LEN, fp);
         
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        if (strcmp(line,SIGN)!=0){
            printf("This isn't the file that was created by this program\n");
        }else{         
            City cities[100];
            char line[LINE_LEN];
            int num_cities = 0;
            while (fgets(line, LINE_LEN, fp) != NULL) {
                char name[100];
                float area;
                int population;
                if (sscanf(line, "%127[^,], %f, %d", name, &area, &population) == 3) {
                    cities[num_cities].name = strdup(name);
                    cities[num_cities].area = area;
                    cities[num_cities].population = population;
                    num_cities++;
                }
            }
            char *words[100];
            float areas[100];
            int popul[100];
            int ch1,ch2;
            ch1=choice1();
            ret.ad=ch1;
            ch2=choice2();
            if (ch2==1){
                for (int i = 0; i < num_cities; i++) {
                    words[i]=cities[i].name;
                }
                ret.nap =sort_words(words, num_cities,ch1);
            }else if(ch2==2){
                for (int i = 0; i < num_cities; i++) {
                    areas[i]=cities[i].area;
                }
                ret.nap =sort_area(areas,num_cities,ch1);
            }else if(ch2==3){
                for (int i = 0; i < num_cities; i++) {
                    popul[i]=cities[i].population;
                }
                ret.nap=sort_popul(popul,num_cities,ch1);
            }
            fclose(fp);
            FILE *temp = tmpfile();
            temp = fopen("filename", "w");
            fprintf(temp,"%s\n",SIGN);
            for (int i = 0; i < num_cities; i++) {
                int b=ar[i].in;
                fprintf(temp, "%s, %.2f, %d\n", cities[b].name, cities[b].area, cities[b].population);
            }
            fclose(temp);
            remove(fname);
            rename("filename", fname);
        }
    }
    return ret;
}
void delete_record(){
    char fname[FILE_N_LEN], name1[100];;
    fflush(stdin);
    printf("Enter a file name: ");
    fgets(fname, FILE_N_LEN, stdin);
    int len = strlen(fname);
    if (fname[len - 1] == '\n')
    {
        fname[len - 1] = '\0';
    }
    FILE *fp1;
    fp1 = fopen(fname, "r+");
    if (fp1 == NULL) {
        printf("There is no file with this name.\n");
        return;
    }
    fclose(fp1);
    
    FILE *fp = fopen(fname, "r");
    char line[LINE_LEN];
        fgets(line, LINE_LEN, fp);
         
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        if (strcmp(line,SIGN)!=0){
            printf("This isn't the file that was created by this program\n");
        }else{
            
            printf("Enter the name of the city to be deleted: ");
            scanf("%[^\n]", name1);    
            if (fp == NULL){
                printf("There is no file with this name\n");
            }else{
                
                char temp_filename[] = "temp.txt";
                FILE *temp_fp = fopen(temp_filename, "w");
                char line[LINE_LEN];
                int nd = 0;
                City c[100];
                int i=0;
                fprintf(temp_fp,"%s\n",SIGN);
                while (fgets(line, LINE_LEN, fp) != NULL){
                    char name[100];
                    float area;
                    int population;
                    if (sscanf(line, "%127[^,], %f, %d", name, &area, &population) == 3) {
                        c[i].name = strdup(name);
                        c[i].area = area;
                        c[i].population = population;
                        
                    }
                    if (strcmp(c[i].name, name1) != 0)
                    {
                        fputs(line, temp_fp);
                    }
                    else
                    {
                        nd++;
                    }
                    i++;
                }
                fclose(fp);
                fclose(temp_fp);
                remove(fname);
                rename(temp_filename, fname);
                printf("Successfully deleted %d of records from file %s\n", nd, fname);
            }
        }
}

void insert_record(reti ret){
    char fname[FILE_N_LEN];
    fflush(stdin);
    printf("Enter a file name: ");
    fgets(fname, FILE_N_LEN, stdin);
    int len = strlen(fname);
    if (fname[len - 1] == '\n')
    {
        fname[len - 1] = '\0';
    }
    FILE *fp1;
    fp1 = fopen(fname, "r");
    if (fp1 == NULL) {
        printf("There is no file with this name.\n");
    }else{
        char line[LINE_LEN];
        fgets(line, LINE_LEN, fp1);
         
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        if (strcmp(line,SIGN)!=0){
            printf("This isn't the file that was created by this program\n");
        }else{
            if ( ((ret.ad>0)&&(ret.ad<3)) && ((ret.nap>0)&&(ret.nap<4))  ){
                fclose(fp1);
                char name1[100];
                float area1;
                int pop;
                printf("Enter the name of the city to be inserted: ");
                scanf("%[^\n]", name1);
                area1=areac();
                pop=popul();
                char line[LINE_LEN];
                int i=0;
                FILE *fp;
                fp = fopen(fname, "r");
                City cities1[100];
                fgets(line, LINE_LEN, fp);
                while (fgets(line, LINE_LEN, fp) != NULL){
                    char name[100];
                    float area;
                    int population;
                    if ((sscanf(line, "%127[^,], %f, %d", name, &area, &population) == 3) ) {
                        cities1[i].name = strdup(name);
                        cities1[i].area = area;
                        cities1[i].population = population;
                        i++;
                    }
                }
                fclose(fp);
                FILE *fp2 = fopen(fname, "r");
                char temp_filename[] = "tempppppp";
                FILE *temp_fp = fopen(temp_filename, "w");
                fprintf(temp_fp,"%s\n",SIGN);
                int j=0;
                fgets(line, LINE_LEN, fp2);
                while (j<i){
                    if ((ret.nap==1) && (ret.ad==1)){
                        if ((j==i-1) &&(strcmp(cities1[j].name,name1)<0)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else if ((j==0) &&(strcmp(cities1[j].name,name1)>0) ){
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }else if ((strcmp(cities1[j].name,name1)<0) && (strcmp(cities1[j+1].name,name1)>0) && (j!=i-1) && (j!=0)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else{
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }
                        j+=1;
                    }else if ((ret.nap==1) && (ret.ad==2)){
                        if ((j==i-1) &&(strcmp(cities1[j].name,name1)>0)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else if ((j==0) &&(strcmp(cities1[j].name,name1)<0)){
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }else if ((strcmp(cities1[j].name,name1)>0) && (strcmp(cities1[j+1].name,name1)<0) && (j!=i-1) && (j!=0)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else{
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }
                        j+=1;
                    }else if ((ret.nap==2) && (ret.ad==1)){
                        if ((j==i-1) &&(cities1[j].area<area1)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else if ((j==0) &&(cities1[j].area>area1)){
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }else if ((cities1[j].area<area1) && (cities1[j+1].area>area1) && (j!=i-1) && (j!=0)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else{
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }
                        j+=1;
                    }else if ((ret.nap==2) && (ret.ad==2)){
                        if ((j==i-1) &&(cities1[j].area>area1)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else if ((j==0) &&(cities1[j].area<area1) ){
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }else if ((cities1[j].area>area1) && (cities1[j+1].area<area1) && (j!=i-1) && (j!=0)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else{
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }
                        j+=1;
                    }else if ((ret.nap==3) && (ret.ad==1)){
                        if ((j==i-1) &&(cities1[j].population<pop)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else if ((j==0) &&(cities1[j].population>pop)){
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }else if ((cities1[j].population<pop) && (cities1[j+1].population>pop) && (j!=i-1) && (j!=0)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else{
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }
                        j+=1;
                    }else if ((ret.nap==3) && (ret.ad==2)){
                        if ((j==i-1) &&(cities1[j].population>pop)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else if ((j==0) &&(cities1[j].population<pop) ){
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }else if ((cities1[j].population>pop) && (cities1[j+1].population<pop) && (j!=i-1) && (j!=0)){
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                            fprintf(temp_fp, "%s, %.2f, %d\n", name1, area1, pop);
                        }else{
                            fgets(line, LINE_LEN, fp2);
                            fputs(line, temp_fp);
                        }
                        j+=1;
                    }
                }
                fclose(fp);
                fclose(temp_fp);
                remove(fname);
                rename(temp_filename, fname);
            }else{
                printf("The data wasn't sorted previously, so new info will be inserted in the end\n");
                FILE *fp;
                fp = fopen(fname, "a");
                char city[40];
                printf("Enter the city name: ");
                fgets(city, 40, stdin);
                len = strlen(city);
                if (city[len - 1] == '\n') {
                    city[len - 1] = '\0';
                }
                fflush(stdin);
                float area=areac();
                fflush(stdin);
                int population=popul();
                fprintf(fp, "%s, %.2f, %d\n", city, area, population);
                fclose(fp);
            }
        }
    }
}

int main(){
    fflush(stdin);
    int x=1,y;
    reti ret;
    ret.ad=0;
    ret.nap=0;
    while (x==1)
    {   
        int choice1, choice2, choice3;
        printf("\nMenu:\n");
        printf("1. Work with files\n");
        printf("2. Work with records\n");
        printf("3. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice1);
        switch (choice1)
        {
        case 1:
            y=1;
            while(y==1){
                printf("\nWork with files:\n");
                printf("1. Create a new file\n");
                printf("2. Read the file\n");
                printf("3. Delete the file\n");
                printf("4. Return to previous page\n");
                printf("5. Quit\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    create_file();
                    choice2=6;
                    break;
                case 2:
                    read_file();
                    choice2=6;
                    break;
                case 3:
                    delete_file();
                    choice2=6;
                    break;
                case 4:
                    y=0;
                    choice2=6;
                    break;
                case 5:
                    x=0;
                    y=0;
                    break;
                default:
                    printf("Invalid choice\n");
                    fflush(stdin);
                    break;
                }
            }
            choice1=4;
            break;
        case 2:
            y=1;
            while(y==1){
                printf("\nWork with records:\n");
                printf("1. Create a new record\n");
                printf("2. Read records\n");
                printf("3. Edit records\n");
                printf("4. Organize records\n");
                printf("5. Insert records\n");
                printf("6. Delete records\n");
                printf("7. Return to previous page\n");
                printf("8. Quit\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice3);
                switch (choice3)
                {
                case 1:
                    ret=create_record();
                    choice3=9;
                    break;
                case 2:
                    read_records();
                    choice3=9;
                    break;
                case 3:
                    edit_record();
                    choice3=9;
                    break;
                case 4:
                    ret = sort_records();
                    choice3=9;
                    break;
                case 5:
                    insert_record(ret);
                    choice3=9;
                    break;
                case 6:
                    delete_record();
                    choice3=9;
                    break;
                case 7:
                    y=0;
                    choice3=9;
                    break;
                case 8:
                    x=0;
                    y=0;
                    break;
                default:
                    printf("Invalid choice\n");
                    fflush(stdin);
                    break;
                }
            }
            choice1=4;
            break;
        case 3:
            x=0;
            break;
        default:
            printf("Invalid choice.\n");
            fflush(stdin);
            break;
        }
    }
    return 0;
}