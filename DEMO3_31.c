#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
					
struct ACCOUNT
{
	int logid;					/*记录ID*/
    char logdate[11];			/*记录发生日期*/
    char lognote[15];			/*记录事件说明*/
    double charge;				/*发生费用：负表示支出，正表示收入*/
    double balance;				/*余额*/
	struct ACCOUNT *next;
};

typedef struct ACCOUNT NODE;
void menu();
void menu2();
NODE* load(FILE *fp);
void add(NODE* head);
void del(NODE* head);
void disp(NODE *head);
void save(NODE *head);
void modify(NODE *head);
void query(NODE* head);


int main()
{
	NODE *head;
	FILE *fp;
	int flag;
	system("color 1F");

	fp=fopen("cashbook.txt","r");
	if(fp==NULL)
	{
		printf("wrong file.press any key to return...\n");
		getchar();
		getchar();
		return 0;
	}

    while(1)
    { 
		menu();	
		scanf("%d",&flag);
		switch(flag)
		{
		case 1:head=load(fp);break;
		case 2:save(head);break;
		case 3:add(head);break;
		case 4:del(head);break;
		case 5:modify(head);break;
		case 6:query(head);break;
		case 7:disp(head);break;
		case 0:exit(0);break;
		default:printf("\n>>>>>>>>>>提示:输入错误!\n");getch(); break;
		}
		system("cls");
    }
	fclose(fp);
	return 0;
}

void menu()
{
	printf("\t\t\t\t银行账户信息管理系统\n");
	printf("\n\n  ==================================主菜单======================================\n");
	printf("\n\t         1、从文件载入账户信息              2、保存账户信息\n");
	printf("\n\t         3、添加账户记录                    4、删除账户记录\n");
	printf("\n\t         5、修改账户记录信息                6、条件查询统计信息\n");
	printf("\n\t         7、浏览全部信息                    0、退出\n");
	printf("\n\n  ==============================================================================\n");
	printf("\n\n请选择:");
}

NODE* load(FILE *fp)
{
	NODE *p,*head,*tail;
	head=(NODE *)malloc(sizeof(NODE));
	head->next=NULL;
	tail= head;
	
	while(!feof(fp))
	{
		p=(NODE *)malloc(sizeof(NODE));
        p->next=NULL;
		fscanf(fp,"%d %s %s %lf %lf",&p->logid,p->logdate,p->lognote,&p->charge,&p->balance);
				
		if(head->next==NULL)
		{
			head->next=p;
			tail=p;
		}
		else
		{
			tail->next=p;
			tail=p;
		}
	}
	fclose(fp);
	printf("press any key to return...\n");
	getch();
	return head;
}

