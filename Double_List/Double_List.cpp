#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;

	Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};


//
Node* create_recursive() {
	int buffer;
	std::cin >> buffer;
	if (buffer == 0) {
		return nullptr;
	}

	Node* new_node = new Node(buffer);
	new_node->next = create_recursive();

	if (new_node->next != nullptr) {
		new_node->next->prev = new_node;
	}
	return new_node;
}


//
Node* create_iterate() {
	Node* head = nullptr;
	Node* tail = nullptr;
	int buffer = 1;

	while (buffer) {
		std::cin >> buffer;
		if (buffer == 0) break;
		Node* new_node = new Node(buffer);

		if (head == nullptr) {
			head = tail = new_node;
		}
		else {
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
		}
	}
	return head;
}


//
void print_recursive(Node* node) {
	if (node == nullptr) {
		return;
	}
	std::cout << node->data << " ";
	print_recursive(node->next);
}


//
void print_iterate_forward(Node* head) {
	Node* current = head;

	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->next;
	}
}


//
void print_iterate_backward(Node* head) {
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->prev;
	}
}


//
void delete_recursive(Node* node) {
	if (node == nullptr) {
		return;
	}

	delete_recursive(node->next);
	delete node;
}


//
void delete_iterate(Node* head) {
	Node* current = head;

	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
}

