#include<iostream>
using namespace std;
//------------------------
struct DT{
		int data;
			};
DT p,Stack[100];
int top;
//-------------------------
void Push(DT Stack[100],int &top,DT p, int data)
{
	p.data;
	if(top==99)
		cout<<"ngăn xep day";
	else
	{
		top++;
		Stack[top]=p;
	}
}
//-----------------------
void Pop(DT Stack[],int &top)
{
	if(top==-1)
		cout<<"ngan xep rong";
	else
	{
		p=Stack[top];
		top--;
	}
}
//--------------------------------
void Tao(DT Stack[100],int &top)
{DT p;
	top=-1;
	
	
		int n;
		cin>>n;
		while(n>0)
		{
			Push(Stack,top,p,n%2);
			n=n/2;
		}
		
}
//--------------------------------
void Xuat(DT Stack[100],int top)
{
	while(top!=-1){
		Pop(Stack,top);
		cout<<p.data;
	}	
}
//-----------------------------
main()
{
	Tao(Stack,top);
	Xuat(Stack,top);
	return 1;
}

