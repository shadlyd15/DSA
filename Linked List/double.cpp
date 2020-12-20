#include <iostream>
using namespace std;

class Node{
public:
	int value;
	Node * next;
	Node * prev;	
};

class List{
public:

	bool insert_first(int value){
		Node * node = new Node;
		if(node){
			node->prev = NULL;
			node->value = value;
			node->next = this->head;
			if(this->head){
				this->head->prev = node;
			}

			this->head = node;
			this->count++;
		}
		return node;
	}

	bool insert_last(int value){
		Node * node = new Node;
		if(node){
			node->next = NULL;
			node->value = value;
			if(!this->head){
				this->head = node;
				node->prev = NULL;
			} else{
				Node * tail = this->head;
				while(tail->next){
					tail = tail->next;
				}
				tail->next = node;
				node->prev = tail;
			}

			this->count++;
		}
		return node;
	}

	bool delete_by_value(int value){
		Node * node = this->head;
		while(node->value != value){
			node = node->next;
		}

		node->next->prev = node->prev;
		node->prev->next = node->next;
		this->count--;
		delete node;
		return !node;
	}

	bool reverse(){

	}
	
	bool clear(){
		Node * node = this->head;
		while(node){
			this->head = node->next;
			delete node;
			node = this->head;
			this->count--;
		}
	}

	bool print(){
		Node * node = this->head;
		while(node){
			cout << node->value << " ";
			node = node->next;
		}
		cout << endl;
		return node;
	}

	bool print_reverse(){ 
	    Node * tail = this->head;
		while(tail->next){
			tail = tail->next;
		}
	 	
	 	cout << "Reverse : ";
	    while (tail){ 
	        cout << tail->value << " "; 
	        tail = tail->prev;
	    }
	    cout << endl;
		return tail;
	} 
	 
	size_t size(){
		return this->count;
	}

private:
	size_t count;
	Node * head;
};


bool print_node(Node * node){
	cout << node->value << " ";
}

int main(int argc, char const *argv[]){
	List * list = new List();
	list->insert_last(-1);
	for (int i = 0; i < 10; ++i){
		list->insert_first(i);
	}

	list->insert_last(69);


	cout << "=======================" << endl;
	cout << "Size : " << list->size() << endl;
	list->print();
	list->print_reverse();

	cout << "=======================" << endl;
	list->delete_by_value(3);
	cout << "Size : " << list->size() << endl;
	list->print();
	list->print_reverse();

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

	cout << "=======================" << endl;
	list->clear();
	cout << "Size : " << list->size() << endl;
	list->print();

	delete list;
	return 0;
}