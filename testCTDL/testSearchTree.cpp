#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

typedef int element_type;
typedef struct node {
	element_type element;
	struct node *left, *right;
} NODE;

typedef NODE *tree;
NODE *root;

void khoi_tao_cay (NODE ** root)
{
	*root=NULL;
}

void chen(int e, NODE **root)
{
	NODE *tam;
	tam = new NODE;
	tam->element = e;
	tam->left = NULL;
	tam->right = NULL;
	if (*root == NULL )
		*root = tam;
	else
	 if (tam->element < (*root)->element)	
		if ((*root)->left)
			chen(e, &(*root)->left);
		else 
			(*root)->left = tam;
	else 
	{
	 	if (tam->element >(*root)->element)
		{
		if ((*root)->right)
			chen(e, &(*root)->right);
		else 
			(*root)->right = tam;
		}
		else 
			cout<<"\ntrung";	
	}
}

void nhap_cay(NODE **root)
{
	element_type e;
	do {
		cout<<"\nNhap element (-1 de ket thuc) :";
		cin>>e;
		if (e!=-1)
			chen(e,root);
	}	while (e!=-1);	
}
int timdequy(int x, NODE *root)
{
	int timthay =0;
	if ((root == NULL) || (timthay))
	return timthay;
	else
	{
		if (x<root->element) timdequy(x,root->left);
		else if (x>root->element) timdequy(x,root->right);
		else timthay=1;
	}
}

int tim(int x, NODE*root)
{
	int t=0;
	while ((root != NULL) && (!t))
	if (root->element==x) t=1;
	else if (x < root->element) root=root->left;
	else root = root->right;
	return t;
}

int xoacuctrai (tree *root)
{
	int k;
	if ((*root)->left == NULL)
	{
		k = (*root)->element;
		
		(*root) = (*root)->right;
		return k;
	}
	
	else return xoacuctrai(&(*root)->left);
}

void xoa(int x, tree *root)
{
	if ((*root) !=NULL)
	if (x<(*root)->element) xoa(x,&(*root)->left);
	
	else if (x>(*root)->element)
		xoa(x,&(*root)->right);
		
	else 
	
	if (((*root)->left==NULL) &&((*root)->right==NULL))
	
	(*root)=NULL;
	
	else
	
	if ((*root)->left ==NULL) (*root)=(*root)->right;
	else if ((*root)->right==NULL) (*root)=(*root)->left;
	else (*root)->element=xoacuctrai(&(*root)->right);	
}

void NLR(NODE*root){
	if (root !=NULL)
	{
		cout.width(4);
		cout<< root->element;
		NLR(root->left);
		NLR(root->right);
	}
}

void LNR(NODE *root)
{
	if (root != NULL)
	{
		cout.width(4);
		LNR(root->left);
		cout<< root->element;
		LNR(root->right);
	}
}

void RNL(NODE *root)
{
	if (root != NULL)
	{
		cout.width(4);
		RNL(root->right);
		cout<< root->element;
		RNL(root->left);			
	}
}

main(){
	khoi_tao_cay(&root);
	nhap_cay(&root);
	cout<<"\nDuyet cay NLR: ";
	NLR(root);
	
	cout<<"\nDuyet cay LNR: ";
	LNR(root);
	
	cout<<"\nDuyet cay RNL: ";
	RNL(root);
	
	int x;
	cout<<"\nNhap gia tri can tim: ";
	cin>>x;
	
	cout<<"\ntim de quy ";
	if (timdequy(x,root)) cout<<"co x";
	else cout<<"ko co";
	
	cout<<"\ntim khong de quy ";
	if (tim(x,root)) cout<<"co x";
	else cout<<"ko co";
	cout<<"\nnhap gia tri can xoa";
	cin>>x;
	xoa(x,&root);
	cout<<"\nCay da xoa(duyet cay NLR) ";
	NLR(root);
	getch();
}
