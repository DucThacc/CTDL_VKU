#include <iostream>
using namespace std;

struct Node{
	float num;
	int coeff;
	struct Node *next;	
};
struct Node*L;

void Inpt( struct Node*&L){
	struct Node *P=NULL;
	struct Node *C=NULL;
	int so_hang;
	cout<<"\nNhap so hang cua da thuc: ";
	cin>>so_hang;
	
	for (int i=0;i<so_hang;i++)
	{
		P= new struct Node;
		cout<<"\nNhap he so cho so hang thu "<<i+1<<" : ";
		cin>>P->coeff;
		cout<<"\nNhap so mu cho so hang thu "<<i+1<<" : ";
		cin>>P->num;
		P->next=NULL;
		
		if (L==NULL){
			L=P;
			C=P;
			
		}
		else
		{
			C->next=P;
			C=P;
		}
	}
}



void Outp(struct Node *L){
	while(L!=NULL)
	{
		cout<<L->coeff<<"X^"<<L->num;
		L=L->next;
		if(L!=NULL)
		{
			cout<<"+";
		}
	}
}

int main(){
	L=NULL;
	Inpt(L);
	Outp(L);
	return 0;
}
	



