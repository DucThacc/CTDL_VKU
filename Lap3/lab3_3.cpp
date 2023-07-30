#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class PriorityQueue {
private:
	Node* head;
	Node* rear;
public:
	PriorityQueue() {
		head = NULL;
		rear = NULL;
	}	
	void push(int data){
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;

		if(head == NULL){
			head = newNode;
		}
		else if (head->data < newNode->data){
			newNode->next = head;
			head = newNode;
		}
		else{
			Node* current = head;
			while(current->next != NULL && current->next->data > newNode->data){
				current = current->next;
			}
			newNode->next = current->next;
			current->next = newNode;
		}

	}
	void pop(){
		Node* temp = head;
		head = head->next;
		delete(temp);
	}
	int top(){
		return head->data;
	}
	bool empty(){
		return head == NULL;
	}
	void print(){
		Node* current = head;
		while(current != NULL){
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};
int main(){
	PriorityQueue pq;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int number;
		cin >> number;
		pq.push(number);
	}
	pq.print();
}