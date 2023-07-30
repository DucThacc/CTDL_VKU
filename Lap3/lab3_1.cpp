#include<bits/stdc++.h>
#include<stack>
using namespace std;


int priority(char c){
	if(c == '+' || c == '-') 
		return 1;
	if ( c == '*' || c == '/') 
		return 2;
	if( c == '^' ) 
		return 3;
	return 0;
}
string convert(string infix){
	string postfix = "";
	int i = 0;
	stack <int>s;
	while(infix[i] != '\0'){
		if( infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z'){
			postfix += infix[i];
			i++;
		}else if(infix[i] == '('){
			s.push(infix[i]);
			i++;
		}else if(infix[i] == ')'){
			while(s.top() != '('){
				postfix += s.top();
				s.pop();
			}
			s.pop();
			i++;
		}else{
			while(!s.empty() && priority(infix[i]) <= priority(s.top()) ){
				postfix += s.top();
				s.pop();
			}
			s.push(infix[i]);
			i++;
		}
	}
	while(!s.empty()){
		postfix += s.top();
		s.pop();
	}
	return postfix;
}
bool check(string infix){
	if(infix[0] == '+' || infix[0] == '-' || infix[0] == '*' || infix[0] == '/' ||infix[0] == '^')
		return false;
	if(infix[1] == '+' || infix[1] == '-' || infix[1] == '*' || infix[1] == '/' ||infix[1] == '^')
		return false;
	return true;
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
					s.push(a-b);
					break;
				}
				case '*':{
					s.push(a*b);
					break;
				}
				case '/':{
					s.push(a/b);
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
	int n;
	do{
		cout << "1) Convert an infix expression into its equivalent postfix notation. \n";
		cout << "2) Evaluate the postfix expression. \n";
		cout << "3) Compute the value of the postfix expression. \n";
		cout << "4) Exit\n";
		cin >> n;
		switch(n){
			case 1:{
				string infix;
				cout << "input infix: ";
				cin >> infix;
				string postfix = convert(infix);
				cout <<"Postfix: " <<postfix << endl;
				break;
			}
			case 2:{
				string infix;
				cout << "input infix: ";
				cin >> infix;
				if(check(infix))
					cout << "Is postfix \n";
				else cout << "Is not postfix \n";

				break;
			}
			case 3:{
				string postfix;
				cout << "input postfix: ";
				cin >> postfix;
				cout << "value: "<< compute(postfix) << endl;
				break;
			}
		}
	}while( n!= 4 );
	return 0;
}