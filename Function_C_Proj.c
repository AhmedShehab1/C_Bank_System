#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "STD_TYPES.H"
#include "C_GRAD_PROJ.h"
#include <time.h>
/*******************************\
TO ACCESS ADMIN_WINDOW CREDENTIALS REQUIRED
NAME ->Ahmed
PASSWORD -> 123
/*******************************/
extern info head;
extern priv Admin;
info *global,*global1;
u16 List_Length=0;
f64 MO;
u16 r;
u8 name1[50];
u8 rep[5];
void Chng_Pass (void);
void Deposit(void);
void reply(void);
void Srch_NA (info *ptr);
void Add_Info(void)
{
	srand(time(NULL));
if(List_Length==0)
{
	head.State=1;
	printf("Please Enter Your First Four Names As In Your Identity card\n");
	fflush(stdin);
scanf("%[^\n]s",head.name); 
while((strlen(head.name)<11))
    {
	printf("Name Provided Is Not Enough\nPlease Try Again --> ");
	fflush(stdin);
    scanf("%[^\n]s",head.name);
    }	
printf("Please Enter Your Address\n");
fflush(stdin);
scanf("%[^\n]s",head.address);
while((strlen(head.address)<20))
{
	printf("Address Provided Is Not Enough\nPlease Try Again --> ");
	fflush(stdin);
    scanf("%[^\n]s",head.address);
}
printf("Please Enter Your Age\n");
scanf("%hu",&head.Age);
if((head.Age)<21)
{
	printf("\n\"Age Less Than 21\"\nPlease Enter Guardian National Id(14-Digit)\n");
	scanf("%s",head.GUARD_ID);
	if((strlen(head.GUARD_ID))!=14)
	{
		printf("Invalid Guardian Id,\nTry Again\n\n");
		scanf("%s",head.GUARD_ID);
	}
}
if((head.Age)>=21)
{
printf("Please Enter Your National Id(14-Digit)\n ");
scanf("%s",head.National_ID);
	if((strlen(head.National_ID))!=14)
	{
		printf("Invalid National Id,\nTry Again\n");
		scanf("%s",head.National_ID);
	}
}
printf("Please Enter Amount Of Money :\n");
scanf("%f",&head.balance);
while(head.balance<0)
{
	printf("\nAmount Entered Not Possible\nPlease Enter Amount Again : ");
    scanf("%f",&head.balance);
}	
head.Account_ID=rand();
printf("\n\nYour Account ID is %lu\n",head.Account_ID);
Pass_Gen();
printf("\nYour Pass is %s\n",head.Pass);
head.next=NULL;
}
else
{
info *last;	
info *new=(info *)malloc(sizeof(info));
new->State=1;
	printf("Please Enter Your First Four Names As In Your Identity card\n");
	fflush(stdin);
scanf("%[^\n]s",new->name);
while((strlen(new->name)<11))
{
	printf("Name Provided Is Not Enough\nPlease Try Again --> ");
	fflush(stdin);
    scanf("%[^\n]s",new->name);
}
printf("Please Enter Your Address\n");
fflush(stdin);
scanf("%[^\n]s",new->address);
while((strlen(new->address)<20))
{
	printf("Address Provided Is Not Enough\nPlease Try Again --> ");
	fflush(stdin);
    scanf("%[^\n]s",new->address);
}
printf("Please Enter Your Age\n");
scanf("%hu",&new->Age);
if((new->Age)<21)
{
	printf("\n\"Age Less Than 21\"\nPlease Enter Guardian National Id(14-Digit)\n");
	scanf("%s",new->GUARD_ID);
	if((strlen(new->GUARD_ID))!=14)
	{
		printf("Invalid Guardian Id,\nTry Again\n\n");
		scanf("%s",new->GUARD_ID);
	}
}
if((new->Age)>=21)
{	
	replay:
 printf("Please Enter Your National Id(14-Digit)\n ");
 fflush(stdin);
 scanf("%s",new->National_ID);
	if((strlen(new->National_ID))!=14)
	{
		printf("Invalid National Id,\nTry Again\n");
		fflush(stdin);
		scanf("%s",new->National_ID);
	}
	Srch_NA(new);
	if(r==0)
	{goto replay;}
}
printf("Please Enter Amount Of Money :\n");
scanf("%f",&(new->balance));
while((new->balance)<0)
{
	printf("\nAmount Entered Not Possible\nPlease Enter Amount Again : ");
    scanf("%f",&(new->balance));
}
u32 BI=rand();
BI++;
if(BI%2==0)
{
	BI+=rand();
	new->Account_ID=BI;
	printf("\nYour Account ID is %lu\n",new->Account_ID);
}
else
{
	BI=(BI+2)/3;
	new->Account_ID=BI;
	printf("\n\nYour Account ID is %lu\n",new->Account_ID);
}
new->next=NULL;
last=&head;
while((last->next)!=NULL)
{
	last=last->next;
	
}
last->next=new;
Pass_Gen();
printf("Your Pass is %s\n",new->Pass);
}
	
	List_Length++;
	printf("\n\"Account Was Created Successfully\"\n");
	reply_Admin();
	
	
	
}

