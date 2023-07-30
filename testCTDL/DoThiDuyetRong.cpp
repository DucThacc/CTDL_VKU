#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//---------------------------

int A[20][20];
int n, top=0, R=0, F=0;
int X[20], S[20], Q[20];

//----------------------------

void INP(int M[20][20], int&n)
{
	for (int d=1; d<=n; d++)
	for (int c=1; c<=n; c++)
	{
		cout<<"A["<<d<<","<<c<<"]=";
		cin>>M[d][c];
	}
}

//-----------------------------

void OUP (int M[20][20], int n)
{
	for (int d=1; d<=n; d++)
	{
		for (int c=1; c<=n; c++)
			cout<<setw(4)<<M[d][c];
		cout<<endl;	
	}
}

//-------------------------------

void AddQ(int Q[20],int &R, int &F, int k)
{
	if (R==0&&F==0)
	{
		R=F=1;
		Q[R]=Q[F]=k;
	}
	else{
		R++;
		Q[R]=k;
	}
}


//---------------------------------

void DeleteQ (int Q[20], int&R, int &F)
{
	int k;
	if(F<=R)
	{
		k=Q[F];
		F++;
	}
	cout<<setw(4)<<k;
}

//----------------------------------

void DuyetR(int M[20][20], int n)
{
	cout<<"1	";
	X[1]=0;
	for (int i=1; i<n; i++)
	{
		for (int j=1; j<=n; j++)
			if((M[i][j]==1)&&(X[j]==1))
			{
				AddQ(Q,R,F,j);
				X[j]=0;
			}
		DeleteQ(Q,R,F);	
	}
}
//-----------ham` danh' dau'-------------

void DD(int X[20], int n)
{
	for (int i=1; i<=n; i++)
		X[i]=1;
		
}

//-----------------------------------

main()
{
	cout<<"So' dinh?: ";
	cin>>n;
	INP(A,n);
	cout<<"\nDO THI VUA NHAP:\n";
	OUP(A,n);
	DD(X,n);
	cout<<"\nDuyet rong:\n";
	DuyetR(A,n);
	return 1;
}











