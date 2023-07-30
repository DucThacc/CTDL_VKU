// dung ds lk doi co so 10 sang co so 2
#include <iostream>
using namespace std;

//--------------------------
struct Node{
	int data;
	Node *next;
};
Node p, Stack[100];
int top;

void push(Node *&p, int data)
{
	Node *node =  new Node;
	node->data=data;
	node->next=p;
	p = node;
}

void pop()
{

}

void Tao(Node Stack[100] , int &top)
{
	int num;
	cin>>num;
	Node p=NULL;
	while (num>0)
	{
		push(p, n%2);
		n=n/2;
	}
}

void Xuat(Node Stack[100], int top)
{
	
}

int main()
{
	Tao(Stack,top);
	Xuat(Stack,top);
	return 1;
}
