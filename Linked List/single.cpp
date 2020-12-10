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
		if(n > this->size()) return false;

		Node * node_n = this->head;
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
		if(n > this->size() - 1) return false;
		Node * node_n = this->head;
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
		Node * node = this->head;
		if(node){
			value = node->value;
			this->head = head->next;
			ret_val = true;
			delete node;
			this->count--;
		}
		return ret_val;
	}

	bool remove(size_t n){
		if(n > this->size() - 1) return false;
		if(!n) {
			int value;
			return this->read(value);
		}

		bool ret_val = false;
		Node * node_left = this->head;
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

	bool reverse(){
		Node * current = this->head;
		Node * next = NULL;
		Node * prev = NULL;

		while(current){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	bool print(){
		Node * node = this->head;
		while(node){
			cout << node->value << " ";
			node = node->next;
		} 
		cout << endl;
	}

	bool destroy(){
		bool ret_val = false;
		size_t size = this->size();
		for (int i = 0; i < size; ++i){
			int value;
			this->read(value);
		}
		ret_val = true;
		this->count = 0;
		this->head = NULL;
		return ret_val;
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

	cout << "=======================" << endl;
	// list->destroy();
	// size_t elements = list->size();
	// for (int i = 0; i < elements; ++i){
	// 	int value;
	// 	list->read(value);
	// 	cout << value << " ";
	// }
	// cout << endl;

	list->reverse();
	cout << "Size : " << list->size() << endl;
	list->print();

	delete list;
	return 0;
}