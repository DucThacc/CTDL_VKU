//-----Queues----------
#include <iostream>
using namespace std;
//------------------

#define Max 10;
int  Queue[Max];
int F,R;
//-------------------

void addQ(int Q[10], int &F, int &R, int x)
{
	if (R==F==-1) //rong
	{
		F++;
		R++;
		Q[F]=x;
		Q[R]=x;
	}
	else if (R-F+1<Max) //doi` toi' va` them
	{
		for (int i=F; i<R; i++)
		{
			Q[i-F]=Q[i];	
			R=i-F+1;
			F=0;
			Q[R]=x;
		}
		
	}
	else if (R<Max-1) //them binh thuong
	{
		R++;
		Q[R]=x;
	}
	else cout<<"hang` day`";
}

//-------------------------
void deletedQ(int Q[10], int &F, int &R)
{
	int x;
	if (R==F)
	{
		x=Q[F];
		F=R=-1; //khoi? tao. lai. hang` rong~
	}
	else 
	{
		x=Q[F];
		F++;
	}
	cout<<x<<"\t";
}
//--------------------------
void Inp(int Q[10], int &F, int &R)
{
	char ch;
	F=R=-1;
	do
	{
		cout<<"x= ";
		cin>>x;
		addQ(Q,F,R,x);
		cout<<"tiep tuc? ";
		cin>>ch;
	}
	while(ch=='y');
	
}
//----------------------------
void Outp(int Q[10], int F, int R)
{
	for(int i=F; i<=R; i++)
	{
		deletedQ(Q,F,R);
	}
}
//-----------------------------
main()
{
	Inp(Queue,F,R);
	Outp(Queue,F,R);
	return 1;
}
