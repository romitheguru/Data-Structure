/**********************************************************

 * 	Object Oriented version of linked list data structure
 * 	This program uses class to represent linked  data node
 
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
	Node *tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	void AddBack(int item);
	int Count();
	void InsertNode(int position,int item);
	Node* Find(int item);
	void DeleteFront();
	void DeleteBack();
	void DeleteBetween(Node *item);
	void DeleteNode(int item);
	void ViewList();
};

int main() {
	List l;
	l.AddBack(100);
	l.ViewList();
	l.AddBack(200);
	l.AddBack(300);
	l.AddBack(400);
	l.AddBack(500);
	l.InsertNode(3,700);
	l.DeleteNode(400);
	l.ViewList();
	return 0;
}

void List::AddBack(int item) {
	Node *p;
	p = new Node();
	p->SetData(item);
	p->SetNext(NULL);

	if(head == NULL) {
		head = p;
		tail = p;
	}
	else {
		tail->SetNext(p);
		tail = p;
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

void List::InsertNode(int position,int item) {
	if(position == 0) {
		printf("Head lies at position 0,\nDo want to create a new head(y/n)...");
		Node *p;
		p = new Node();
		p->SetData(item);
		p->SetNext(head);
		head = p;
		return;
	}
	else {
		int c = Count();

		if(position > c+1) {
			printf("ERROR!!\nPosition does not exist\nCan't be inserted\n");
			return;
		}

		if(position == c+1)
			AddBack(item);
		else {
			Node *temp;
			temp = head;

			for (int i = 1; i < position-1; i++) {
				temp = temp->GetNext();
			}

			Node *p = new Node();
			p->SetData(item);
			p->SetNext(temp->GetNext());
			temp->SetNext(p);
		}
	}
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

void List::DeleteFront() {
	Node *temp;
	temp = head;
	head = temp->GetNext();
	delete temp;
	cout<<"Node deleted successfully\n";
}

void List::DeleteBack() {
	Node *temp,*previous;
	temp = head;
	
	if(temp == NULL)
		return;

	if(temp->GetNext() == NULL) {
		delete temp;
		head = NULL;
		return;
	}

	while(temp->GetNext() != NULL) {
		previous = temp;
		temp = temp->GetNext();
	}
	delete tail;
	previous->SetNext(NULL);
	tail = previous;
}

void List::DeleteBetween(Node *item) {
	Node *temp;
	temp = head;
	
	while(temp->GetNext() != item)
		temp = temp->GetNext();

	temp->SetNext(item->GetNext());
	delete item;
}

void List::DeleteNode(int item) {
	Node *temp = Find(item);

	if(temp == NULL)
		cout<<"Item is not in the list\n";

	if(temp == head)
		DeleteFront();

	if(temp == tail)
		DeleteBack();
	else
		DeleteBetween(temp);
}

void List::ViewList() {
	if(head == NULL)
		cout<<"List is empty\n";
	else {
		cout<<"HEAD --> ";
		Node *temp;
		temp = head;
		while(temp != NULL) {
			cout<<temp->GetData()<<" --> ";
			temp = temp->GetNext();
		}
		cout<<"NULL\n";
	}
}
