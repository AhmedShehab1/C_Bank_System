#ifndef _GRAD_PROJ_H_
#define _GRAD_PROJ_H_
/*******************************\
TO ACCESS ADMIN_WINDOW CREDENTIALS REQUIRED
NAME ->Ahmed
PASSWORD -> 123
/*******************************/
typedef struct Bank_Information info;
struct Bank_Information
{
u8 name[50];
u8 address[70];
u8 Age;
u8 Pass[20];
u8 GUARD_ID[14];
u8 National_ID[14];
u16 State;
u16 Account_ID;
f64 balance;

info *next;
};
typedef struct Access_Admin_Window priv;
struct Access_Admin_Window
{
	u8 User_Name[15];
	u8 Pass[15];	
};
void Add_Info(void);
void Client_Window(void);
void Admin_Window(void);
void User_Choice(void);
void Pass_Gen(void);
void O_E_A(void);
void Make_Trnsc(void);
void Chng_Stat(void);
void Get_Cash(void);
u16 Srch_ID(u16 B_ID);
void Srch_ID_1 (u16 B_ID);
void Srch_NA (info *ptr);
void replay(void);
void reply_Admin(void);


#endif










