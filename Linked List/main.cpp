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
			this->count++;
		}
		return node;
	}

	bool insert(int value, size_t n){
		if(!n) return this->insert(value);

		Node * node_n = head;
		for (int i = 0; i < n - 1; ++i){
			node_n = node_n->next;
		}

		Node * node = new Node();
		if (node){
			node->value = value;
			node->next = node_n->next;
			node_n->next = node;
			this->count++;
		}
		return node_n;
	}


	bool replace(int value, size_t n){
		Node * node_n = head;
		for (size_t i = 0; i < n; ++i){
			node_n = node_n->next;
		}
		if (node_n){
			node_n->value = value;
		}
		return node_n;
	}

	bool read(int &value){
		bool ret_val = false;
		Node * node = head;
		if(node){
			value = node->value;
			head = node->next;
			ret_val = true;
			delete node;
			this->count--;
		}
		return ret_val;
	}

	bool remove(size_t n){
		if(!n) {
			int value;
			return this->read(value);
		}

		bool ret_val = false;
		Node * node_left = head;
		for (int i = 0; i < n - 1; ++i){
			node_left = node_left->next;
		}

		if (node_left){
			Node * node_n = node_left->next;
			node_left->next = node_n->next;
			if (node_n){
				ret_val = true;
				delete node_n;
				this->count--;
			}
		}
		return ret_val;
	}

	bool print(){
		Node * node = head;
		while(node){
			cout << node->value << " ";
			node = node->next;
		} 
		cout << endl;
	}

	bool is_empty(){

	}

	size_t size(){
		return count;
	}

private:
	size_t count;
	Node * head, tail;
};

int main(int argc, char const *argv[]){
	List * list = new List();
	for (int i = 0; i < 10; ++i){
		list->insert(i);
	}

	cout << "=======================" << endl;
	cout << "Size : " << list->size() << endl;
	list->print();

	cout << "=======================" << endl;
	list->insert(99, 0);
	cout << "Size : " << list->size() << endl;
	list->print();

	cout << "=======================" << endl;
	list->remove(0);
	cout << "Size : " << list->size() << endl;
	list->print();

	return 0;
}