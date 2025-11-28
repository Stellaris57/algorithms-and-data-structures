#include <iostream>
#include <cstdint>

struct Node {
	Node* xor_ptr;
	int data;

	Node(int val) : data(val), xor_ptr(nullptr){}
};

Node* XOR(Node* a, Node* b) {
	return (Node*)((uintptr_t)a ^ (uintptr_t)b);
}

Node* create_recursive() {
	int buffer = 1;
	std::cin >> buffer;
	if (buffer == 0) {
		return nullptr;
	}

	Node* new_node = new Node(buffer);
	Node* next_node = create_recursive();

	new_node->xor_ptr = XOR(nullptr, next_node);
	if (next_node != nullptr) {
		Node* next_next = XOR(nullptr, next_node->xor_ptr);
		next_node->xor_ptr = XOR(new_node, next_next);
	}

	return new_node;
}

Node* create_iterate() {
	Node* head = nullptr;
	Node* tail = nullptr;
	Node* prev = nullptr;
	int buffer = 1;

	while (buffer) {
		std::cin >> buffer;
		if (buffer == 0) break;

		Node* new_node = new Node(buffer);
		if (head == nullptr) {
			head = tail = new_node;
			new_node->xor_ptr = XOR(nullptr, nullptr);
		}
		else {
			tail->xor_ptr = XOR(prev, new_node);
			new_node->xor_ptr = XOR(tail, nullptr);
			prev = tail;
			tail = new_node;
		}
	}
	return head;
}
