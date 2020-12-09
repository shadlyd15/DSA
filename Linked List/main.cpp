#include <iostream>
using namespace std;

/*
Insert
======
1. Create new node
2. Put value in new node
3. Be the "next" of head
4. the new node becomes head
*/
class Node{
public:
	int value;
	Node * next;	
};

class List{
public:
	bool insert(int value){
		Node * node = new Node();
		if (node){
			node->value = value;
			node->next = this->head;
			this->head = node;
		}
		return node;
	}

	bool read(){

	}

	bool remove(){

	}

	bool print(){
		Node * node = head;
		while(node){
			cout << node->value << endl;
			node = node->next;
		} 
	}

	bool is_empty(){

	}

private:
	size_t size;
	Node * head, tail;
};

int main(int argc, char const *argv[]){
	List * list = new List();
	for (int i = 0; i < 10; ++i){
		list->insert(i);
	}

	list->print();
	// cout << "test" << endl;
	return 0;
}