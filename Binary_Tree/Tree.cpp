#include <iostream>


//стркутура дерева
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) : data(value), right(nullptr), left(nullptr) {}
};

//вспомогательная функция создания узла
TreeNode* make_new(int value) {
	return new TreeNode(value);
}

//итеративное создание
TreeNode* in_iterate(TreeNode* root, int value) {
	TreeNode* newNode = make_new(value);
	if (!root) {
		return make_new(value);
	}

	TreeNode* current = root;
	while (true) {
		if (value < current->data) {
			if (!current->left) {
				current->left = newNode;
				break;
			}
			current = current->left;
		}
		else if (value > current->data) {
			if (current->right) {
				current->right = newNode;
				break;
			}
			current = current->right;
		}
		else {
			delete newNode;
			break;
		}
	}
	return root;
}


//рекурсивное создание
TreeNode* in_recursive(TreeNode node, int value) {
	if (!node) {
		make_new(value);
	}

	if (value < node->data) {
		node->left = in_recursive(node->left, value);
	}
	else if (value > node->data) {
		node->right = in_recursive(node->right, value);
	}
	return node;
}

//поиск узла
bool search_node(TreeNode* root, int value) {
	if (!root) return false;
	if (root->data == value) return true;

	if (value < root->data) {
		return search_node(root->left, value);
	}
	else {
		return searc_node(root->right, value);
	}
}
