#ifndef NODE_H
#define NODE_H

class Node {
	friend class LinkedList;
public:
	Node(int data,Node*link);
private:
	int data;
	Node* link;

};



#endif
