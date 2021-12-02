#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define USER_MAX 50

typedef struct
{   char firstname[60];
    char lastname[60];
    char email[100];
    char username[20];
    char password[20];
} User;
typedef struct rate
{   
    float dhrating;
    float coxrating;
    float syrating;
    float ctrating;
    float bdnrating;
}rt;
typedef struct trag
{   
    float atbdrating;
    float cbdtrating;
    float dhholirating;
    float bdsrating;
    
}tr;

User list[USER_MAX];
User u;

char* filename = "user.txt";
//void copytofile();
void welcome();
User login();
void writeToFile(User u);
int exist(User u);
void registerUser();
void showblog(const char *locname);
float rates();
float agencyrates();
float average(const char *ratefile);
void writeblog(const char *writefile);


int main()

{   
    struct rate rt;
    struct trag tr;

     int choice=0,sub_ch_1=0,sub_ch_2=0,sub_ch_3=0,sub_ch_4=0,sub_ch_4_1=0,sub_ch_4_2=0;
    //copytofile();
    welcome();
    system("cls");
    User test[USER_MAX];
    FILE *fp = fopen(filename,"r");
    int i=0;
    if(NULL == fp)
    {
        printf("FILE NOT FOUND");
        return -1;
    }
    
    for(i=0; i<USER_MAX; i++)
    {
        char ufirstname[60];
        char ulastname[60];
        char uemail[100];
        char uname[20];
        char upassword[20];
        fscanf(fp,"%s%s%s%s%s",ufirstname,ulastname,uemail,uname,upassword);
        strcpy(list[i].firstname , ufirstname);
        strcpy(list[i].lastname , ulastname);
        strcpy(list[i].email , uemail);
        strcpy(list[i].username , uname);
        strcpy(list[i].password , upassword);
    }
    
     while(choice!=5)
{
    system("cls");
    system("color d");
    printf("\t\t\t=====================\n");
    printf("\t\t\t||     MAIN MENU   ||\n");
    printf("\t\t\t=====================\n\n");
    printf("\t\t1=> Login/Create Account.\n\n\t\t2=> Locations you might visit.\n\n\t\t3=> Share Your Travel Experiences.\n\n\t\t4=> Suggested Travel Agencies.\n\n\t\t5=> Exit and Close.\n\n");
    
    printf("Enter Choice:");
    scanf("%d",&choice);
    
switch (choice)
 {
case 1:

do
   {
       system("color c");
system("cls");
    printf("\t\t\t==================================\n");
    printf("\t\t\t||     LOGIN/CREATE ACCOUNT     ||\n");
    printf("\t\t\t==================================\n\n");
printf("\t\t1=> Login.\n\n\t\t2=> Create Account\n\n\t\t3=> Exit\n\n");

printf("Enter Choice:");
scanf("%d",&sub_ch_1);
if(1 == sub_ch_1)
    {
        
        system("cls");
        u=login();
        if(1 == exist(u))
        {
            printf("success!!!\n Press enter to Main Menu....");
            getch();
            
        }
        else
        {
            printf("WRONG USERNAME OR PASS TRY AGAIN.\n Press enter to continue.... ");
            getch();
            
        }
        
    }
    else if (2 == sub_ch_1)
    {
        system("cls");
        registerUser();
         printf("Press enter for Main Menu");
        getch();
       
    }
    else
    {
        printf("......");
    }
   }while(sub_ch_1!=3);


break;
case 2:
  
 do
  { system("color a");
    system("cls");
    printf("\t\t\t=======================================\n");
    printf("\t\t\t||     LOCATIONS YOU MIGHT VISIT     ||\n");
    printf("\t\t\t=======================================\n\n");
    printf("\t\t1=> Dhaka\n\n\t\t2=> Cox's Bazar\n\n\t\t3=> Syhlet\n\n\t\t4=> Chittagong\n\n\t\t5=> Bandarban\n\n\t\t6=> Exit\n\n");
    printf("Choose your desination:");
    scanf("%d",&sub_ch_2);
    switch (sub_ch_2)
    {
    case 1:
    system("cls");
    
     showblog("dhAka.txt");
     printf("\nUsers Rate It %.2f out of 5\n\n",average("dhrating.txt"));
     getch();
        break;
        case 2:
        system("cls");
        showblog("coxs.txt");
        printf("\nUsers Rate It %.2f out of 5\n\n",average("coxrating.txt"));
        getch();
        break;
    case 3:
    system("cls");
    showblog("shylet.txt");
    printf("\nUsers Rate It %.2f out of 5\n\n",average("syrating.txt"));
    getch();
        break;
        case 4:
        system("cls");
        showblog("chittagong.txt");
        printf("\nUsers Rate It %.2f out of 5\n\n",average("ctrating.txt"));
        getch();
        break;
        case 5:
        system("cls");
        showblog("bandarban.txt");
        printf("\nUsers Rate It %.2f out of 5\n\n",average("bdnrating.txt"));
        getch();
        break;
        case 6:
        system("cls");
        printf(".........");
        break;
    default:
    printf("Invalid Input..");
        break;
    }//SECOND SWITCH
  } while (sub_ch_2!=6);
    
break;
case 3:
system("color b");
    system("cls");
        u=login();
        if(1 == exist(u))
        {
            printf("success!!!\n Press enter to Share Experience Menu....");
            getch();
            
        }
        else
        {
            printf("WRONG USERNAME OR PASS TRY AGAIN.\n Press enter to continue.... ");
            getch();
            
        }

do

{
     
    system("cls");
    system("color b");
    printf("\t\t\t===========================================\n");
    printf("\t\t\t||     SHARE YOUR TRAVEL EXPERIENCES     ||\n");
    printf("\t\t\t===========================================\n\n");
    printf("\t\t1=> Dhaka\n\n\t\t2=> Cox's Bazar\n\n\t\t3=> Syhlet\n\n\t\t4=> Chittagong\n\n\t\t5=> Bandarban\n\n\t\t6=> Exit\n\n");
    printf("Choose your desination:");
    scanf("%d",&sub_ch_3);
    
    switch(sub_ch_3)
    {
        case 1:
                rt.dhrating=rates();

                FILE *dh = fopen("dhrating.txt","a");

                fprintf(dh, "%.2f\n", rt.dhrating);
                fclose(dh);
                getchar();
                writeblog("dhAka.txt");
               
               


        break;
        case 2:
                rt.coxrating=rates();

                FILE *cox = fopen("coxrating.txt","a");

                fprintf(cox, "%.2f\n", rt.coxrating);
                fclose(cox);
                getchar();
                writeblog("coxs.txt");

         break;
        case 3:
                rt.syrating=rates();

                FILE *sy = fopen("syrating.txt","a");

                fprintf(sy, "%.2f\n", rt.syrating);
                fclose(sy);
                getchar();
                writeblog("shylet.txt");

         break;
        case 4:
                rt.ctrating=rates();

                FILE *ct = fopen("ctrating.txt","a");

                fprintf(ct, "%.2f\n", rt.ctrating);
                fclose(ct);
                getchar();
                writeblog("chittagong.txt");

         break;
        case 5:
                rt.bdnrating=rates();

                FILE *bdn = fopen("bdnrating.txt","a");

                fprintf(bdn, "%.2f\n", rt.bdnrating);
                fclose(bdn);
                getchar();
                writeblog("bandarban.txt");

         break;
        case 6:

        printf(".....");
         break;
         default:
    printf("Invalid Input..");
        break;
    }//THIRD SWITCH

}while(sub_ch_3!=6);

break;
case 4:
do
{
    system("cls");
    system("color e");
    printf("\t\t\t==================================\n");
    printf("\t\t\t||         TOUR AGENCIES        ||\n");
    printf("\t\t\t==================================\n\n");
printf("\t\t1=> Rate Existing Travel Agencies.\n\n\t\t2=> Travel Agency Informations and Rating\n\n\t\t3=> Exit\n\n");

printf("Enter Choice:");
scanf("%d",&sub_ch_4);
if(sub_ch_4==1)
{system("cls");
        u=login();
        if(1 == exist(u))
        {
            printf("success!!!\n Press enter to Rate Tour Agencies....");
            getch();
            
        }
        else
        {
            printf("WRONG USERNAME OR PASS TRY AGAIN.\n Press enter to continue.... ");
            getch();
            
        }
    do
    {
        system("cls");
    printf("\t\t\t=================================\n");
    printf("\t\t\t||      RATE TOUR AGENCIES     ||\n");
    printf("\t\t\t=================================\n\n");
printf("\t\t1=> Amazing Tour BD.\n\n\t\t2=> Cholo BD Tours.\n\n\t\t3=> Dhaka Holidays.\n\n\t\t4=> BD Stall\n\n\t\t5=> Exit\n\n");

printf("Enter Choice:");
scanf("%d",&sub_ch_4_1);

switch(sub_ch_4_1)
{
case 1:
tr.atbdrating=agencyrates();
FILE *atbd = fopen("atbdrating.txt","a");
fprintf(atbd, "%.2f\n", tr.atbdrating);
 fclose(atbd);
break;
case 2:
tr.cbdtrating=agencyrates();
FILE *cbdt = fopen("cbdtrating.txt","a");
fprintf(cbdt, "%.2f\n", tr.cbdtrating);
 fclose(cbdt);
break;
case 3:
tr.dhholirating=agencyrates();
FILE *dhholi = fopen("dhholirating.txt","a");
fprintf(dhholi, "%.2f\n", tr.dhholirating);
 fclose(dhholi);
break;
case 4:
tr.bdsrating=agencyrates();

FILE *bds = fopen("bdsrating.txt","a");

fprintf(bds, "%.2f\n", tr.bdsrating);
 fclose(bds);
break;
case 5:
printf("...");
break;
default:
printf("Invalid Input...");
}//AGENCY RATING SWITCH
}while(sub_ch_4_1!=5);
}
else if(sub_ch_4==2)
{ 
    do
    {
        system("cls");
    printf("\t\t\t==================================\n");
    printf("\t\t\t||         TOUR AGENCIES        ||\n");
    printf("\t\t\t==================================\n\n");
printf("\t\t1=> Amazing Tour BD.\n\n\t\t2=> Cholo BD Tours.\n\n\t\t3=> Dhaka Holidays.\n\n\t\t4=> BD Stall\n\n\t\t5=> Exit\n\n");

printf("Enter Choice:");
scanf("%d",&sub_ch_4_2);

switch(sub_ch_4_2)
{
case 1:
system("cls");
showblog("amazingtrbd.txt");
printf("\nUsers Rate It %.2f out of 5\n\n",average("atbdrating.txt"));
getch();
break;
case 2:
system("cls");
showblog("chbdtr.txt");
printf("\nUsers Rate It %.2f out of 5\n\n",average("cbdtrating.txt"));
getch();
break;
case 3:
system("cls");
showblog("dhakaholidays.txt");
printf("\nUsers Rate It %.2f out of 5\n\n",average("dhholirating.txt"));
getch();
break;
case 4:
system("cls");
showblog("bdstall.txt");
printf("\nUsers Rate It %.2f out of 5\n\n",average("bdsrating.txt"));
getch();
break;
case 5:
printf("....");
break;
default:
printf("Invalid Input...");
break;
}

}while(sub_ch_4_2!=5);
}
else
{
printf("...");
}
}while(sub_ch_4!=3);




break;
case 5:
printf("Exit and close");
break;
default:
printf("Enter correct choice");





 }//END OF MAIN SWITCH
}

return 0;
}
 void welcome()
    {
        system("color a");
    printf("\t\t\t###########\n");
    printf("\t\t\t#         #\n");
    printf("\t\t\t# Welcome #\n");
    printf("\t\t\t#         #\n");
    printf("\t\t\t###########\n");
    printf("\t\t  #######################\n");
    printf("\t\t  #                     #\n");
    printf("\t\t  # Ultimate Tour Guide #\n");
    printf("\t\t  #                     #\n");
    printf("\t\t  #######################\n");
    printf("\n\n\nPress enter to continue");
    getch();
    
    }
    User login()
{
    char username[20];
    char password[20];
    User lg;
    printf("enter username:");
    scanf("%s",username);
    strcpy(lg.username , username);
    printf("enter password:");
    scanf("%s",password);
    strcpy(lg.password,password);
    return lg;
}

