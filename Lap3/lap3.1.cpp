#include <iostream>
using namespace std;

class Node {
  public:
    char data;
    Node* next;
    Node(char val) {
      data = val;
      next = NULL;
    }
};

class Stack {
  private:
    Node* top;
    int size;
  public:
    Stack() {
      top = NULL;
      size = 0;
    }
    bool isEmpty() {
      return size == 0;
    }
    void push(char val) {
      Node* newNode = new Node(val);
      if(top == NULL) {
        top = newNode;
      } else {
        newNode->next = top;
        top = newNode;
      }
      size++;
    }
    char pop() {
      if(top == NULL) {
        return '\0';
      } else {
        char val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return val;
      }
    }
    char peek() {
      return top == NULL ? '\0' : top->data;
    }
};

bool isOperand(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int precedence(char c) {
  switch(c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return 0;
  }
}

string infixToPostfix(string expression) {
  Stack stack;
  string postfix = "";
  
  for(int i=0; i<expression.length(); i++) {
    char c = expression[i];

    if(isOperand(c)){
      postfix += c;
    } else if(c == '(') {
      stack.push(c);
    } else if(c == ')') {
      while(stack.peek() != '('){
        postfix += stack.pop();
      }
      stack.pop();
    } else {
      while(!stack.isEmpty() && stack.peek() != '(' && precedence(c) <= precedence(stack.peek())) {
        postfix += stack.pop();
      }
      stack.push(c);
    }
  }
  
  while(!stack.isEmpty()) {
    postfix += stack.pop();
  }
  
  return postfix;
}

int eval(char op, int op1, int op2) {
  switch(op) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
    case '^':
      return pow(op1, op2);
    default:
      return 0;
  }
}

int evaluatePostfix(string expression) {
  Stack stack;

  for(int i=0; i<expression.length(); i++) {
    char c = expression[i];

    if(isOperand(c)){
      stack.push(c);
    } else {
      int operand2 = stack.pop() - '0';
      int operand1 = stack.pop() - '0';

      int result = eval(c, operand1, operand2);
      stack.push(result + '0');
    }
  }

  return stack.pop() - '0';
}

int computeValue(string expression) {
  string postfix = infixToPostfix(expression);
  return evaluatePostfix(postfix);
}

