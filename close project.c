#include <stdio.h>
#include<conio.h>

#include<process.h>
#include <stdlib.h>
#include <string.h>

void input();
void input_result();

void admin();
void student();

void display();
void display_result();

void search();
void search_by_roll();
void search_by_name();
void search_by_name_result();
void search_by_rl_result();
void check_highest_lowest();


void show_avarge_mark();
void check_higest();
void check_data_structure_pass_fail();
void check_statistics_pass_fail();
void check_math_pass_fail();
void check_project_pass_fail();

void modify();
void modify_student();
void modify_student_result();
struct student
{
    char name[10];
    int password[10];
    char na[30];
    char cl[10];
    int ID;
    int d_marks,s_marks,m_marks,p_marks;
    float per;
    char grade;
    int std;

} s;
long si=sizeof(s);
FILE *fp;
FILE *fp1;
FILE *fr1;
FILE *fr2;







void main()
{
    system("cls");
    system("color B");

    int choice;


    printf("\n\n\t\t\t\t*************************************************\n");
    printf("\t\t\t\t\t\t  WELCOME");
    printf("\n  \t\t\t\t\t            TO");
    printf("\n\t\t\t\t\t  VARSITY MANAEGMENT SYSTEM");
    printf("\t\t\t\t*************************************************");

    printf("\n\n\n\t\t\t\t\t1.Administrator Login");
    printf("\n\t\t\t\t\t2.Student Login");
    printf("\n\n\t\t\t\t\tPlease enter your choice: ");
    scanf("%d",&choice);




    switch(choice)
    {

    case 0:
        exit(0);
    case 1:

        admin();
        break;

    case 2:

        student();

        break;
    default:
        printf("errors");
    }
    return 0;

}




