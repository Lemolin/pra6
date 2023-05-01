#include"LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {
	if (len == 0) {
		head = nullptr;
		return;
	}

	head = new Node(array[0], nullptr);
	Node* curr = head;
	for (int i = 1; i < len; i++) {
		curr->link = new Node(array[i], nullptr);
		curr = curr->link;
	}

}

LinkedList::~LinkedList() {
	Node* curr = head;
	while (curr != nullptr) {
		Node* next = curr->link;
		delete curr;
		curr = next;
	}
}


void LinkedList::insertPosition(int pos, int NewNum) {
	if (pos == 0) {
		head = new Node(NewNum, head);
	}
	Node* curr = head;
	for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
		curr = curr->link;
	}
	if (curr == nullptr) {
		Node* newNode = new Node(NewNum, nullptr);
		curr = head;
		while (curr->link != nullptr) {
			curr = curr->link;
		}
		curr->link = newNode;
	}
	else {
		Node* newNode = new Node(NewNum, curr->link);
		curr->link = newNode;
	}
	
}

bool LinkedList::deletePosition(int pos) {
	if (head == nullptr) {
		return false;
	}

	if (pos == 1) {
		Node* temp = head;
		head = head->link;
		delete temp;
		return true;
	}
	int i = 1;
	Node* curr = head;
	while (i < pos - 1 && curr != nullptr) {
		curr = curr->link;
		i++;
	}
	if (curr == nullptr || curr->link == nullptr) {
		
		return false;
	}
	Node* temp = curr->link;
	curr->link = curr->link->link;
	delete temp;
	return true;

}

int LinkedList::get(int pos) {
	if (head == nullptr) {
		return -1;
	}
	Node* curr = head;
	for (int i = 1; i < pos && curr != nullptr;i++) {
		curr = curr->link;
	}
	if (curr == nullptr) {
		return -1;
	}
	return curr->data;
}
