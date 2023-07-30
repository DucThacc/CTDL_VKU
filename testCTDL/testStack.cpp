#include<iostream>
using namespace std;
//------------------------
struct DT{
				float hs;
				int bac;
			};
DT p,Stack[100];
int top;
//-------------------------
void Push(DT Stack[100],int &top,DT p)
{
	cout<<"he so=";
	cin>>p.hs;
	cout<<"bac=";
	cin>>p.bac;
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
{//DT p;
	if(top==-1)
		cout<<"ngan xep rong";
	else
	{
		p=Stack[top];
		top--;
	}
	//cout<<p.hs<<"\t"<<p.bac<<"\n";
}
//--------------------------------
void Tao(DT Stack[100],int &top)
{DT p;
 char ch;
	top=-1;
	do{
		Push(Stack,top,p);
		cout<<"tiep tuc";
		cin>>ch;
	}while(ch=='y');
}
//--------------------------------
void Xuat(DT Stack[100],int top)
{
	while(top!=-1){
		Pop(Stack,top);
		cout<<p.hs<<".x^"<<p.bac<<"+";
	}	
}
//-----------------------------
main()
{
	Tao(Stack,top);
	cout<<"He so    Bac:\n";
	Xuat(Stack,top);
	return 1;
}

