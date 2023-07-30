#include <iostream>
#include <iomanip>
using namespace std;
//---------------------



int A[20][20];
int n, top=0, R=0, F=0;
int X[20], S[20], Q[20];

//----------------------

void INP(int M[20][20], int &n)
{
	for(int d=1; d<=n; d++)
	for(int c=1; c<=n; c++)	
	{
		cout<<"A["<<d<<"]["<<c<<"]=";
		cin>>M[d][c];	
	}
	
	
}

//----------------------

void OUP(int M[20][20], int &n)
{
	for(int d=1; d<=n; d++)
	{
		for(int c=1; c<=n; c++){
			cout<<setw(5)<<M[d][c];
		}
		cout<<"\n";
	}
}

//-----------ham` danh' dau'-------------

void DD(int X[20], int n)
{
	for (int i=1; i<=n; i++)
		X[i]=1;
		
}

//------POP------------------------

void Pop(int S[20], int &n)
{
	int k;
	if(n>=0){
		k=S[n];
		n--;
	}
	if(k>0)
	cout<<setw(4)<<k;
}

//-------Push----------------------

void Push(int S[20], int &n, int k)
{
	if (n<19){
		n++;
		S[n]=k;
	}
}

//-----------------------------------

void DuyetX(int M[20][20], int n){
	cout<<"1 ";
	int top=0;
	for (int i=1; i<=n; i++){
		X[1]=0;
		for (int j=n; j>=1; j--){	
			if(M[i][j]==1 and X[j]==1)
			{
				Push(S,top,j);
				X[j]=0;
			}
		}
		Pop(S,top);
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
	cout<<"1  ";
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

//------------------------
main(){
	cout<<"So' dinh?: ";
	cin>>n;
	INP(A,n);
	cout<<"\nDO THI VUA NHAP:\n";
	OUP(A,n);
	DD(X,n);
	cout<<"\nDuyet sau:\n";
	DuyetX(A,n);
	DD(X,n);
	cout<<"\nDuyet rong:\n";
	DuyetR(A,n);
	return 1;
}




























