void admin()
{
    system("color A");
    system("cls");

    int ch,i;
    char password[10],name[10];
    fr1=fopen("Administrator.txt","w");
    if(fr1==NULL)
    {
        printf("File does not exists\n");
        return 0;
    }
    printf("\t\t\t\t\t****For Administrator****\n");
    printf("\n\t\t\t\t\tPlease enter your name:");
    scanf ("%s",&name);
    printf("\n\t\t\t\t\tPlease enter your password:");
    for(i=0; i<8; i++)
    {
        password[i]=getch();
        printf("*");
    }
    password[i]='\0';
    fwrite(&s, sizeof(s),1,fr1);


    if(strcmp(name,"joy")==0 && strcmp(password,"majumder")==0)

    {
        printf("\n\n\t\t\t\t\t***Admin Login succesfully***");
        while(1)
        {
            printf("\n\n\t\t\t\t\t1.Student input and editing ");
            printf("\n\t\t\t\t\t2.Student result input and editing ");
            printf("\n\t\t\t\t\t3.Display Student information");
            printf("\n\t\t\t\t\t4.Display Student information and result");
            printf("\n\t\t\t\t\t5.Search");
            printf("\n\t\t\t\t\t6.Modify");

            printf("\n\t\t\t\t\t7.Check");

            printf("\n\t\t\t\t\t8.Back To Main Menu");
            fwrite(&s, sizeof(s),1,fr1);


            printf("\n\n     Please enter your choice:");
            scanf("%d",&ch);

            switch (ch)
            {
            case 0:
                exit (0);
            case 1:

                input();

                break;
            case 2:
                input_result();
                break;
            case 3:
                display();
                break;
            case 4:
                display_result();
                break;
            case 5:
                search();
                break;
            case 6:
                modify();
                break;
            case 7:
                check_highest_lowest();
                break;



            case 8:
                system("cls");
                main();
                break;
            default:
                printf("errors");
            }


        }







    }

    else
    {
        printf("Check your name or password");

    }


fclose(fr1);

}
void student()
{
    system("cls");

    char name[20],password[10],ch='*';
    int i,choice;
    fr2=fopen("student.txt","w");
    if(fr2==NULL)
    {
        printf("File does not exists\n");
        return 0;
    }



    printf("\t\t\t\t\t  ****For Student****\n");
    printf("\n\t\t\t\t\tPlease enter your name:");
    scanf ("%s",&name);
    printf("\n\t\t\t\t\tPlease enter your password:");
    for(i=0; i<3; i++)
    {
        password[i]=getch();
        printf("*");
    }
    password[i]='\0';

    if(strcmp(name,"rohim")==0 && strcmp(password,"ddd")==0)

    {
        printf("\n\t\t\t\t\t***Student Login succesfully***");
        while(1)
        {


            printf("\n\n\t\t\t\t\t1.Enter your Information");
            printf("\n\t\t\t\t\t2.View My Information");

            printf("\n\t\t\t\t\t3.View My Result");
            printf("\n\t\t\t\t\t4.Back to main menu");
            {
                printf("\n\n     Please enter your choice:");
                scanf("%d",&choice);

                switch (choice)
                {
                case 0:
                    exit (0);
                case 1:
                    input();

                    break;
                case 2:
                    search_by_name();
                    break;
                case 3:
                    search_by_name_result();
                    break;
                case 4:

                    main();
                    break;
                default:
                    printf("errors");
                }
            }
        }
    }
    else
    {
        printf("Check your name or password");

    }
}
void input()
{
    system("cls");
    fp = fopen("st.txt","ab");
    printf("Enter Student Name: ");
    fflush(stdin);
    gets(s.na);
    printf("Enter Class: ");
    scanf("%s",&s.cl);
    printf("Enter ID: ");
    scanf("%d",&s.ID);


    fwrite(&s, sizeof(s),1,fp);
    printf("Record Saved Successfully");
    fclose(fp);

}
void input_result()
{
    system("cls");
    fp1 = fopen("str.txt","ab");
    printf("Enter Student Name: ");
    fflush(stdin);
    gets(s.na);
    printf("Enter Class: ");
    scanf("%s",&s.cl);
    printf("Enter ID: ");
    scanf("%d",&s.ID);
    printf("\nEnter The marks in Data structure out of 100 : ");
    scanf("%d",&s.d_marks);
    printf("\nEnter The marks in Statistic out of 100 : ");
    scanf("%d",&s.s_marks);
    printf("\nEnter The marks in maths out of 100 : ");
    scanf("%d",&s.m_marks);
    printf("\nEnter The marks in project out of 100 : ");
    scanf("%d",&s.p_marks);

    s.per=(s.d_marks+s.s_marks+s.m_marks+s.p_marks)/4.0;
    if(s.per>=60)
        s.grade='A';
    else if(s.per>=50 &&s.per<60)
        s.grade='B';
    else if(s.per>=33 &&s.per<50)
        s.grade='C';
    else
        s.grade='F';







    fwrite(&s, sizeof(s),1,fp1);
    printf("Record Saved Successfully");
    fclose(fp1);
}
void display()
{
    system("cls");
    printf("<== Student Info ==>\n\n");
    printf("%-30s %-20s %-10s %s\n","Name","Class","ID");
    fp = fopen("st.txt","rb");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("%-30s %-20s %-10d %s\n",s.na,s.cl,s.ID);
    }
    fclose(fp);
    printf("Press any key to continue...");
}



void display_result()
{
    system("cls");

    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fp1=fopen("str.txt","rb");
    while((fread(&s,sizeof(s),1,fp1))>0)
    {

        printf("\nName of student : %s",s.na);
        printf("\nName of class : %s",s.cl);
        printf("\nNumber of id : %d",s.ID);
        printf("\n\nMarks in Data sturcture : %d",s.d_marks);
        printf("\nMarks in Statistics : %d",s.s_marks);
        printf("\nMarks in Math : %d",s.m_marks);
        printf("\nMarks in Project : %d",s.p_marks);

        printf("\nPercentage of student is  : %.2f",s.per);
        printf("\nGrade of student is : %c",s.grade);
        printf("\n\n====================================\n");

        printf("Press any key to continue...");

        getch();




    }


    fclose(fp1);

}





