#include <iostream>

template <typename T>
struct Queue {
	struct Node {
		T data;
		Node* next;
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	size_t _size = 0;

	T front() {
		return head->data;
	}

	void push(const T& value) {
		Node* new_node = new Node;
		new_node->data = value;
		if (head == nullptr) {
			this->head = new_node;
		}
		else {
			this->tail = new_node;
		}
		this->tail = new_node;
		this->_size++;
	}

	size_t size() {
		return this->_size;
	}

	void pop() {
		if (this->head == nullptr) {
			return;
		}
		Node* tmp = this->head;
		this->head = this->head->next;
		delete tmp;
		this->_size--;
	}

	void print_queue() {
		Node* current = this->head;
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
};


int main() {
	Queue<int> q;
	q.push(11);
	q.push(22);
	q.push(33);
	q.print_queue();
	
}
