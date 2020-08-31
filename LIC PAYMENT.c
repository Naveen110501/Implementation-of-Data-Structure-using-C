#include<stdio.h>
#include<stdlib.h>
void input();
void writefile();
void output();
void view();
void search();
struct date
{
int month;
int day;
int year;
};
struct account
{
int number;
char name[100];
int account_no;
int mobile_no;
char city[100];
char account_type;
float oldbalance;
float newbalance;
float payment;
struct date lastpayment;
}customer;
int tl,sl,ts;
main()
{
int i,n,choice;
printf("LIC PAYMENT:\n\n");A:
printf("\n1:to add account on list");
printf("\n2:search the account\n");
printf("3:to view customer account\n");
printf("4:output\n");
printf("5:exit\n");
printf("\nenter the choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("\nNumber of account to be created");
scanf("%d",&n);
for(i=0;i<n;i++){
input();
if(customer.payment>0)
customer.account_type=(customer.payment<0.1*customer.oldbalance)? 'O': 'I';
else
customer.account_type=(customer.oldbalance>0)?'I' : 'C';
customer.newbalance=customer.oldbalance - customer.payment;
writefile();
goto A;
}
case 2:
search();
goto A;
case 3:
view();
goto A;
case 4:
output();
goto A;
case 5:
break;
}
}
void search()
{
int element;
printf("enter the account number that you want to search\n");
scanf("%d",&element);
if(customer.account_no==element)
{
printf("\ncustomer already exist\n");
}
else
printf("\ncustomer already not exist\n");
}
void input()
{
FILE *fp=fopen("naveen.dat","rb");
fseek (fp,0,SEEK_END);
tl=ftell(fp);t
sl=sizeof(customer);
ts=tl/sl;
fseek(fp,(ts-1)*sl,SEEK_SET);
fread(&customer,sizeof(customer),1,fp);
printf("\ncustomer no:%d\n",++customer.number);
fclose(fp);
printf("Account number:");
scanf("%d",&customer.account_no);
printf("\nName:");
scanf("%s",customer.name);
printf("\nmobile no:");
scanf("%d",&customer.mobile_no);
printf("\nCity:");
scanf("%s",customer.city);
printf("Previous balance:");
scanf("%f",&customer.oldbalance);
printf("Current payment:");
scanf("%f",&customer.payment);
printf("Payment date(mm/dd/yyyy):");
scanf("%d/%d/%d",&customer.lastpayment.month,&customer.lastpayment.day,&customer.lastpayment.year);
return;
}
void view()
{
printf("Account number:");
printf("%d\n",customer.account_no);
printf("\nName:");
printf("%s\n",customer.name);
printf("\nmobile no:");
printf("%d\n",customer.mobile_no);
printf("City:");
printf("%s\n",customer.city);
printf("Previous balance:");
printf("%f\n",customer.oldbalance);
printf("Current payment:");
printf("%f\n",customer.payment);
printf("Payment date(mm/dd/yyyy):");
printf("%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
return;
}
void writefile()
{
FILE *fp;
fp=fopen("naveen.dat","ab");
fwrite(&customer,sizeof(customer),1,fp);
fclose(fp);
return;
}
void output()
{
printf("\n\n    Customer no    :%d\n",customer.number);
printf("Name 	   :%s\n",customer.name);
printf("Mobile no      :%d\n",customer.mobile_no);
printf("Account number :%d\n",customer.account_no);
printf("City           :%s\n",customer.city);
printf("Old balance    :%.f\n",customer.oldbalance);
printf("Current payment:%.f\n",customer.payment);
printf("New balance    :%.f\n",customer.newbalance);
printf("Payment date   :%d/%d/%d\n\n",customer.lastpayment.month,customer.lastpayment.day,customer.lastpayment.year);
printf("Account status :");
switch(customer.account_type)
{
case 'C':
printf("CURRENT\n\n");
break;
case 'O':
printf("OVERDUE\n\n");
break;
case 'I':
printf("ONDUE\n\n");
break;
default:
printf("ERROR\\n\n");
}
return;
}