u16 Srch_ID (u16 B_ID)
{
	r=1;
global=&head;
if(List_Length==0)
{
printf("\n\nNo User Exists\n");
User_Choice();
}

if((global->Account_ID)==B_ID)
	return r;

while((global->next)!=NULL)	
{
	global=global->next;
   if((global->Account_ID)==B_ID)
   {
	   return r;
   }
   
}
r=0;
return r;	
	
}

void Srch_NA (info *ptr)
{
	u8 id[14],ids[14];
	strcpy(id,ptr->National_ID);
	r=1;
global=&head;
strcpy(ids,global->National_ID);
if(strcmp(id,ids)==0)
{
	printf("\nNational ID Already Exist\nPlease Try Again\n");
	r=0;
	return;
	
}
else
	return;

while((global->next)!=NULL)	
{
	global=global->next;
   strcpy(ids,global->National_ID);
if(strcmp(id,ids)==0)
{
	printf("National ID Already Exist\nPlease Try Again");
	r=0;
	return;
	
}
else
	return;

   
}
		
}



u16 Srch_ID1 (u16 B_ID)
{
	r=1;
global1=&head;
if(List_Length==0)
{
printf("\n\nNo User Exists\n");
User_Choice();
}

if((global1->Account_ID)==B_ID)
	return r;

while((global1->next)!=NULL)	
{
	global1=global1->next;
   if((global1->Account_ID)==B_ID)
   {
	   return r;
   }
  
} 
	
	
}





void O_E_A(void)
{
	u8 x;
	u16 y,r;
	printf("\nPlease Enter Valid Bank Account ID\n");
	fflush(stdin);
	scanf("%lu",&y);
    r=Srch_ID(y);
	if(r==1)
	{
	printf("For Making Transaction Press(1)\nTo Change Account Status Press(2)\nTo Get Cash Press(3)\nDeposit in This Account Press(4)\nTo Return To Main Menu Press(5)\n\n");
	scanf("%hu",&x);
while(x<1 || x>6)
{
	printf("Wrong Input\nTry Again");
	scanf("%hu",&x);
}
if(x!=2)
{
	if((global->State)!=1)
	{
		printf("Account Is Restrited Or Closed \n\"Action Could Not Be Done\"\n");
		User_Choice();
		
	}
}
switch(x)
{
	case 1:
	Make_Trnsc();break;
    case 2:
	Chng_Stat();break;
    case 3:
	Get_Cash();break;
	case 4:
	Deposit();break;
	case 5:	
	Admin_Window();break;
	case 6:
	Chng_Pass();
	
}
	}
	else
		{   
			printf("\n\n\"No Bank Account  Associated With The Provided ID\"\n\nDo You Want To Try Again?\nType (y) for \"yes\" or (n) for \"no\" \n\n");
			fflush(stdin);
	        scanf("%[^\n]s",rep);
			if((strcmp(rep,"Y"))==0||(strcmp(rep,"y"))==0)
				O_E_A();
			else if((strcmp(rep,"N"))==0||(strcmp(rep,"n"))==0)
	            User_Choice();
			else
			{
				printf("Invalid Input \n Window Will Be Terminated\n");
				User_Choice();
			}
}
}