void search()
{
    system("cls");
    int ch;

    while(1)
    {

        printf("<== Varsity Management ==>\n");
        printf("<== Search ==>\n\n");
        printf("1.Search By Roll\n");
        printf("2.Search By Name\n");
        printf("3.Search By Name Result\n");
        printf("4 .Search By Roll Result\n");
        printf("5.Back To Admin menu\n");
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            search_by_roll();
            break;

        case 2:
            search_by_name();
            break;
        case 3:
            search_by_name_result();
            break;
        case 4:
            search_by_rl_result();
            break;
        case 5:
            system("cls");
            admin();
            break;


        default:
            printf("Invalid Choice");

        }
        getch();
    }
}

void search_by_roll()
{
    system("cls");

    int ID,f=0;
    printf("Enter Roll to search: ");
    scanf("%d",&ID);
    printf("%-30s %-20s %-10s %s\n","Name","Class","ID");
    fp=fopen("st.txt","rb");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(ID == s.ID)
        {
            f=1;
            printf("%-30s %-20s %-10d %s\n",s.na,s.cl,s.ID);
            printf("Record Found Successfully...\n");
            printf("Press any key to continue...\n\n");
            break;
        }
    }
    fclose(fp);
    if(f==0)
        printf("Record Not Found...\n");



}

void search_by_name()

{
    system("cls");
    char na[30];
    int f=0;
    printf("Enter Name to search: ");
    fflush(stdin);
    gets(na);
    printf("%-30s %-20s %-10s %s\n","Name","Class","ID");
    fp=fopen("st.txt","rb");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(strcmpi(na,s.na)==0)
        {
            f=1;
            printf("%-30s %-20s %-10d %s\n",s.na,s.cl,s.ID);
            printf("Record Found Successfully...\n");
            printf("Press any key to continue...\n\n");
            break;
        }
    }
    fclose(fp);
    if(f==0)
        printf("Record Not Found...\n");



}
void search_by_name_result()
{

    system("cls");
    char na[30];
    int f=0;
    printf("Enter Name to search: ");
    fflush(stdin);
    gets(na);
    fp1=fopen("str.txt","rb");
    while(fread(&s,sizeof(s),1,fp1)==1)
    {
        if(strcmpi(na,s.na)==0)
        {
            f=1;
            printf("\nName of student : %s",s.na);
            printf("\nName of class : %s",s.cl);
            printf("\n\Number of id : %d",s.ID);

            printf("\n\nMarks in Data sturcture : %d",s.d_marks);
            printf("\nMarks in Statistics : %d",s.s_marks);
            printf("\nMarks in Math : %d",s.m_marks);
            printf("\nMarks in Project : %d",s.p_marks);




            printf("\nPercentage of student is  : %.2f",s.per);
            printf("\nGrade of student is : %c",s.grade);
            printf("\n\n====================================\n");
            printf("Record Found Successfully...\n");
            printf("Press any key to continue...\n\n");
            getch();



            break;
        }
    }
    fclose(fp1);
    if(f==0)
        printf("Record Not Found...\n");





}
void search_by_rl_result()
{

    system("cls");
    int ID,f=0;
    printf("Enter Roll to search: ");
    scanf("%d",&ID);
    fp1=fopen("str.txt","rb");
    while(fread(&s,sizeof(s),1,fp1)==1)
    {
        if(ID == s.ID)
        {
            f=1;
            printf("\nName of student : %s",s.na);
            printf("\nName of class : %s",s.cl);
            printf("\nNumber of id : %d",s.ID);

            printf("\n\nMarks in Data sturcture : %d",s.d_marks);
            printf("\nMarks in Statistics : %d",s.s_marks);
            printf("\nMarks in Math : %d",s.m_marks);
            printf("\nMarks in Project : %d",s.p_marks);


            printf("\nPercentage of student is  : %.2f",s.per);
            printf("\nGrade of student is : %c",s.grade);
            printf("\n\n====================================\n");
            printf("Record Found Successfully...\n");
            printf("Press any key to continue...\n\n");

            getch();



            break;
        }
    }
    fclose(fp1);
    if(f==0)
        printf("Record Not Found...\n");





}



