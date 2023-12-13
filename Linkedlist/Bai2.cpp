#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

struct LinkedList {
	Node *head;
};

Node* createNode(int d) {
	Node* node = new Node;
	node->data = d;
	node->next = NULL;
	return node;
}

void createList(LinkedList& l) {
	l.head = NULL;
}

void addHead(LinkedList& l, Node *node) {
	if(l.head == NULL) {
		l.head = node;
	} else {
		node->next = l.head;
		l.head = node;
	}
		
}

void printList(LinkedList l) {
	if(l.head != NULL) {
		Node* node = l.head;
		while (node != NULL) {
			cout << node->data << " ";
			node = node->next;
		}
	}
}

int main() {
	LinkedList list;
	createList(list);
	
	addHead(list, createNode(1)); 
	addHead(list, createNode(2)); 
	addHead(list, createNode(3)); 
	
	printList(list);
	return 0;
}