void Make_Trnsc(void)
{
	u16 ID,r;
	printf("\nPlease Enter Account ID Of The User You Want To Transfer Money To : ");
    scanf("%lu",&ID);
	r=Srch_ID1(ID);
	if(r==1)
	{
	if((global1->State)!=1)
	{
		printf("\nID Provided Is Associated With A Closed Or Restricted Bank Account \n\n\t ");
		User_Choice();
		
	}
	if((global1->Account_ID)==(global->Account_ID))
	{
		printf("Transaction Failed\n\"ID Provided Is For Same User\"");
		Make_Trnsc();
	}
	printf("Please Enter Amount To Be Transfered To The Bank Account Associated With The Following  ID-->%lu\nAmount Is : ",global1->Account_ID);
	scanf("%f",&MO);
	if((global->balance)>=MO)
	{
		(global->balance)=(global->balance)-MO;
		(global1->balance)=(global1->balance)+MO;
		printf("\nOperation Was Done Successfully\n\n");
		reply();
	}
	else
	{
	printf("Transaction Failed\n\"Amount Greater Than Available In The Account\"\n\n");
	Make_Trnsc();
	}
	}
	else
	{
		printf("\n\n\"No Bank Account  Associated With The Provided ID\"\n\nDo You Want To Try Again?\nType (y) for \"yes\" or (n) for \"no\" \n\n");
		fflush(stdin);
	        scanf("%[^\n]s",rep);
			if((strcmp(rep,"Y"))==0||(strcmp(rep,"y"))==0)
				Make_Trnsc();
			else if((strcmp(rep,"N"))==0||(strcmp(rep,"n"))==0)
	            User_Choice();
			else
			{
				printf("Invalid Input \n Window Will Be Terminated\n");
				User_Choice();
			}
	}
	
	
	
}

void Chng_Stat(void)
{
	u16 z;
	printf("\nEnter (1) For Active State, (2) For Restricted State, (3) For Closed State \n\n ");
	scanf("%hu",&z);
	while(z<1 || z>3)
	{
		printf("Wrong Input\nTry Again\n");
		scanf("%hu",&z);
	}
    switch(z)
	{
		case 1:
		       if((global->State)==z)
			   {printf("Account Already In Active State\n");
		       reply_Admin();}
	           else
               {global->State=z;
		       printf("\n Account Now In Active State\n");
			   reply_Admin();}
               break;		   
		case 2:
		       if((global->State)==z)
			   {
				   printf("Account Already In Active State\n");
		           reply_Admin();
			   } 
       		   else
               {global->State=z;
		       printf("\n Account Now In Restricted  State\n");
			   reply_Admin();}
		       break;
		case 3:
		       if((global->State)==z)
			   {printf("Account Already In Active State\n");
		       reply_Admin();}
	           else
               {global->State=z;	
               printf("\n Account Now In Closed State\n");
			   reply_Admin();}		   
	           break;
		
	}
	
	
}
void Get_Cash(void)
{
	printf("Please Enter Amount Of Money You Need : ");
	scanf("%f",&MO);
    if((global->balance)>=MO)
	{
		(global->balance)-=MO;
		printf("\n%f\n",global->balance);
		printf("\nOperation Was Done Successfully\n\n");
		reply();
	}
	else
	{
	printf("\nAmount Greater Than Available In The Account\n\n");
	Get_Cash();
	}
}

void Deposit(void)
{
	printf("\nPlease Enter Amount You Want To Add To Current Account : ");
	scanf("%f",&MO);
	(global->balance)+=MO;
	printf("\n\nOperation Completed\n\n");
	reply();
}

