#include<iostream>

#include <iomanip>

using namespace std;





template<class Item>
class binary_tree_node {
public:
	binary_tree_node(const Item& init_data = Item(), 
		binary_tree_node* init_left = NULL,
		binary_tree_node* init_right = NULL) {
		init_left = left_field;
		init_right = right_field;
	}
	Item& data() {
		return data_field;
	}
	const Item& data() const{
		return data_field;
	}
	binary_tree_node*& left() {
		return left_field;
	}
	const binary_tree_node* left() const {
		return left_field;
	}
	binary_tree_node*& right() {
		return right_field;
	}
	const binary_tree_node* right() const {
		return right_field;
	}

	void set_data(const Item& data) {
		data_field = data;
	}
	void set_left(binary_tree_node* node) {
		left_field = node;
	}
	void set_right(binary_tree_node* node) {
		right_field = node;
	}
	bool is_leaf()const {
		return (left_field == NULL && right_field == NULL);
	}
private:
	Item data_field;
	binary_tree_node* left_field;
	binary_tree_node* right_field;
};

template <class Item, class SizeType>
void print(const binary_tree_node<Item>* root_ptr,
	SizeType depth)
{
	if (root_ptr != NULL)
	{
		print(root_ptr->right(), depth + 1);
		cout << setw(4 * depth) << "" << root_ptr->data() << endl;
		print(root_ptr->left(), depth + 1);
	}
}

template<class Item>
void tree_clear(binary_tree_node<Item>*& node_ptr) {
	if (node_ptr != NULL) {
		tree_clear(node_ptr->left());
		tree_clear(node_ptr->right());
		delete node_ptr;
		node_ptr = NULL;
	}
}

template<class Item>
binary_tree_node<Item>* tree_copy(binary_tree_node<Item>* node_ptr) {
	binary_tree_node<Item>* l_ptr;
	binary_tree_node<Item>* r_ptr;

	if (node_ptr == NULL)
		return NULL;
	else {
		l_ptr = tree_copy(node_ptr->left());
		r_ptr = tree_copy(node_ptr->right());
		return new binary_tree_node(node_ptr->data(), l_ptr, r_ptr);
	}
}


int main() {
	binary_tree_node<int> node;
	binary_tree_node<int> r_node;
	binary_tree_node<int> l_node;


	node.set_data(5);
	r_node.set_data(1);
	l_node.set_data(3);
	node.set_left(&l_node);
	node.set_right(&r_node);
	print(&node, 0);
	return 0;
}