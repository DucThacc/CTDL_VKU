#include <conio.h>
#include <stdio.h>

typedef char TData;
typedef struct TNode{
		TData Data;
		TNode *left;
		TNode *right;
};
typedef TNode TTree;
TTree *p,*q,*T;

//=============================

void TaoNut(char c)
{
		p = new TTree;
		p->Data=c;
		p->left=NULL;
		p->right=NULL;
}

//==============================

void PreOrder(TTree *T)
{
	TTree *p;
	p=T;
	if(p!=NULL)
	{
		printf("%c",p->Data);
		printf(" ");
		PreOrder(p->left);
		PreOrder(p->right);
	}
}

//================================

void InOrder(TTree *T)
{
	TTree *p;
	p=T;
	if(p!=NULL)
	{
		InOrder(p->left);
		printf("%c",p->Data);
		printf(" ");
		InOrder(p->right);
	}
}

//=================================

void PosOrder(TTree *T)
{
	TTree *p;
	p=T;
	if(p!=NULL)
	{
		PosOrder(p->left);
		PosOrder(p->right);		
		printf("%c",p->Data);
		printf(" ");
	}
}

//====================================

main()
{
	T=NULL;
	TaoNut('A');		T=p;
	TaoNut('B');		T->left=p;		q=p;
	TaoNut('D');		q->left=p;		
	TaoNut('E');		q->right=p;
	TaoNut('C');		T->right=p;		q=p;
	TaoNut('F');		q->left=p;		q=p;	
	TaoNut('G');		q->left=p;
	TaoNut('H');		q->right=p;
	printf("\nDuyet tien to: ");	PreOrder(T);
	printf("\nDuyet trung to: ");	InOrder(T);
	printf("\nDuyet hau to: ");		PosOrder(T);
	getch();
}