void writeToFile(User u)
{
    FILE *fw = fopen(filename,"a+");
    fprintf(fw,u.firstname);
    fprintf(fw,"\t");
    fprintf(fw,u.lastname);
    fprintf(fw,"\t");
    fprintf(fw,u.email);
    fprintf(fw,"\t");
    fprintf(fw,u.username);
    fprintf(fw,"\t");
    fprintf(fw,u.password);
    fprintf(fw,"\n");
}

int exist(User u)
{
    int i;
    for(i=0; i<USER_MAX; i++)
    {
        if(0==strcmp(list[i].username ,u.username) && 0==strcmp(list[i].password ,u.password))
        {
            return 1;
        }
    }
    return -1;
}

void registerUser()
{   char firstname[60];
    char lastname[60];
    char email[100];
    char username[20];
    char password[20];
    User user;
    int i;
    printf("Enter your first name:");
    scanf("%s",firstname);
    strcpy(user.firstname , firstname);
    printf("Enter your last name:");
    scanf("%s",lastname);
    strcpy(user.lastname , lastname);
    printf("Enter your email:");
    scanf("%s",email);
    strcpy(user.email , email);
    printf("Enter your username:");
    scanf("%s",username);
    strcpy(user.username , username);

    for(i=0; i<USER_MAX; i++)
    {
        if(0==strcmp(list[i].username ,username))
        {
            printf("USERNAME ALREADY EXIST");
            return;
        }
    }

    printf("enter your password:");
    scanf("%s",password);
    strcpy(user.password , password);
    writeToFile(user);
}
void showblog(const char *locname)
{
    system("color f");
	FILE *fptr;
	char str;
	fptr = fopen (locname, "r");  
	if (fptr == NULL)
	{
		printf(" File does not exist or cannot be opened.\n");
		exit(0);
	}
	str = fgetc(fptr);
	while (str != EOF)
		{
			printf ("%c", str);
			str = fgetc(fptr);
		}
	fclose(fptr);
    
    
}

