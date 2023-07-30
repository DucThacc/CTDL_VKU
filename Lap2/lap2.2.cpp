#include <iostream>
#include <math.h> 

using namespace std;

struct Node {
	int num;
	int coeff; 
	struct Node *next;
};

Node *poly1 = NULL;
Node *poly2 = NULL;

void add1(int x) {
	Node *newNode = new Node[sizeof(Node)];
  	cout << "Coeff: " << x << endl;
	cout << "Enter number: ";
  	cin >> newNode->num;
	
	newNode->coeff = x;
  	newNode->next = NULL;

	if (poly1 == NULL) {
		poly1 = newNode;
	    return;
	}

	Node *current = poly1;
	while (current->next != NULL) {
	  current = current->next;
	}
	current->next = newNode;
}
void add2(int x) {
	Node *newNode = new Node[sizeof(Node)];
  	cout << "Coeff: " << x << endl;
	cout << "Enter number: ";
  	cin >> newNode->num;
	
	newNode->coeff = x;
  	newNode->next = NULL;

	if (poly2 == NULL) {
		poly2 = newNode;
	    return;
	}

	Node *current = poly2;
	while (current->next != NULL) {
	  current = current->next;
	}
	current->next = newNode;
}

void print() {
  	Node *current = poly1;
  	cout << "Polynomial 1: ";
  	while (current != NULL) {
  		if (current->coeff != 0) {
  			if (current->num > 0) {
    			cout << current->num << "*x^" << current->coeff << " + ";
			} else if (current->num < 0) {
				cout << "(" << current->num << ")*x^" << current->coeff << " + ";	
			} 
		} else {
			cout << current->num << " = 0\n";	
		} 
	    current = current->next;
	}
	current = poly2;
  	cout << "Polynomial 2: ";
  	while (current != NULL) {
    	if (current->coeff > 0) {
    		if (current->num > 0) {
    			cout << current->num << "*x^" << current->coeff << " + ";
			} else if (current->num < 0) {
				cout << "(" << current->num << ")*x^" << current->coeff << " + ";	
			} 
		} else {
			if (current->num < 0) 
				cout << "(" << current->num << ") = 0\n";	
			else 
				cout << current->num << " = 0\n";
		} 
	    current = current->next;
	}
}
 
void addition() {
	Node *current1 = poly1;
	Node *current2 = poly2;
	
	print();
	
	cout << "Polynomial add: ";
	int temp = current1->coeff - current2->coeff; 
	if (temp > 0) {
		for (int i = 0; i < temp; i++) {
			if (current1->num > 0) {
    			cout << current1->num << "*x^" << current1->coeff << " + ";
			} else if (current1->num < 0) {
				cout << "(" << current1->num << ")*x^" << current1->coeff << " + ";	
			}
			current1 = current1->next;
		}
	} else if (temp < 0) {
		for (int i = 0; i < abs(temp); i++) {
			if (current2->num > 0) {
    			cout << current2->num << "*x^" << current2->coeff << " + ";
			} else if (current2->num < 0) {
				cout << "(" << current2->num << ")*x^" << current2->coeff << " + ";	
			}
			current2 = current2->next;
		}
	} 
	 
	int add; 
	while (current1 != NULL && current2 != NULL) {
		add = current1->num + current2->num;
	    if (current1->coeff > 0) {
    		if (add > 0) {
    			cout << add << "*x^" << current1->coeff << " + ";
			} else if (add < 0) {
				cout << "(" << add << ")*x^" << current1->coeff << " + ";	
			} 
		} else {
			if (add < 0) 
				cout << "(" << add << ") = 0\n";	
			else 
				cout << add << " = 0\n";	
		} 
		current1 = current1->next;
	    current2 = current2->next;
	}
}
void subtraction() {
	Node *current1 = poly1;
	Node *current2 = poly2;
	
	print();
	
	cout << "Polynomial sub: ";
	int temp = current1->coeff - current2->coeff; 
	if (temp > 0) {
		for (int i = 0; i < temp; i++) {
			if (current1->num > 0) {
    			cout << current1->num << "*x^" << current1->coeff << " + ";
			} else if (current1->num < 0) {
				cout << "(" << current1->num << ")*x^" << current1->coeff << " + ";	
			}
			current1 = current1->next;
		}
	} else if (temp < 0) {
		for (int i = 0; i < abs(temp); i++) {
			if (current2->num > 0) {
    			cout << "(-" << current2->num << ")*x^" << current2->coeff << " + ";	
			} else if (current2->num < 0) {
				cout << current2->num << "*x^" << current2->coeff << " + ";	
			}
			current2 = current2->next;
		}
	} 
	
	int sub; 
	while (current1 != NULL && current2 != NULL) {
		sub = current1->num - current2->num;
	    if (current1->coeff > 0) {
    		if (sub > 0) { 
    			cout << sub << "*x^" << current1->coeff << " + ";
			} else if (sub < 0) {
				cout << "(" << sub << ")*x^" << current1->coeff << " + ";	
			} 
		} else {
			if (sub < 0) 
				cout << "(" << sub << ") = 0\n";	
			else 
				cout << sub << " = 0\n";	
		} 
		current1 = current1->next;
	    current2 = current2->next;
	}
}

int main() {
	int c = 0;
	
	do {
		cout<<"\n****************PROJECT****************** ";
		cout<<"\n1 : Add a polynomials";
		cout<<"\n2 : Print a polynomials";
		cout<<"\n3 : Addition on a polynomials";
		cout<<"\n4 : Subtraction on a polynomials";
		cout<<"\n0 : Exit";
		cout<<"\nEnter your choice: ";
		cin>>c;
		
		
		switch(c) {
			case 0:
				cout<<"\nEnd.";
				break;
			
			case 1:
				if (poly1 != NULL) {
					poly1 = NULL; 
				} 
				
				int coeff;
				cout << "Enter coeff of polynomial 1: ";
				cin >> coeff;
				for (int i = coeff; i >= 0; i--)
					add1(i);
			
			case 2:
				print();
				break;
			
			case 3:
				addition();
				break;
				
			case 4:
				subtraction();
				break;		 
			
			default:
				cout<<"\nWRONG CHOICE";
		}
	} while(c != 0);
	
	return 0;
}
