// *********************************************************************************
// Singly-linked list and recursion
// ---------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------
// Matteo Girardi
// *********************************************************************************

#include <iostream>
#include <string>

using namespace std;

#define N_nodes 15

struct node {
	int x;
	node *next;
};

node* search(node* list, int vfind) {
	if (list==NULL) {
		return NULL;
	}
	if (list->x == vfind) {
		return list;
	}
	else {
		return search (list->next, vfind);
	}
}

node* insert(node* list, int n) {
	node * tmp = new node;
	if (list==NULL) {
		tmp->x = n;
		tmp->next = NULL;
		list = tmp;

	}
	else {
		tmp->x = n;
		tmp->next = NULL;
		node * cur = list;
		while (cur) {
			if (cur->next == NULL) {
				cur->next = tmp;
				return list;
				// break;
			}
			cur = cur->next;
		}
	}
	return list;
}

node* revert(node* list) {
	
}

void print(node* list) {
	node * tmp = list;
	while(tmp) {
		cout << tmp->x << endl;
		tmp = tmp->next;
	}
}

int main() {
	node * head = NULL;
	for (int i = 0; i<N_nodes; ++i) {
		head = insert(head, i);
	}
	print(head);
	node * find = NULL;
	find = search(head,5);
	print(find);
}