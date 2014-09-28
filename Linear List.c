/* 
 *	C version of linked list program
 *	Basic funtionality-->
 *	Add node
 *	Delete node
 *	View list
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

node *head = NULL;
node *tail = NULL;
void add_node(int i);
void remove_node();
void view_list();

int main() {
	int num;
	int ch;
	
	while(1) {
		printf("This is linear list menu -->\n");
		printf("(1) Add node\n(2) Delete node\n(3) View list\n(4) Exit\n");
		printf("Choose option ... ");
		scanf("%d",&ch);
	
		switch(ch) {
			case 1: printf("Enter data : ");
					scanf("%d",&num);
					add_node(num);
					break;
			
			case 2: remove_node();
					break;
			
			case 3: view_list();
					break;
			
			case 4: exit(0);
		}
	}

	return 0;
}

void add_node(int i) {
	node *p;
	p = (node *)malloc(sizeof(node));
	p->data = i;
	printf("Data is added\n");
	p->next = NULL;

	if (head == NULL) {
		head = p;
		tail = p;
		printf("Executed\n");

	}
	else {
		tail->next = p;
		tail = p;
	}
}

void view_list() {
	if(head == NULL)
		printf("List is empty\n");
	else {
		node *temp;
		temp = head;
		while(temp != NULL) {
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void remove_node() {
	int temp;
	node *p;
	if(head == NULL) {
		printf("List is empty\n");
		return;
	}
	p = head;
	head = p->next;
	temp = p->data;
	printf("Deleted item is %d\n", temp);
	free(p);
	return;
}
