#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

struct item
{
/*	vector<char> name;//array of items
	vector<char> desc;
*/
	char name[30],desc[100];
	item *next;
};

item *start_item=NULL;
item i1[10];

void add(item **start,char ch[30])
{
	item *p1;
	item *p;
	p=(*start);
	if((*start)==NULL)
	{
		(*start)=new item;
		strcpy((*start)->name,ch);
		(*start)->next=NULL;
	}
	else	
	{
		p1=new item;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=p1;
		strcpy(p1->name,ch);
		p1->next=NULL;
	}
}

void drop(item **start,char name[30])
{
	item *p=(*start);
	item *p1;
	
	if((*start)==NULL)
		cout<<"\nList is empty";
	else if(strcmpi((*start)->name,name)==0)
	{
		(*start)=(*start)->next;
		p->next=NULL;
		delete p;
	}
	else
	{
		while(p!=NULL)
		{
			if(strcmpi(p->next->name,name)!=0)
			{
				p1=p->next;
				p->next=p1->next;
				p1->next=NULL;
				delete p1;
			}
			else
				p=p->next;
		}
	}
}

void Display(item *start)
{
	item *p=start;
	while(p!=NULL)
	{
		cout<<"\n"<<p->name;
		p=p->next;
	}	
}

void Initialize_items()
{
	strcpy(i1[0].name,"Mouse");
	strcpy(i1[0].desc,"Computer Room");
	
	strcpy(i1[1].name,"Keyboard");
	strcpy(i1[1].desc,"Dinning Room");
	
	strcpy(i1[2].name,"Speaker");
	strcpy(i1[2].desc,"Bed Room");
	
	strcpy(i1[3].name,"Phone");
	strcpy(i1[3].desc,"Kitchen");
	
	strcpy(i1[4].name,"Speaker");
	strcpy(i1[4].desc,"Bed Room");
	
	strcpy(i1[5].name,"Charger");
	strcpy(i1[5].desc,"Store Room");				
}


//add drop display free ,pass start functions for multiple linked list
/*{
		item *start;
		vector<int>random;
	
	public:
		
		item1()
		{
			item *p,*p1;
			
			{
				p=new item;
				strcpy(p->name,"Mouse");
				strcpy(p->desc,"Computer Room");
				random.push_back(*p);
				start=p;
				p1=start;
				p->next=NULL;

				p=new item;
				strcpy(p->name,"Keyboard");
				strcpy(p->desc,"Dinning Room");
				p1->next=p;
				p->next=NULL;
				p1=p1->next;

				p=new item;
				strcpy(p->name,"Speaker");
				strcpy(p->desc,"Bed Room");
				p1->next=p;
				p->next=NULL;
				p1=p1->next;

				p=new item;
				strcpy(p->name,"Phone");
				strcpy(p->desc,"Kitchen");
				p1->next=p;
				p->next=NULL;
				p1=p1->next;

				p=new item;
				strcpy(p->name,"Speaker");
				strcpy(p->desc,"Bed Room");
				p1->next=p;
				p->next=NULL;
				p1=p1->next;

				p=new item;
				strcpy(p->name,"Charger");
				strcpy(p->desc,"Store Room");
				p1->next=p;
				p->next=NULL;
				p1=p1->next;

			}
		}
		
		void Randomise()
		{
			
		}
		void Display()
		{
			item *p=start;
			while(p!=NULL)
			{
				cout<<"\n"<<p->name;
				p=p->next;
			}
		}
		
}
*/

int main()
{
//	Initialize_item();
	add(&start_item,"Laptop");
	add(&start_item,"Charger");
	Display(start_item);
	drop(&start_item,"Laptop");
	Display(start_item);
	return 0;
}
