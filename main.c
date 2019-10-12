#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define max 20
int temp;
FILE *p,*p2;
int front=-1;
int rear=-1;
int cq[max];
int temp2;
void update();
void manager();
void insertcq(int ch);
int deletecq();
struct node
{
char fooditem[20];
int data;
int flag;
int amt_of_stock_left;
struct node *next;
};
struct stock
{
int amt;
};
struct stock rice,paneer,potato,flour;
struct stock rice={1000};
struct stock paneer={1000};
struct stock potato={1000};
struct stock flour={1000};
struct node *start=NULL;
struct node *insert(struct node *start)
{
struct node *ptr,*new_node;
int amount;
int fi;
int f;
char fn[20];
p=fopen("MAIN","a");
printf("\nenter the food item you are taking\n");
printf("\n1.rice\n2.paneer\n3.potato\n4.flour\n");
scanf("%d",&fi);
switch(fi)
{
case 1:
printf("\nenter the amount of stock you are taking\n");
scanf("%d",&amount);
temp=rice.amt;
rice.amt=rice.amt-amount;
if(rice.amt<0)
{
printf("\nyou cannot take that much quantity");
rice.amt=temp;
}
else
{
printf("\nthe amount of rice left is : %d",rice.amt);
new_node=(struct node *)malloc(sizeof(struct node));
new_node->amt_of_stock_left=rice.amt;
strcpy(new_node ->fooditem,"rice");
new_node->data=amount;
if(0.3*1000>rice.amt)
new_node ->flag=1;
else 
new_node ->flag=0;
new_node->next=start;
start=new_node;
}
return start;
break;
case 2:

printf("\nenter the amount of stock you are taking\n");
scanf("%d",&amount);
temp=paneer.amt;
paneer.amt=paneer.amt-amount;
if(paneer.amt<0)
{
printf("\nyou cannot take that much quantity");
paneer.amt=temp;
}
else
{
printf("\nthe amount of paneer left is : %d",paneer.amt);
new_node=(struct node *)malloc(sizeof(struct node));
strcpy(new_node ->fooditem,"paneer");
new_node ->amt_of_stock_left=rice.amt;

new_node->data=amount;
if(0.3*1000>paneer.amt)
new_node ->flag=1;
else
new_node ->flag=0;
new_node->next=start;
start=new_node;
}
return start;
break;
case 3:

printf("\nenter the amount of stock you are taking\n");
scanf("%d",&amount);
temp=potato.amt;
potato.amt=potato.amt-amount;
if(potato.amt<0)
{
printf("\nyou cannot take that much quantity");
potato.amt=temp;
}
else
{
printf("\nthe amount of potato left is : %d",potato.amt);
new_node=(struct node *)malloc(sizeof(struct node));
strcpy(new_node ->fooditem,"potato");
new_node ->amt_of_stock_left=rice.amt;
new_node->data=amount;
if(0.3*1000>potato.amt)
new_node ->flag=1;
else
new_node ->flag=0;
new_node->next=start;
start=new_node;
}
return start;
break;
case 4:

printf("\nenter the amount of stock you are taking\n");
scanf("%d",&amount);
temp=flour.amt;
flour.amt=flour.amt-amount;
if(flour.amt<0)
{
printf("\nyou cannot take that much quantity");
flour.amt=temp;
}
else
{
printf("\nthe amount of flour left is : %d",flour.amt);
new_node=(struct node *)malloc(sizeof(struct node));
strcpy(new_node ->fooditem,"flour");
new_node ->amt_of_stock_left=rice.amt;
new_node->data=amount;
if(0.3*1000>flour.amt)
new_node ->flag=1;
else
new_node ->flag=0;
new_node->next=start;
start=new_node;
}
return start;
break;
}
fclose(p);
}
void manager()
{
char c;
struct node *ptr;
ptr=start;
if(ptr==NULL)
{
	if(ptr->flag==1)
	update();
	else printf("\nthe stock of %s doesnot reuires to be updated",ptr->fooditem);
}
else if(ptr->next==NULL)
{
if(ptr->flag==1)
{
printf("\nthe stock of %s requires to be updated by %d",ptr->fooditem,300-ptr->amt_of_stock_left);
update();
}
else printf("\nthe stock of %s doesnot reuires to be updated",ptr->fooditem);
}
else
{
while(ptr->next!=NULL)
{
if(ptr->flag==1)
{
printf("\nthe stock of %s requires to be updated by %d",ptr->fooditem,300-ptr->amt_of_stock_left);
update();//update is a function which allows the manager to change the amount of stock by adding more to it.
}
else
{
printf("\nthe stock of %s does not requies to be updated",ptr->fooditem);
}
ptr=ptr->next;
}
}
}
void update()
{
int ask,amount;
int fi;
struct node *ptr;
ptr=start;
	printf("\nwhich food item are do you want to add\n");
	printf("\n1.rice\n2.paneer\n3.potato\n4.four\n");
	scanf("%d",&fi);	
	switch(fi)
	{
	case 1:	
	printf("\nhow much amount are you adding to the stock?\n");
	scanf("%d",&amount);
	rice.amt+=amount;
	if(0.3*1000>rice.amt)
	ptr ->flag=1;
	else 
	ptr ->flag=0;
	ptr->amt_of_stock_left+=amount;
	printf("\nthe amount of rice in stock is :%d",ptr->amt_of_stock_left);
	break;
	case 2:	
	printf("\nhow much amount are you adding to the stock?\n");
	scanf("%d",&amount);
	paneer.amt+=amount;
	if(0.3*1000>paneer.amt)
	ptr ->flag=1;
	else
	ptr ->flag=0;
	ptr->amt_of_stock_left+=amount;
	printf("\nthe amount of rice in stock is :%d",ptr->amt_of_stock_left);
	break;
	case 3:	
	printf("\nhow much amount are you adding to the stock?\n");
	scanf("%d",&amount);
	potato.amt+=amount;
	if(0.3*1000>potato.amt)
	ptr ->flag=1;
	else
	ptr ->flag=0;
	ptr->amt_of_stock_left+=amount;
	printf("\nthe amount of rice in stock is :%d",ptr->amt_of_stock_left);
	break;
	case 4:	
	printf("\nhow much amount are you adding to the stock?\n");
	scanf("%d",&amount);
	flour.amt+=amount;
	if(0.3*temp>flour.amt)
	ptr ->flag=1;
	else
	ptr ->flag=0;
	ptr->amt_of_stock_left+=amount;
	printf("\nthe amount of rice in stock is :%d",ptr->amt_of_stock_left);
	break;
	}
}
void coordinator()
{
int ch,temp1;
printf("\nenter 1 to insert or 0 for delete\n");
scanf("%d",&ch);
if(ch==1)
insertcq(ch);
else
temp1=deletecq();
}
void insertcq(int ch)
{
if(((rear==max-1)&&(front==0))||(rear==front-1))
printf("\nrestaurant full!!\n");
else if(rear==-1)
{
	rear=0;
	front=0;
	cq[rear]=ch;
}
else if(rear==max-1)
{
	rear=0;
	cq[rear]=ch;
}
else
{
	rear++;
	cq[rear]=ch;
}
}
int deletecq()
{
int val;
if(front==-1)
printf("\nrestaurant empty\n");
else if(front==rear)
front=rear=-1;
else if(front==max-1)
front=0;
else 
front++;
val=cq[front];
return val;
}
void main()
{
int choice;
do
{
printf("\nenter your profession\n");
printf("\n1.chef\n2.manager\n3.co-ordinator\n4.exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
start=insert(start);
break;
case 2:
manager();
break;
case 3:
coordinator();
break;
}
}while(choice!=4);
}