void Chng_Pass (void)
{
	u8 N_Pass[20],O_Pass[20];
	u8 i=3;
	printf("\nPlease Enter Old Password : ");
	fflush(stdin);
    	scanf("%[^\n]s",N_Pass);
    strcpy(O_Pass,global->Pass);	
	while(strcmp(N_Pass,O_Pass)!=0)
	{
		printf("\nIncorrect Password,Please Try Again\nEnter Old Password Again: ");
		fflush(stdin);
		scanf("%[^\n]s",N_Pass);
		if(strcmp(N_Pass,O_Pass)!=0)
	    {
			i--;
			printf("\n%hu attempts remaining",i);
			
		}
	    if(i==0)
		{printf("\n\"All Attempts Were Consumed\"\nWindow Will Be Terminated\n");
		User_Choice();}
	}
		printf("\nPlease Enter New Password Maximum 15 characters : ");
		fflush(stdin);
		scanf("%[^\n]s",N_Pass);
	    while(strlen(N_Pass)>15)
		{
			printf("\nPassword exceeded 15 char\nEnter New Password:");
			fflush(stdin);
			scanf("%[^\n]s",N_Pass);
		}
		strcpy(global->Pass,N_Pass);
		printf("Password Changed Successfully\n Returning to Main Menu\n");
		User_Choice();
}

void User_Choice(void)
{
	u8 x;
	printf("Please Enter 1 To Access Admin Window & 0 To Access Client Window\n");
	fflush(stdin);
	scanf("%hu",&x);
	while(x!=0 && x!=1)
	{
		printf("Wrong Input\nTry Again\n");
		scanf("%hu",&x);
	}
	if(x==1)
	Admin_Window();
    else
	{if(List_Length==0)
		{
		printf("\nNo Users Exist\n");
 		User_Choice();
		}
		else
	     Client_Window();
	}
	
}



void Admin_Window(void)
{
	strcpy(Admin.User_Name,"Ahmed");
    strcpy(Admin.Pass,"123");
	u8 y,Name[15],Pass[15],O_Name[15],O_Pass[15];
	printf("\"Admin Window\" \nPlease Provide Valid UserName And Password To Access Admin Window\n\nEnter User Name --> ");
	fflush(stdin);
	scanf("%[^\n]s",Name);
	strcpy(O_Name,Admin.User_Name);
	printf("\nEnter Password --> ");
	fflush(stdin);
	scanf("%[^\n]s",Pass);
	strcpy(O_Pass,Admin.Pass);
	while((strcmp(Name,O_Name)!=0)&&(strcmp(Pass,O_Pass))!=0)
	{
		printf("\n\nInvalid UserName Or Password \nPlease Try Again\n");
		printf("Enter User Name -->");
		fflush(stdin);
	scanf("%[^\n]s",Name);
	strcpy(O_Name,Admin.User_Name);
	printf("\nEnter Password --> ");
	fflush(stdin);
	scanf("%[^\n]s",Pass);
	strcpy(O_Pass,Admin.Pass);
	}
	printf("\n\nAvailable Actions : \n\n 1.Create New Account(1)\n\n2.Open Existing Account(2)\n\n3.Exit The System(3)\n\nPlease Type The No. Associated With The Action Needed : \n\n ");
		scanf("%hu",&y);
		while(y<1 || y>3)
	{
		printf("Wrong Input\nTry Again\n");
		scanf("%hu",&y);		
	}
	switch(y)
	{
		case 1 : Add_Info();break;
		case 2 :O_E_A();break;
		case 3 :User_Choice();break;
		
	}
	
	
	
}
//gcc C_GRAD_PROJ.c Function_C_Proj.c