void disp(NODE *head)
{
	NODE *p;
	if(head->next==NULL)
	{
		printf("no data to display.press anykey to continue...\n");
		getchar();
		getchar();
		return;
	}
	p=head->next;
	while(p)
	{
		printf("%3d %11s %10s %lf %lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);
		p=p->next;
	}
	printf("press any key to return...\n");
	getch();
}

void add(NODE* head)
{
	NODE *p,*tail,*s;
	int temp;

	printf("Please input nodeno.");
	scanf("%d",&temp);
	s=head->next;
	while(s!=NULL)
	{
		if(s->logid==temp)
		{
			printf("same id,please input again:");
			scanf("%d",&temp);
			s=head->next;
		}
		else
			s=s->next;
	}

	p=(NODE *)malloc(sizeof(NODE));
	p->next=NULL;

	p->logid=temp;
	printf("input the log date:");scanf("%s",p->logdate);
	printf("input the log note:");scanf("%s",p->lognote);
	printf("input the charge:");  scanf("%lf",&p->charge);

	tail=head;
	if(head->next==NULL)
	{
		p->balance=p->charge;
		head->next=p;
		tail=p;
	}
	else
	{
		while(tail->next!=NULL)
			tail=tail->next;
		p->balance=tail->balance+p->charge;
		tail->next=p;
		tail=p;
	}
	printf("end adding, press any key to continue...");
	getch();
}

void del(NODE *head)
{
	NODE *p,*r;
	int temp;
	char ch;

	if(head->next==NULL)
	{
		printf("empty list,press any key to continue...\n");
		getchar();
		return;
	}

	printf("input the no. to delete:");
	scanf("%d",&temp);

	p=head->next;
	while(p!=NULL)
	{
		if(p->logid==temp)
		{
			printf("the record to delete:\n");
			printf("%3d  %s  %s  %lf  %lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);
			break;
		}
		p=p->next;
	}
	if(p==NULL)
	{
		printf("No node to delete.press any key to continue...\n");
		return;
	}
	else
	{
		printf("are you sure?(Y/N)");
		getch();
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
		case 'N':
		case 'n':return;
		case 'Y':
		case 'y':break;
		}		
		r=head;
		while(r->next!=p)
			r=r->next;
		r->next=r->next->next;		
	    printf("end deleting, press any key to continue...");
	    getch();
	}
}

void save(NODE* head)
{
	NODE *p;
	FILE *fp;
	if(head->next==NULL)
	{
		printf("empty list,press any key to continue...\n");
		getchar();
		return;
	}

	fp=fopen("cashbox.txt","w");
	if(fp==NULL)
	{
		printf("file open error.\n");
		return;
	}

	p=head->next;
	while(p!=NULL)
	{
		fprintf(fp,"\n%d   %s   %s   %lf   %lf",p->logid,p->logdate,p->lognote,p->charge,p->balance);
		p=p->next;
	}
	fclose(fp);
	printf("end saving, press any key to continue...");
	getch();
}

void modify(NODE *head)
{
	NODE *p;
	int find;
	char ch;

	if(head->next==NULL)
	{
		printf("empty list,press any key to continue...\n");
		getchar();
		return;
	}

	printf("please input the NO. to modify:");
	scanf("%d",&find);

	p=head->next;
	while(p!=NULL)
	{
		if(p->logid==find)
		{
			printf("the modified record is:\n"); 
			printf("%3d   %s   %s    %.2lf     %.2lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);
			break;
		}
		p=p->next;
	}
	if(p==NULL)
	{
		printf("cannot find the modified record,press anykey to continue...\n");
		getch();
		return;
	}

	printf("are you sure to modify(Y/N)?");
	scanf("%c",&ch);
	getchar();
	switch(ch)
	{
		case 'N':
		case 'n':return;
		case 'Y':
		case 'y':break;
	}
	printf("please input the item to modify(1.date   2.note   3.charge):");
	scanf("%d",&find);
	switch(find)
	{
	case 1:printf("please input new date(original date is %s):",p->logdate);
		   scanf("%s",p->logdate);
		   break;
	case 2:printf("please input new note(original note is %s):",p->lognote);
		   scanf("%s",p->lognote);
		   break;
    case 3:printf("please input new charge(original charge is %.2lf):",p->charge);
		   scanf("%lf",&p->charge);
		   break;
    default:printf("error input....");return;
	}
	getchar();
	printf("press any key to return...\n");
	getch();
}

void menu2()
{
	printf("\n\n  ==================================查询菜单======================================\n");
	printf("\n\t         1、按编号查询                  2、按时间查询\n");
	printf("\n\t         3、按类别说明                  4、按收支查询\n");
	printf("\n\t         5、按余额查询                  0、返回主菜单\n");
	printf("\n\n  ==============================================================================\n");
	printf("请选择:");
}
void query(NODE* head)
{
	NODE *p;
	int sel,No;
	double bal1,bal2,tmp;
	char date1[10],date2[10],temp[10];

	p=head->next;
	if(head->next==NULL)
	{
		printf("empty list,press any key to continue...\n");
		getchar();
		return;
	}
	system("cls");
	menu2();
	scanf("%d",&sel);
	switch(sel)
	{
	case 0:
	default:return;
	case 1:
		printf("please input the NO. to query:");
	    scanf("%d",&No);
		while(p!=NULL)
		{
			if(p->logid==No)
			{
				printf("the record is:\n"); 
				printf("%3d   %s   %s    %.2lf     %.2lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);
				break;
			}
		    p=p->next;
		}
    	if(p==NULL)
		{
			printf("cannot find the record,press anykey to continue...\n");
			getch();
			return;
		}
		break;
	case 2:
		printf("please input the date range:");
		scanf("%s%s",date1,date2);
		if(strcmp(date1,date2)>0)
		{
			strcpy(temp,date1);strcpy(date1,date2);strcpy(date2,temp);
		}

		while(p!=NULL)
		{
			if(strcmp(p->logdate,date1)>=0&&strcmp(p->logdate,date2)<=0)
			{
				printf("the record is:\n"); 
				printf("%3d   %s   %s    %.2lf     %.2lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);				
			}
		    p=p->next;
		}
    	break;
	case 3:
		printf("input the query type(1.allowance,2.shopping,3.workingpay,4.schplarship,5.other):");
		scanf("%d",&No);
		switch(No)
		{
		case 1:
			while(p!=NULL)
			{
			if(strcmp(p->lognote,"allowance")==0)
			{
				printf("the record is:\n"); 
				printf("%3d   %s   %s    %.2lf     %.2lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);				
			}
		    p=p->next;
			}
			break;
		case 2:
			while(p!=NULL)
			{
			if(strcmp(p->lognote,"shopping")==0)
			{
				printf("the record is:\n"); 
				printf("%3d   %s   %s    %.2lf     %.2lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);				
			}
		    p=p->next;
			}
			break;
		case 3:
			while(p!=NULL)
			{
			if(strcmp(p->lognote,"workingpay")==0)
			{
				printf("the record is:\n"); 
				printf("%3d   %s   %s    %.2lf     %.2lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);				
			}
		    p=p->next;
			}
			break;
		case 4:
			while(p!=NULL)
			{
			if(strcmp(p->lognote,"scholarship")==0)
			{
				printf("the record is:\n"); 
				printf("%3d   %s   %s    %.2lf     %.2lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);				
			}
		    p=p->next;
			}
			break;
		case 5:return;
		}
		break;
	case 4:
		printf("please input the item to query(1.income,2.outcome)");
		scanf("%d",&No);
		if(No==1)
		{
			while(p!=NULL)
			{
			if(p->charge>0)
			{
				printf("the record is:\n"); 
				printf("%3d   %s   %s    %.2lf     %.2lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);				
			}
		    p=p->next;
			}
		}
		else
		{
			while(p!=NULL)
			{
			if(p->charge<0)
			{
				printf("the record is:\n"); 
				printf("%3d   %s   %s    %.2lf     %.2lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);				
			}
		    p=p->next;
			}
		}

		break;
					
	case 5:
		printf("please input the balance range:");
		scanf("%lf%lf",&bal1,&bal2);
		if(bal1>bal2)
		{
			tmp=bal1;bal1=bal2;bal2=tmp;
		}
		
		while(p!=NULL)
		{
			if(p->balance>=bal1&&p->balance<=bal2)
			{
				printf("the record is:\n"); 
				printf("%3d   %s   %s    %.2lf     %.2lf\n",p->logid,p->logdate,p->lognote,p->charge,p->balance);				
			}
		    p=p->next;
		}
		break;
	}

	printf("end querying,press any key to return...\n");
	getch();
}
