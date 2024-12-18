#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int roll;
    float marks[8];
    char fname[25], lname[25];
}info;

char subject[9][9], grade[9][3], y_sem[7];

int tcredit, credit[9], sub_no;

void sem1(), sem2(), sem3(), sem4(), sem5(), sem6(), sem7(), sem8();
float gvalue(float, int);

int main()
{
    info s;
    FILE *fp, *fpr, *fp_temp, *fpa;
    int i, n, sem, wrong, wrong2, choice, r, ans;
    float gval[8], gpoint[8], tgpoint, gpa;
    char path[200];
    
    //INPUT SEMESTER
    start:
    system("color 8f");
    do{
        system("cls");
        
        printf("\n\n\n\t<<<<<<<<<<<<<   KATHMANDU UNIVERSITY GPA PORTAL   >>>>>>>>>>>>>\n");
        printf("\t\t\t\t\t\t\tCreated by:\n");
        printf("\t\t\t\t\t\t\tShubin Pokhrel\n");
        printf("\t\t\t\t\t\t\tShashwat Khadka\n");
        printf("\t\t\t\t\t\t\tSiddhartha Pradhan\n");
        printf("\t\t\t\t\t\t\tBinaya Raj Thapa\n\n\n");
        
        wrong = 0;
        printf("\tEnter your semester: ");
        scanf("%d", &sem);

        //ASSIGN SUBJECT AND CREDIT
        if(sem == 1) {sub_no = 8; strcpy(path, "sem1.txt"); sem1();}
        else if(sem == 2) {sub_no = 8; strcpy(path, "sem2.txt"); sem2();}
        else if(sem == 3) {sub_no = 7; strcpy(path, "sem3.txt"); sem3();}
        else if(sem == 4) {sub_no = 6; strcpy(path, "sem4.txt"); sem4();}
        else if(sem == 5) {sub_no = 7; strcpy(path, "sem5.txt"); sem5();}
        else if(sem == 6) {sub_no = 7; strcpy(path, "sem6.txt"); sem6();}
        else if(sem == 7) {sub_no = 5; strcpy(path, "sem7.txt"); sem7();}
        else if(sem == 8) {sub_no = 3; strcpy(path, "sem8.txt"); sem8();}
        else {printf("\n\tInvalid Semester\n\n\t"); wrong = 1; system("pause");}
    }while(wrong == 1);
    
    //CREATE FILE IF DOESN'T EXIST
    fp = fopen(path, "ab");
    fclose(fp);
    
    do{
        system("cls");
        printf("\n\n\n\t<<<<<<<<<<<<<   KATHMANDU UNIVERSITY GPA PORTAL   >>>>>>>>>>>>>\n");
        printf("\t\t\t\t\t\t\tCreated by:\n");
        printf("\t\t\t\t\t\t\tShubin Pokhrel\n");
        printf("\t\t\t\t\t\t\tShashwat Khadka\n");
        printf("\t\t\t\t\t\t\tSiddhartha Pradhan\n");
        printf("\t\t\t\t\t\t\tBinaya Raj Thapa\n\n\n");
        wrong2 == 0;
        printf("\t1. View Report Card\t");
        printf("2. Add Marks\t");
        printf("3. View All\t");
        printf("4. Exit\n\n");
        printf("\tChoice: ");
        scanf("%d", &choice);
    
        if(choice == 2){
            system("cls");
            printf("\n\n\n\t<<<<<<<<<<<<<   KATHMANDU UNIVERSITY GPA PORTAL   >>>>>>>>>>>>>\n");
            printf("\t\t\t\t\t\t\tCreated by:\n");
            printf("\t\t\t\t\t\t\tShubin Pokhrel\n");
            printf("\t\t\t\t\t\t\tShashwat Khadka\n");
            printf("\t\t\t\t\t\t\tSiddhartha Pradhan\n");
            printf("\t\t\t\t\t\t\tBinaya Raj Thapa\n\n\n");
        
            fflush(stdin);
            printf("\n\tRoll Number: ");
            scanf("%d", &r);
            
            //CHECK IF ROLL IS REPEATED, IF SO DELETE THE PREVIOUS RECORD
            fp = fopen(path, "rb");
            fp_temp = fopen("temp.txt", "wb");

            while (fread(&s,sizeof(s),1,fp)) {
		        if (s.roll != r){
                    fwrite(&s, sizeof(s), 1, fp_temp);
                }
            }
            fflush(fp);
            fflush(fp_temp);
            fclose(fp);
            fclose(fp_temp);
            remove(path);
            rename("temp.txt", path);
            
            s.roll = r;
            //USER INPUT
            fp = fopen(path,"ab");
            fflush(stdin);
            printf("\n\n\tFirst Name: ");
            scanf("%s", &s.fname);
            fflush(stdin);
            printf("\n\tLast Name: ");
            scanf("%s", &s.lname);
            fflush(stdin);
            for(i=0;i<sub_no;i++){
                do{
                    wrong = 0;
                    printf("\n\tMarks of %s: ",subject[i]);
                    scanf("%f",&s.marks[i]);
                    if(s.marks[i]<0 || s.marks[i]>100){printf("\n\tInvalid marks, Re-enter\n\t"); system("pause"); printf("\n"); wrong = 1;}
                }while(wrong == 1);
            }
            
            fwrite(&s,sizeof(s),1,fp);
            fclose(fp);
            printf("\n\t");
            system("pause");
            goto start;
        }
    
        else if (choice == 1){
            search:
            system("color b");
            system("cls");
            printf("\n\n\n\t<<<<<<<<<<<<<   KATHMANDU UNIVERSITY GPA PORTAL   >>>>>>>>>>>>>\n");
            printf("\t\t\t\t\t\t\tCreated by:\n");
            printf("\t\t\t\t\t\t\tShubin Pokhrel\n");
            printf("\t\t\t\t\t\t\tShashwat Khadka\n");
            printf("\t\t\t\t\t\t\tSiddhartha Pradhan\n");
            printf("\t\t\t\t\t\t\tBinaya Raj Thapa\n\n\n");
            
            printf("\n\tRoll Number: ");
            scanf("%d", &r);

            fpr=fopen(path,"rb");
    
    
            while(fread(&s,sizeof(s),1,fpr)==1){

                if(s.roll==r){
    
                    //ASSIGN GRADE VALUE, GRADE AND GRADE POINT

                    tgpoint = 0;
                    for(i = 0; i < sub_no; i++){
                        gval[i] = gvalue(s.marks[i], i);
                        gpoint[i] = gval[i]*credit[i];
                        tgpoint += gpoint[i];
                    }
                    gpa = tgpoint/tcredit;
    
                    system("cls");
                    //REPORT CARD
                    system("color b");
                    printf("\n\t-----------------------------------------------------------------------------------------------\n");
                    printf("\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                    printf("\t-----------------------------------------------------------------------------------------------\n\n");
                    printf("\t                                KATHMANDU  UNIVERSITY\n\n");
                    printf("\t                                  SCHOOL OF SCIENCE\n\n");
                    printf("\t-----------------------------------------------------------------------------------------------\n\n");
                    printf("\tProgram:\t\tCOMPUTER SCIENCE\n");
                    printf("\tName of the Student:\t");
                    //NAME TO UPPERCASE
                    int j = 0;
                    char ch;
                    while (s.lname[j]) {
                        ch = s.lname[j];
                        putchar(toupper(ch));
                        j++;
                    }
                    printf(" ");
                    j = 0;
                    while (s.fname[j]) {
                        ch = s.fname[j];
                        putchar(toupper(ch));
                        j++;
                    }
                    printf("\n");
                    printf("\tRoll Number:\t\t%d\n\n", s.roll);
                    printf("\t-----------------------------------------------------------------------------------------------\n");
                    printf("\tYEAR/SEMESTER:\t%s\n", y_sem);
                    printf("\t-----------------------------------------------------------------------------------------------\n\n");
                    printf("\tCOURSE\t\t\tCREDIT\t\tGRADE\t\tGRADE VALUE\t\tGRADE POINTS\n");
                    for(i=0;i<sub_no;i++){
                        printf("\t%s\t\t  %d\t\t  %c%c\t\t   %.2f\t\t\t    %.2f\n",subject[i],credit[i],grade[i][0],grade[i][1],gval[i],gpoint[i]);    
                    }
                    printf("\n\t-----------------------------------------------------------------------------------------------\n\n");
                    printf("\tGPA: %.2f\n\n",gpa);
                    printf("\t-----------------------------------------------------------------------------------------------\n");
                    printf("\txxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                    printf("\t-----------------------------------------------------------------------------------------------\n\t");
                    system("pause");
                    fclose(fpr);
                    goto start;
                }
            }
            system("color 04");
            printf("\n\tDATA NOT AVAILABLE!!\n\n\t");
            system("pause");
            goto search;
        }
    
        else if(choice==3){
            system("cls");
            fpa=fopen(path,"rb");
            while(fread(&s,sizeof(s),1,fpa)==1){ 
                printf("Roll:%d\n",s.roll);
                printf("%s %s\n",s.fname,s.lname);
                for(i=0;i<6;i++){
                    printf("%s:%.2f\n",subject[i],s.marks[i]);
                }
            printf("\n\n");    
            }
            fclose(fp);
            system("pause");
            goto start;   
        }

        else if(choice==4){
            system("color 02");
            system("cls");
            printf("MAIN MENU[1]\n");
            printf("Enter any other chracter to exit\n\n");
            scanf("%d", &ans);

            if (ans == 1) goto start;
            else exit(0);
        }
        
        else {
            printf("\n\tInvalid choice, Re-enter\n\n\t");
            system("pause");
            printf("\n");
            wrong2 = 1;
        }
    
    }while(wrong2 == 1);

    


    return 0;
}

void sem1()
{
    strcpy(y_sem, "I/I");
    int i, n;
    strcpy(subject[0], "MATH 101");
    strcpy(subject[1], "PHYS 101");
    strcpy(subject[2], "ENGT 101");
    strcpy(subject[3], "COMP 102");
    strcpy(subject[4], "ENGG 111");
    strcpy(subject[5], "CHEM 101");
    strcpy(subject[6], "EDRG 101");
    strcpy(subject[7], "ENGG 101");
    tcredit = 0;
    for (i = 0, n = 3; i < sub_no; i++){
        if (i == 6) n--;
        credit[i] = n;
        tcredit+=credit[i];
    }
}

void sem2()
{
    strcpy(y_sem, "I/II");
    int i, n;
    strcpy(subject[0], "MATH 104");
    strcpy(subject[1], "PHYS 102");
    strcpy(subject[2], "COMP 116");
    strcpy(subject[3], "ENGG 112");
    strcpy(subject[4], "ENGT 102");
    strcpy(subject[5], "ENVE 101");
    strcpy(subject[6], "EDRG 102");
    strcpy(subject[7], "ENGG 102");
    tcredit = 0;
    for (i = 0, n = 3; i < sub_no; i++){
        if (i == 4) n--;
        credit[i] = n;
        tcredit+=credit[i];
    }
}

void sem3()
{
    strcpy(y_sem, "II/I");
    int i, n;
    strcpy(subject[0], "MATH 208");
    strcpy(subject[1], "MCSC 201");
    strcpy(subject[2], "EEEG 202");
    strcpy(subject[3], "EEEG 211");
    strcpy(subject[4], "COMP 202");
    strcpy(subject[5], "COMP 206");
    strcpy(subject[6], "COMP 208");
    tcredit = 0;
    for (i = 0, n = 3; i < sub_no; i++){
        if (i == 5 || i == 6) n--;
        credit[i] = n;
        tcredit+=credit[i];
    }
}

void sem4()
{
    strcpy(y_sem, "II/II");
    int i, n;
    strcpy(subject[0], "MATH 207");
    strcpy(subject[1], "MCSC 202");
    strcpy(subject[2], "COMP 204");
    strcpy(subject[3], "COMP 231");
    strcpy(subject[4], "COMP 232");
    strcpy(subject[5], "COMP 207");
    tcredit = 0;
    for (i = 0, n = 4; i < sub_no; i++){
        if (i == 1 || i == 5) n--;
        credit[i] = n;
        tcredit+=credit[i];
    }
}

void sem5()
{
    strcpy(y_sem, "III/I");
    int i, n;
    strcpy(subject[0], "COMP 317");
    strcpy(subject[1], "MGTS 301");
    strcpy(subject[2], "COMP 307");
    strcpy(subject[3], "COMP 315");
    strcpy(subject[4], "COMP 316");
    strcpy(subject[5], "COMP 342");
    strcpy(subject[6], "COMP 311");
    tcredit = 0;
    for (i = 0, n = 4; i < sub_no; i++){
        if (i == 1) n--;
        if (i == 6) n=n-2;
        credit[i] = n;
        tcredit+=credit[i];
    }
}

void sem6()
{
    strcpy(y_sem, "III/II");
    int i, n;
    strcpy(subject[0], "MATH 332");
    strcpy(subject[1], "COMP 302");
    strcpy(subject[2], "COMP 409");
    strcpy(subject[3], "COMP 314");
    strcpy(subject[4], "COMP 323");
    strcpy(subject[5], "COMP 341");
    strcpy(subject[6], "COMP 313");
    tcredit = 0;
    for (i = 0, n = 3; i < sub_no; i++){
        if (i == 6) n--;
        credit[i] = n;
        tcredit+=credit[i];
    }
}

void sem7()
{
    strcpy(y_sem, "IV/I");
    int i, n;
    strcpy(subject[0], "MGTS 403");
    strcpy(subject[1], "COMP 401");
    strcpy(subject[2], "COMP 472");
    strcpy(subject[3], "ELECT 01");
    strcpy(subject[4], "ELECT 02");
    tcredit = 0;
    for (i = 0, n = 3; i < sub_no; i++){
        credit[i] = n;
        tcredit+=credit[i];
    }
}

void sem8()
{
    strcpy(y_sem, "IV/II");
    int i, n;
    strcpy(subject[0], "COMP 408");
    strcpy(subject[1], "MGTS 402");
    strcpy(subject[2], "COMP 486");
    tcredit = 0;
    for (i = 0, n = 6; i < sub_no; i++){
        if (i == 1) n = 3;
        credit[i] = n;
        tcredit+=credit[i];
    }
}

float gvalue(float m, int i)
{
    float gv;
        
    if (m>=80 && m<=100){
        gv = 4.00;
        strcpy(grade[i], "A");
    }
        
    else if (m>=75 && m<80){
        gv = 3.70;
        strcpy(grade[i], "A-");
    }
        
    else if (m>=70 && m<75){
        gv = 3.30;
        strcpy(grade[i], "B+");
    }
        
    else if (m>=65 && m<70){
        gv = 3.00;
        strcpy(grade[i], "B");
    }
        
    else if (m>=60 && m<65){
        gv = 2.70;
        strcpy(grade[i], "B-");
    }
        
    else if (m>=55 && m<60){
        gv = 2.30;
        strcpy(grade[i], "C+");
    }
        
    else if (m>=50 && m<55){
        gv = 2.00;
        strcpy(grade[i], "C");
    }

    else if (m>=45 && m<50){
        gv = 1.70;
        strcpy(grade[i], "C-");
    }

    else if (m>=40 && m<45){
        gv = 1.00;
        strcpy(grade[i], "D");
    }

    else if (m>=0 && m<40){
        gv = 0.00;
        strcpy(grade[i], "F");
    }
    
    return  gv;  
}