float rates()
{
float rating, food, accommodation, sights;
system("cls");
printf("\t\tRate your experience about accommodation,food & sights out of 5. \n");
printf("\t\tRate Accommodation:");
scanf("%f",&accommodation);
printf("\t\tRate Food:");
scanf("%f",&food);
printf("\t\tRate Sights:");
scanf("%f",&sights);
rating=(accommodation+food+sights)/3.0;
printf("\t\tFinal rating:%.2f",rating);
getch();
return rating;
}


float agencyrates()
{
float rating, accommodation,cost, customercare;
printf("\n\n\n\t\tRate your experience about Accommodation,Cost & Customer Care out of 5. \n");
printf("\t\tRate Accommodation:");
scanf("%f",&accommodation);
printf("\t\tRate Cost:");
scanf("%f",&cost);
printf("\t\tRate Customer Care:");
scanf("%f",&customercare);
rating=(accommodation+cost+customercare)/3.0;
printf("Final rating:%.2f",rating);
getch();

return rating;
}

float average(const char *ratefile)
{	
FILE *fp;

float ratings,stat,count=0.0,sum=0.0;
fp = fopen(ratefile,"r");
stat= fscanf(fp,"%f",&ratings);
while(stat==1)
{
	
	sum+=ratings;
	stat= fscanf(fp,"%f",&ratings);
	count++;
}

return sum/count;
}

 void writeblog(const char *writefile)
{
    char writeblog[1000],headline[100], c;
   int index = 0;
    FILE *wbl = fopen(writefile, "a+");
   printf("\n\nEnter a headline of your blog:");
   fgets(headline, sizeof(headline), stdin);
   fprintf(wbl,"\n%s",headline);
   fprintf(wbl,"---------------------------------------------------------------------------------");
   time_t t;   // not a primitive datatype
    time(&t);
    fprintf(wbl,"\n%s",ctime(&t));
   fprintf(wbl,"--------------------------\n");
   
   printf("Start sharing your blog( press '/' and enter to end typing)\n");
   while((c = getchar()) != '/'){
       writeblog[index++] = c;
   }
   writeblog[index] = '\0';
   fprintf(wbl,"\n%s\n\n",writeblog);
   fclose(wbl);
}