void check_highest_lowest()
{



    system("cls");
    int ch;

    while(1)
    {

        printf("<== Varsity Management ==>\n");
        printf("<== Check highest lowest ==>\n\n");
        printf("1.Show avarge mark all student\n");
        printf("2.Check 1st Position\n");
        printf("3.Check Data structure pass fail\n");
        printf("4.Check Statistics pass fail \n");
        printf("5.Check Math pass fail\n");
        printf("5.Check Project pass fail\n");
        printf("7.Back To Admin menu\n");
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            show_avarge_mark();
            break;

        case 2:
            check_higest() ;
            break;


        case 3:
            check_data_structure_pass_fail();
            break;
        case 4:
            check_statistics_pass_fail();
            break;
        case 5:
            check_math_pass_fail();
            break;
        case 6:
            check_project_pass_fail();
            break;

        case 7:
            system("cls");
            admin();
            break;


        default:
            printf("Invalid Choice");

        }
        getch();
    }
}



void show_avarge_mark()
{
    int n;
    system("cls");
    printf("\n\n\n\t\tDISPLAY ALL AVARGE MARK !!!\n\n");
    printf("Total student: \n");
    scanf("%d",&n);
    fp1=fopen("str.txt","rb");
    while((fread(&s,sizeof(s),1,fp1))>0)
    {

        printf("\nPercentage of student is  : %.2f\n",s.per);
        printf("\n\n====================================\n");

        printf("Press any key to continue...\n\n");

        getch();




    }


    fclose(fp1);

}





void check_higest()
{


    system("cls");

    float result[10],greatest;

    int i =0;
    int f=0;
    int n;

    //printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");

    printf("Total student: \n");
    scanf("%d",&n);
    printf("The avarge results are:\n");

    for (i = 1; i < n+1; i++)
    {
        printf("The %dst student result is:\n",i);
        scanf("%f", &result[i]);
    }
    //Assume that a[0] is greatest
    greatest = result[0];
    for (i = 1; i < n+1; i++)
    {
        if (result[i] > greatest)
        {
            greatest = result[i];
        }

    }
    printf("****1st position****\n\n");
    printf("Greatest of numbers is %f\n", greatest);



    printf("1st positional student total information\n");

    fp1=fopen("str.txt","rb");
    while(fread(&s,sizeof(s),1,fp1)==1)
    {
        if(greatest==s.per)
        {

            f=1;
            printf("\nName of student : %s",s.na);
            printf("\nName of class : %s",s.cl);
            printf("\n\Number of id : %d",s.ID);
            printf("\n\nMarks in Data sturcture : %d",s.d_marks);
            printf("\nMarks in Statistics : %d",s.s_marks);
            printf("\nMarks in Math : %d",s.m_marks);
            printf("\nMarks in Project : %d",s.p_marks);

            printf("\nPercentage of student is  : %.2f",s.per);
            printf("\nGrade of student is : %c",s.grade);
            printf("\n\n====================================\n");
            printf("Record Found Successfully...\n");
            printf("Press any key to continue...\n\'n");

            break;
        }


    }


    fclose(fp1);
    if(f==0)
        printf("Record Not Found...\n");
    return 0;
}




void check_data_structure_pass_fail()
{


    system("cls");

    int result[10],greatest;

    int i =0;
    int f=0;
    int n;
    int count1=0,count2=0;
    //printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");

    printf("Total student: \n");
    scanf("%d",&n);
    printf("The Data structure results are:\n");

    for (i = 1; i < n+1; i++)
    {
        printf("The %dst student result is:\n",i);
        scanf("%d", &result[i]);
    }


    for (i = 1; i < n+1; i++)
    {

        if(result[i]>40)
        {
            count1++;
        }
        else
        {
            count2++;
        }


    }

    printf("\nTotal pass in Data structure is: %d\n",count1);
    printf("Total fail in Data structure is: %d\n\n",count2);

    printf("Press any key to continue...\n\n");

}




void check_statistics_pass_fail()
{


    system("cls");

    float result[10],greatest;

    int i =0;
    int f=0;
    int n;
    int count1=0,count2=0;
    //printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");

    printf("Total student: \n");
    scanf("%d",&n);
    printf("The Statistics results are:\n");

    for (i = 1; i < n+1; i++)
    {
        printf("The %dst student result is:\n",i);
        scanf("%f", &result[i]);
    }

    for (i = 1; i < n+1; i++)
    {

        if(result[i]>40)
        {
            count1++;
        }
        else
        {
            count2++;
        }

    }

    printf("Total pass in Statistics is: %d\n",count1);
    printf("Total fail in Statistics is: %d\n\n",count2);

    printf("Press any key to continue...\n\n");

}

