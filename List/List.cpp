#include <iostream>

struct Node {
	Node* next;
	int data;

	Node(int val) : data(val), next(nullptr) {}
};


//создание рекурсивно
Node* create_recursive(int* values, int size, int index) {
	if (index >= size) { return nullptr; }
	Node* new_node = new Node(values[index]);
	new_node->next = create_recursive(values, size, index + 1);
	return new_node;
}


//создание итеративно
Node* create_iterate(int* values, int size) {
	if (size == 0) { return nullptr; }

	Node* head = new Node(values[0]);
	Node* current = head;
	for (int i = 1; i < size; i++) {
		Node* new_node = new Node(values[i]);
		current->next = new_node;
		current = new_node;
	}
	return head;
}


//вывод рекурсивно
void print_recursive(Node* current) {
	if (current == nullptr) {
		std::cout << std::endl;
		return;
	}

	std::cout << current->data << " ";
	print_recursive(current->next);
}



//вывод нерекурсивно
void print_iterate(Node* head) {
	Node* current = head;
	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}



//удаление элемента рекурсивно
void pop_recursive(Node* current) {
	if (current == nullptr) {
		return;
	}
	pop_recursive(current->next);
	delete current;
}



//удаление элемента итеративно
void pop_iterate(Node*& head) {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}




int main() {
	int values[] = { 1, 2, 3, 4, 5, 9, 8, 7, 6, 5 };
	int size = sizeof(values) / sizeof(values[0]);

	std::cout << "Создание рекурсивно:" << std::endl;
	Node* head1 = create_recursive(values, size, 0);
	print_recursive(head1);

	std::cout << "Создание итеративно:" << std::endl;
	Node* head2 = create_iterate(values, size);
	print_iterate(head2);

	std::cout << "Вывод рекурсивно:" << std::endl;
	print_recursive(head1);

	std::cout << "Вывод итеративно:" << std::endl;
	print_iterate(head2);

	// Удаление
	pop_recursive(head1);
	pop_iterate(head2);

	return 0;
}
