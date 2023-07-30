#include <iostream>
#include <conio.h>
using namespace std;

struct SN
{
	int so;
	SN *next;	
};

SN *L;

void Inp(SN *&L)
{
	int x;
	char ch;
	SN *P, *C;
	do
	{
		//cap' phat' bo. nho'
		P=new SN;
		cout<<"So = ";
		cin>>P->so;
		P->next=NULL;
		
		if(L==NULL)
		{
			L=P;
			C=P;	
		}
		else 
		{
			C->next=P;
			C=P;
		}
		
		cout<<"Tiep tuc nhap?(y): ";
		cin>>ch;
	} 
	while (ch=='y' or ch=='Y');	
}

void Out(SN *L)
{
	SN *P;
	P=L;
	while(P!=NULL)
	{
		cout<<P->so<<"\t";
		P=P->next;	
	}
	
}
//chen
// co L->I->Q->Null
// tao. nut' P cho P->next= Q->next sau do' Q->next=P;

void Insert(SN *&L, int x, int k)
// i la`gia' tri. can` chen`, k la` vi tri' chen`
{
	int dem=0;
	SN *P,*Q;
	P=new SN; //cap' phat' vung` nho' cho con tro
	P->so=x; //dua gia tri x vao` truong` so' cua? con tro? P
	Q=L;
	while (dem<k and Q!=NULL)
	{
		dem++;
		Q=Q->next;	
	}
	if (Q!=NULL)
	{
		P->next=Q->next;
		Q->next=P;
	}
} 
//xoa
//muon xoa nut dang sau Q thi cho Q->next = P->next, sau do free(p) de thu hoi bo nho
void Del(SN *&L,int k )
{
	SN *Q, *P;
	int dem=0;
	Q=L;
	while (dem<k and Q!=NULL)
	{
		dem++;
		Q=Q->next;	
	}
	if (Q!=NULL)
	{
		P=Q->next;
		Q->next=P->next;
		delete(P);//thu hoi` bo. nho' con tro P
	}
}


main()
{
	int x,k,m;
	L=NULL;
	Inp(L);
	cout<<"\nDanh Sach: \n";
	Out(L);
	cout<<"\nx= "; cin>>x;
	cout<<"\nk= "; cin>>k;
	Insert(L,x,k);
	cout<<"\nDanh Sach sau chen: \n";
	Out(L);	
	cout<<"\nVi tri xoa: "; cin>>m;
	Del(L,m);
	cout<<"\nDanh Sach sau xoa: \n";
	Out(L);
	return 0;
}


