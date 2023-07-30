#include<bits/stdc++.h>
using namespace std;

struct Node{
	char data;
	Node *left;
	Node *right;
};
Node *newNode(char data){
	Node *newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right= NULL;
	return newNode;
}
string postfix="";
void inOrder_traversal(Node *node){
	if(node == NULL) return;
	if( !(node->data >= '0' && node->data <= '9') )
		cout << "(";
	inOrder_traversal(node->left);
	cout << node->data;
	inOrder_traversal(node->right);
	if( !(node->data >= '0' && node->data <= '9') )
	cout << ")";
}
void preOrder_traversal(Node *node){
	if(node == NULL) return;
	cout << node->data;
	preOrder_traversal(node->left);
	preOrder_traversal(node->right);
}
void postOrder_traversal(Node *node){
	if(node == NULL) return;
	postOrder_traversal(node->left);
	postOrder_traversal(node->right);
	cout << node->data;
	postfix += node->data;
}
int compute(string postfix){
	int i = 0;
	int sum = 0;
	stack <int>s;
	while(postfix[i]!='\0'){
		if(postfix[i] >= '0' && postfix[i] <= '9'){
			s.push(postfix[i] - '0');
		}else{
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			switch (postfix[i]){
				case '+':{
					s.push(a+b);
					break;
				}
				case '-':{
					s.push(b-a);
					break;
				}
				case '*':{
					s.push(a*b);
					break;
				}
				case '/':{
					s.push(b/a);
					break;
				}
				case '^':{
					s.push(pow(b,a));
					break;
				}
			}
		}
		i++;
	}
	return s.top();
}
int main(){
	Node *root = newNode('*');
	root->left = newNode('-');
	root->left->left = newNode('8');
	root->left->right = newNode('5');
	root->right = newNode('/');
	root->right->left = newNode('+');
	root->right->right = newNode('3');
	root->right->left->left = newNode('4');
	root->right->left->right = newNode('2');
	cout << "in-order traversal:   ";
	inOrder_traversal(root);
	cout << endl;
	cout << "pre-order traversal:   ";
	preOrder_traversal(root);
	cout << endl;
	cout << "post-order traversal:   ";
	postOrder_traversal(root);
	cout << endl;
	cout << "compute:   " << postfix <<endl<< "result:   ";
	cout << compute(postfix);
	return 0;
}