void Client_Window(void)
{
u16 ID;
u8 Pass_Check[15],O_Pass[20],x,i;
printf("\nPlease Enter Your Account ID : ");
scanf("%lu",&ID);
Srch_ID(ID);
if(r==1)
{
if((global->State!=1))
{
	printf("Account Is Currently Closed Or Restricted \n Please Contact The Bank For Further Information\n");
	User_Choice();
}
printf("\nPlease Enter Your Account Password\n-->");
fflush(stdin);
scanf("%[^\n]s",Pass_Check);
strcpy(O_Pass,global->Pass);
i=3;
while(strcmp(Pass_Check,O_Pass)!=0)
	{
		printf("\nIncorrect Password,Please Try Again\nEnter Password Again: ");
		fflush(stdin);
		scanf("%[^\n]s",Pass_Check);
		if(strcmp(Pass_Check,O_Pass)!=0)
	    {
			i--;
			printf("\n %hu attempts remaining",i);
		
		}
	    if(i==0)
		{printf("\n\"All Attempts Were Consumed\"\nWindow Will Be Terminated\n");
		User_Choice();}
	}
printf("\n\n\n\"Welcome To Client Window \"\n Available Actions : \n\n 1.Make Transaction(1)\n\n2.Change Account Password(2)\n\n3.Get Cash(3)\n\n4.Deposit In Account(4)\n\n5.Return To Main Menu(5)\n\nPlease Type The No. Associated With The Action Needed : \n\n ");
scanf("%hu",&x);
while(x<1 || x>5)
	{
		printf("Wrong Input\nTry Again\n");
		scanf("%hu",&x);
	}
	switch(x)
	{
		
		case 1:
		Make_Trnsc();break;
		case 2:
		Chng_Pass();break;
		case 3:
		Get_Cash();break;
		case 4:
		Deposit();break;
		case 5:
		User_Choice();break;
		
		
		
	}
}
else
{
	printf("\n\"ID Provided Doesnt Exist\"\n\n");
	User_Choice();
}
	
	
	
	
}
void reply(void)
{
	u16 x;
			printf("Do You Want To Perform Another Operation?\nType (y) for \"yes\" or (n) for \"no\" \n\n");
			fflush(stdin);
	        scanf("%[^\n]s",rep);
			if((strcmp(rep,"Y"))==0||(strcmp(rep,"y"))==0)
			{
				printf("\n\n1.Make Transaction(1)\n\n2.Change Account Password(2)\n\n3.Get Cash(3)\n\n4.Deposit In Account(4)\n\n5.Return To Main Menu(5)\n\nPlease Type The No. Associated With The Action Needed : \n\n ");
				scanf("%hu",&x);
              while(x<1 || x>5)
	          {
		        printf("Wrong Input\nTry Again\n");
		        scanf("%hu",&x);
	          }
	   switch(x)
	   {
		
		case 1:
		Make_Trnsc();break;
		case 2:
		Chng_Pass();break;
		case 3:
		Get_Cash();break;
		case 4:
		Deposit();break;
		case 5:
		User_Choice();break;
		
		
		
	   }
			}
			else if((strcmp(rep,"N"))==0||(strcmp(rep,"n"))==0)
	            User_Choice();
			else
			{
				printf("Invalid Input \n Window Will Be Terminated\n");
				User_Choice();
			}
	
}
void reply_Admin(void)
{
	u16 y;
			printf("Do You Want To Perform Another Operation?\nType (y) for \"yes\" or (n) for \"no\" \n\n");
			fflush(stdin);
	        scanf("%[^\n]s",rep);
			if((strcmp(rep,"Y"))==0||(strcmp(rep,"y"))==0)
			{
				printf("\n\nAvailable Actions : \n\n 1.Create New Account(1)\n\n2.Open Existing Account(2)\n\n3.Exit The System(3)\n\nPlease Type The No. Associated With The Action Needed : \n\n ");
		scanf("%hu",&y);
		while(y<1 || y>3)
	{
		printf("Wrong Input\nTry Again\n");
		scanf("%hu",&y);		
	}
	switch(y)
	{
		case 1 : Add_Info();break;
		case 2 :O_E_A();break;
		case 3 :User_Choice();break;
		
	}
			}
			else if((strcmp(rep,"N"))==0||(strcmp(rep,"n"))==0)
	            User_Choice();
			else
			{
				printf("Invalid Input \n Window Will Be Terminated\n");
				User_Choice();
			}
	
}

#define PASSLEN 16
void Pass_Gen(void)
{
	info *pass=&head;
	u8 set_var[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	srand(time(NULL));
	u16 index,i;
	if(List_Length==0)
	{
	for(i=0;i<PASSLEN-1;++i)
	{
		index=rand()%62;
		pass->Pass[i]=set_var[index];
	}	
		
	}
	else{
		while((pass->next)!=NULL)
		{
			pass=pass->next;
	for(i=0;i<PASSLEN-1;++i)
	{
		index=rand()%62;
		pass->Pass[i]=set_var[index];
	}		
			
			
	  }	
	}	
}