void check_math_pass_fail()
{


    system("cls");

    float result[10],greatest;

    int i =0;
    int f=0;
    int n;
    int count1=0,count2=0;
    //printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");

    printf("Total student: \n");
    scanf("%d",&n);
    printf("The Math results are:\n");

    for (i = 1; i < n+1; i++)
    {
        printf("The %dst student result is:\n",i);
        scanf("%f", &result[i]);
    }

    for (i = 1; i < n+1; i++)
    {


        if(result[i]>40)
        {
            count1++;
        }
        else
        {
            count2++;
        }



    }


    printf("Total pass in Math is: %d\n",count1);
    printf("Total fail in Math is: %d\n\n",count2);

    printf("Press any key to continue...\n\n");
}

void check_project_pass_fail()
{


    system("cls");

    float result[10];

    int i =0;
    int f=0;
    int n;
    int count1=0,count2=0;
    //printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");

    printf("Total student: \n");
    scanf("%d",&n);
    printf("The Project results are:\n");

    for (i = 1; i < n+1; i++)
    {
        printf("The %dst student result is:\n",i);
        scanf("%f", &result[i]);
    }

    for (i = 1; i < n; i++)
    {

        if(result[i]>40)
        {
            count1++;
        }
        else
        {
            count2++;
        }

    }

    printf("Total pass in Project is: %d\n",count1);
    printf("Total fail in Project is: %d\n\n",count2);
    printf("Press any key to continue...\n\n");
}










void modify()
{
    system("cls");
    int choice;

    while(1)
    {

        printf("<== Varsity Management ==>\n");
        printf("<== Modify ==>\n");
        printf("\n\n1.Modify only student");
        printf("\n2.Modify student with result");
        printf("\n3.Back to main menu");

        printf("\n\nPlease Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {

        case 0:
            exit(0);
        case 1:
            modify_student();
            break;
        case 2:
            modify_student_result();
            break;
        case 3:

            admin();
            break;
        default:
            printf("Invalid Choice");
        }
        getch();

    }

}
void modify_student()
{
    system("cls");
    int ID, f=0;
    printf("Enter Roll To Modifiy: ");
    scanf("%d",&ID);
    fp=fopen("st.txt","rb+");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(ID == s.ID)
        {
            f=1;
            printf("Enter New Name: ");
            fflush(stdin);
            gets(s.na);
            printf("Enter Class: ");
            scanf("%s",s.cl);
            printf("Enter New Roll: ");
            scanf("%d",&s.ID);
            fseek(fp,-si,1);
            fwrite(&s,sizeof(s),1,fp);
            fclose(fp);
            printf("\nModified Successfully...\n\n");
            break;
        }
    }
    if(f==0)
        printf("Record Not Found...");



}
void modify_student_result()
{
    system("cls");
    int ID, f=0;
    printf("Enter Roll To Modifiy: ");
    scanf("%d",&ID);
    fp1=fopen("str.txt","rb+");
    while(fread(&s,sizeof(s),1,fp1)==1)
    {
        if(ID == s.ID)
        {
            f=1;
            printf("Enter New Name: ");
            fflush(stdin);
            gets(s.na);
            printf("Enter Class: ");
            scanf("%s",s.cl);
            printf("Enter New Roll: ");
            scanf("%d",&s.ID);
            printf("\nEnter The marks in Data structure out of 100 : ");
            scanf("%d",&s.d_marks);
            printf("\nEnter The marks in Statistic out of 100 : ");
            scanf("%d",&s.s_marks);
            printf("\nEnter The marks in maths out of 100 : ");
            scanf("%d",&s.m_marks);
            printf("\nEnter The marks in project out of 100 : ");
            scanf("%d",&s.p_marks);
            fseek(fp,-si,1);
            fwrite(&s,sizeof(s),1,fp1);
            fclose(fp1);
            printf("\nModified Successfully...\n\n");
            break;
        }
    }
    if(f==0)
        printf("Record Not Found...");



}

