#include <iostream>
#include <cstdint>

struct Node {
    Node* xor_ptr;
    int data;

    Node(int val) : data(val), xor_ptr(nullptr) {}
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

void print_iterate_forward(Node* head) {
    Node* current = head;
    Node* prev = nullptr;
    Node* next;

    std::cout << "List (forward): ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        next = XOR(prev, current->xor_ptr);
        prev = current;
        current = next;
    }
    std::cout << std::endl;
}

void print_iterate_backward(Node* head) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    // Находим хвост списка
    Node* current = head;
    Node* prev = nullptr;
    Node* next;

    while (current != nullptr) {
        next = XOR(prev, current->xor_ptr);
        if (next == nullptr) break;
        prev = current;
        current = next;
    }

    // Теперь current указывает на хвост
    std::cout << "List (backward): ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        Node* temp = XOR(next, current->xor_ptr);
        next = current;
        current = temp;
    }
    std::cout << std::endl;
}

void print_recursive_helper(Node* curr, Node* prev) {
    if (curr == nullptr) return;

    std::cout << curr->data << " ";
    Node* next = XOR(prev, curr->xor_ptr);
    print_recursive_helper(next, curr);
}

void print_recursive(Node* head) {
    std::cout << "List (recursive forward): ";
    print_recursive_helper(head, nullptr);
    std::cout << std::endl;
}

void delete_recursive_helper(Node* curr, Node* prev) {
    if (curr == nullptr) return;

    Node* next = XOR(prev, curr->xor_ptr);
    delete curr;
    delete_recursive_helper(next, curr);
}

void delete_recursive(Node*& head) {
    delete_recursive_helper(head, nullptr);
    head = nullptr;
    std::cout << "List deleted (recursive)" << std::endl;
}

void delete_iterate(Node*& head) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        Node* next = XOR(prev, current->xor_ptr);
        delete current;
        prev = current;
        current = next;
    }
    head = nullptr;
    std::cout << "List deleted (iterative)" << std::endl;
}




int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    std::cout << "Creating list iteratively (enter numbers, 0 to stop):" << std::endl;
    list1 = create_iterate();
    print_iterate_forward(list1);
    print_iterate_backward(list1);


    delete_iterate(list1);

    std::cout << "\nCreating list recursively (enter numbers, 0 to stop):" << std::endl;
    list2 = create_recursive();
    print_recursive(list2);

    delete_recursive(list2);

    // Проверка, что список действительно удален
    std::cout << "\nAfter deletion:" << std::endl;
    print_iterate_forward(list2);

    return 0;
}
