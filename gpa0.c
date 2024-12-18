#include <stdio.h>
#include <string.h>
#include <time.h>
void gpa(float[],int,char[][25]);
float numbergradefromlettergrade(char letter[]);

void main(){
    int i;
    float marks[8];

    char subject[][25]={"MATH101","PHY101(T)","PHY101(P)","CHEM101","ENGG101","EDRG101","COMP102","ENGG111"};
    
    for(i=0;i<8;i++){
        printf("Marks of %s:",subject[i]);
        scanf("%f",&marks[i]);
    }
    
    gpa(marks,8,subject);
}

void gpa(float m[],int a,char subject[8][25]){
	
    int j,k,credit,rollno;
    float sum=0,totalgpa=0,sgpa=0;
    char g[2],firstname[15],lastname[15];
    printf("\n Name   :   ");
    scanf("%s",&firstname);
    printf("LastName  :  ");
    scanf("%s",&lastname);
    printf("Roll Number    :   ");
    scanf("%d",&rollno);

        printf("\n\n");

    printf("BSc. Computer Science\n");
    printf("%s %s\n",lastname,firstname);
    printf("Roll Number=%d\n",rollno);
    time_t t;   
    time(&t);

    printf("%s",ctime(&t));

    printf("                         KATHMANDU UNIVERSITY\n");
    printf("----------------------------------------------------------------------\n");

    printf("  SUBJECTS             CREDIT               GPA               GRADE \n");
    
    printf("----------------------------------------------------------------------\n");
    
    for (j=0;j<a;j++){
    if(j==0 || j==3 || j==6 ){
        credit=3;
        if (m[j]>=90){
        	
           strcpy(g,"A");
        }
        else if (m[j]>=80){
        
        strcpy(g,"A-");
        }
        else if (m[j]>=75){
        
        strcpy(g,"B+");
        }
        else if (m[j]>=70){
        
        strcpy(g,"B");
        }
        else if (m[j]>=65){
        
        strcpy(g,"B-");
        }
        else if (m[j]>=55){
        
        strcpy(g,"C+");
        }
        else if (m[j]>=50){
        
        strcpy(g,"C");
        }
        else if (m[j]>=0){
        
        strcpy(g,"F");
        }

        sum=sum+sgpa*credit;
        sgpa=numbergradefromlettergrade(g);
        //printf("%f",sgpa);

    }
        else if(j==1|| j==4 || j==5|| j==7){
            credit=2;
        //physics theory
        if (m[j]>=90){
           // credit=2;
        
        strcpy(g,"A");
        }
        else if (m[j]>=80){
        
        strcpy(g,"A-");
        }
        else if (m[j]>=75){
        
        strcpy(g,"B+");
        }
        else if (m[j]>=70){
        
        strcpy(g,"B");
        }
        else if (m[j]>=65){
        
        strcpy(g,"B-");
        }
        else if (m[j]>=55){
        
        strcpy(g,"C+");
        }
        else if (m[j]>=50){
        
        strcpy(g,"C");
        }
        else if (m[j]>=0){
        
        strcpy(g,"F");
        }
        sgpa=numbergradefromlettergrade(g);
        sum=sum+sgpa*credit;
    }
        else if(j==2){
           credit=1;
                //practical practical
        if (m[j]>=17.5){
        m[j]=4;
        strcpy(g,"A");
        }
        else if (m[j]>=15){
        m[j]=3;
        strcpy(g,"B-");
        }
        else if (m[j]>=12.5){
        m[j]=2;
        strcpy(g,"B");
        }
        else if (m[j]>=10){
        m[j]=1;
        strcpy(g,"C");
        }
        else if (m[j]>=0){
        m[j]=0;
        strcpy(g,"F");
        }
        sum=sum+sgpa*credit;
        }
        sgpa=numbergradefromlettergrade(g);
        printf("%10s              %d                  %.2f                %s\n",subject[j],credit,sgpa,g);  
      

     totalgpa=totalgpa+sgpa;
    }
    
    float finalgpa;
    int totalcredit=17;
    printf("\nTotal Credits=%d\t\tTotal GPA=%.2f\n",totalcredit,totalgpa);  
    printf("Summation of GPAxCredit=%.2f\n",sum);  
    finalgpa=sum/totalcredit;
    printf("GPA=%.2f",finalgpa);
    
}

float numbergradefromlettergrade(char letter[]){
	if(strcmp(letter,"A")==0)
		return 4.0;
	else if(strcmp(letter,"A-")==0)
		return 3.7;
	else if(strcmp(letter,"B+")==0)
		return 3.3;
	else if(strcmp(letter,"B")==0)
		return 3.0;
	else if(strcmp(letter,"B-")==0)
		return 2.7;
	else if(strcmp(letter,"C+")==0)
		return 2.3;
	else if(strcmp(letter,"C")==0)
		return 2.0;
	else if(strcmp(letter,"F")==0)
		return 0;
}
