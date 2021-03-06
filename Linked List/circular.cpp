#include <iostream>
using namespace std;

/*
Insert
======
1. Create new node
2. Put value in new node
3. Be the "next" of this->head
4. the new node becomes this->head
*/
class Node{
public:
	int value;
	Node * next;
	Node * prev;
};

class List{
public:
	bool insert_head(int value){
		Node * node = new Node;

		if(node){
			node->value = value;
			node->next = this->head;
			this->head = node;
			if(!this->tail){
				this->tail = this->head;
			} else{
				this->tail->next = this->head;
			}
			this->count++;
		}
		return node;
	}

	bool insert_tail(int value){
		Node * node = new Node;
		if(node){
			node->value = value;
			node->next = this->tail;
			this->tail = node;
			if(!this->head){
				this->head = this->tail;
			} else{
				this->tail->next = this->head;
			}
			this->count++;
		}
		return node;
	}

	bool print(){
		Node * node = this->head;
		for (int i = 0; i < this->size(); ++i){
			cout << node->value << " ";
			node = node->next;
		}
		cout << endl;
	}

	size_t size(){
		return this->count;
	}


private:
	size_t count;
	Node * head;
	Node * tail;
};


bool print_node(Node * node){
	cout << node->value << " ";
}

int main(int argc, char const *argv[]){
	List * list = new List();
	for (int i = 0; i < 10; ++i){
		list->insert_head(i);
	}

	list->insert_tail(69);



	cout << "=======================" << endl;
	cout << "Size : " << list->size() << endl;
	list->print();

	// cout << "=======================" << endl;
	// list->insert(123, 5);
	// cout << "Size : " << list->size() << endl;
	// list->print();


	// cout << "=======================" << endl;
	// list->replace(456, 5);
	// cout << "Size : " << list->size() << endl;
	// list->print();

	// cout << "=======================" << endl;
	// list->remove(5);
	// cout << "Size : " << list->size() << endl;
	// list->print();

	// cout << "=======================" << endl;
	// int value;
	// cout << "Value : " << list->read(value) <<endl;
	// cout << "Size : " << list->size() << endl;
	// list->print();

	// cout << "=======================" << endl;
	// list->reverse();
	// cout << "Size : " << list->size() << endl;
	// list->print();	
	// list->head_prev();

	// cout << "=======================" << endl;
	// list->destroy();
	// cout << "Size : " << list->size() << endl;
	// list->print();

	delete list;
	return 0;
}