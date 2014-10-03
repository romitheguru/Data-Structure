/**********************************************************

 * 	Object Oriented version of Stack data structure
 *	This program uses classes to represent linked  data node
 *	This program also uses the concept of inheritence
 
 **********************************************************/

#include<iostream>
#include<cstdio>
#include<new>
using namespace std;

class Node {
	int data;
	Node *next;
public:
	Node() {}
	void SetData(int i) {
		data = i;
	};
	void SetNext(Node *p) {
		next = p;
	};
	int GetData() {
		return data;
	};
	Node* GetNext() {
		return next;
	};
};

class List {
	Node *head;
protected:
	List() {
		head = NULL;
	}
	void AddFront(int item);
	int Count();
	Node* Find(int item);
	int DeleteFront();
	void ViewList();
};

class Stack : public List {
	Node *Top; 
public:
	Stack() {
		Top = NULL;
	}
	void Push(int item) {
		AddFront(item);
	}
	int Pop() {
		return DeleteFront();
	}
	void ViewStack() {
		cout<<"TOP --> ";
		ViewList();
	}
};

int main() {
	Stack s;
	s.Push(1000);
	s.Push(2000);
	s.ViewStack();
	s.Push(3000);
	s.ViewStack();
	s.Pop();
	s.ViewStack();
	return 0;
}

void List::AddFront(int item) {
	Node *p = new Node();
	p->SetData(item);
	p->SetNext(NULL);

	if(head == NULL)
		head = p;
	else {
		p->SetNext(head);
		head = p;
	}
}

int List::Count() {
	int c = 0;
	Node *temp = head;

	if(temp == NULL)
		return 0;
	while(temp != NULL) {
		c++;
		temp = temp->GetNext();
	}

	return c;
}

Node* List::Find(int item) {
	Node *temp = head;
	int flag = 0;
	
	while(temp != NULL) {
		if(temp->GetData() == item) {
			flag = 1;
			break;
		}
		temp = temp->GetNext();
	}

	if(flag == 1)
		return temp;
	else
		return NULL;
}

int List::DeleteFront() {
	int num;
	Node *temp;
	temp = head;
	num = temp->GetData();
	head = temp->GetNext();
	delete temp;
	return num;
}

void List::ViewList() {
	if(head == NULL)
		cout<<"List is empty\n";
	else {
		Node *temp;
		temp = head;
		while(temp != NULL) {
			cout<<temp->GetData()<<" --> ";
			temp = temp->GetNext();
		}
		cout<<"NULL\n";
	}
}
