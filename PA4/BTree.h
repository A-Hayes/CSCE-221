#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum color {red, black};

template <typename T>
struct Node 
{
	T value;
	Node<T>* left;
	Node<T>* right;
    Node<T>* parent;

    int search_time;
    color node_color; //don't need to worry about this for the regular BTree

    Node(T val = T(), Node<T>* l = NULL, Node<T>* r = NULL, Node<T>* p = NULL, color col = color::red)
		: value(val), left(l), right(r), parent(p), search_time(0), node_color(col) {}

	Node(const Node<T>* other)
	{
		value = other->value;
		node_color = other->node_color;
		search_time = other->search_time;
	}

	bool is_leaf(){return (left == 0 && right == 0);}
};

template <typename T>
struct BTree
{
protected:
	int size;

public:
	Node<T>* root;

    BTree() : root(NULL),size(0){}
	BTree(const BTree<T>& other);
	BTree<T>& operator=(const BTree<T>& other);
	BTree<T>& operator=(const BTree<T> other);

	Node<T>* get_root(){return root;}
	const Node<T>* get_root() const {return root;}
	virtual Node<T>* insert(T obj);
	Node<T>* search(T obj);
	void update_search_times();
	float get_average_search_time();
    ostream& inorder(ostream& out);
    virtual ostream& print_level_by_level(ostream& out);

private:
	void copy_helper(Node<T>* copy_to, const Node<T>* copy_from) const;
	virtual Node<T>* insert_helper(T obj, Node<T>* node);
	Node<T>* search_helper(T obj, Node<T>* node);
	ostream& inorder_helper(ostream& out, Node<T>* node);
	void update_search_times_helper(Node<T>* node, int depth);
	int get_total_search_time(Node<T>* node);
	virtual void pretty_print_node(ostream& out,Node<T>* node);
};

template <typename T>
ostream& operator<<(ostream& out, BTree<T>& tree)
{
	return out;
}

template <typename T>
ostream& operator<<(ostream& out, Node<T> node)
{
	out << "( " << node.value << ", " << node.search_time << ", " << node.node_color << " )";
	return out;
}

template <typename T>
void BTree<T>::pretty_print_node(ostream& out,Node<T>* node)
{
	out << node->value << "["<<node->search_time<<"] ";
}

template <typename T>
istream& operator>>(istream& in, BTree<T>& tree)
{
	T value;
	in >> value;
	tree.insert(value);
	return in;
}

template <typename T>
BTree<T>::BTree(const BTree<T>& other)
{
    Node<T>* oldRoot = other.root;
		root = new Node<T>;
		copy_helper(root, oldRoot);
}

// Assumes tree being copied to is empty due to lack of delete fucntions
template <typename T>
BTree<T>& BTree<T>::operator=(const BTree<T>& other)
{
	copy_helper(other->root, root);
}

// Assumes tree being copied to is empty due to lack of delete fucntions
template <typename T>
BTree<T>& BTree<T>::operator=(const BTree<T> other)
{
	copy_helper(other->root, root);
}

template <typename T>
void BTree<T>::copy_helper(Node<T>* copy_to, const Node<T>* copy_from) const
{
	if(copy_from == nullptr || copy_from == copy_to){
		return;
	} else {
		copy_to->value = copy_from->value;
		copy_to->node_color = copy_from->node_color;

		if(copy_from->left != nullptr){
			copy_to->left = new Node<T>;
			copy_to->left->parent = copy_to;
			copy_helper(copy_to->left, copy_from->left);
		} else {
			copy_to->left = nullptr;
		}

		if(copy_from->right != nullptr){
			copy_to->right = new Node<T>;
			copy_to->right->parent = copy_to;
			copy_helper(copy_to->right, copy_from->right);
		} else {
			copy_to->right = nullptr;
		}
	}
}

template <typename T>
Node<T>* BTree<T>::insert_helper(T obj, Node<T>* curr)
{

	if(curr == nullptr){
		size++;
		return new Node<T>(obj);
	}
	
	if(obj == curr->value){
		return curr;
	}

	if(obj < curr->value) {
		Node<T>* leftNode = insert_helper(obj, curr->left);
		curr->left = leftNode;
		leftNode->parent = curr;
	} else {
		Node<T>* rightNode = insert_helper(obj, curr->right);
		curr->right = rightNode;
		rightNode->parent = curr;
	}
	return curr;
}

template <typename T>
Node<T>* BTree<T>::insert(T obj)
{
	if(root == nullptr){
		root = new Node<T>(obj);
		size = 1;
		return root;
	}

	Node<T>* node = insert_helper(obj, root);

	update_search_times();

  return node;
}

template <typename T>
Node<T>* BTree<T>::search_helper(T obj, Node<T>* node)
{
	if(obj == node->value){
		return node;
	}

	if(obj < node->value && node->left != nullptr) {
		return search_helper(obj, node->left);
	} else if(obj > node->value && node->right != nullptr) {
		return search_helper(obj, node->right);
	} else {
		return nullptr;
	}
}

template <typename T>
Node<T>* BTree<T>::search(T obj)
{
	if(obj == root->value){
		return root;
	} else if(obj < root->value) {
		return search_helper(obj, root->left);
	} else {
		return search_helper(obj, root->right);
	}
}

template <typename T>
void BTree<T>::update_search_times_helper(Node<T>* node, int depth)
{
	node->search_time = depth;

	if(node->left != nullptr){
		update_search_times_helper(node->left, depth+1);
	}

	if(node->right != nullptr){
		update_search_times_helper(node->right, depth+1);
	}
}

template <typename T>
void BTree<T>::update_search_times()
{
	update_search_times_helper(root, 0);
}

template <typename T>
ostream& BTree<T>::inorder_helper(ostream& out, Node<T>* node)
{
	if(node == nullptr){
		return out;
	}
  
  if(node == root){
    out << "In-order traversal: ";
  }
  
	inorder_helper(out, node->left);

	out << node->value << " ";

	inorder_helper(out, node->right);
}

template <typename T>
ostream& BTree<T>::inorder(ostream& out)
{
	if(size > 16){
    out << "Tree too large to print." << endl;
    return out;
  }
  return inorder_helper(out, root) << endl;
}

template <typename T>
ostream& BTree<T>::print_level_by_level(ostream& out)
{
	if(size > 16){
    out << "Tree too large to print." << endl;
    return out;
  }
  out << "Level-by-Level Traversal: " << endl;
  queue< Node<T>* > mainQ;
	int nodesLeft = 1;
	int nextLv = 0;
	if(root != nullptr){
		mainQ.push(root);
		out << root->value << endl;
	} else {
		return out;
	}

	while(!mainQ.empty()){
		Node<T>* temp = mainQ.front();
		mainQ.pop();

		if(temp->left != nullptr){
			mainQ.push(temp->left);
			out << temp->left->value << " ";
			nextLv++;
		} else {
			out << "X ";
			nextLv++;
		}

		if(temp->right != nullptr){
			mainQ.push(temp->right);
			out << temp->right->value << " ";
			nextLv++;
		} else {
			out << "X ";
			nextLv++;
		}

		nodesLeft--;

		if(nodesLeft == 0){
			out << endl;
			nodesLeft = nextLv;
			nextLv = 0;
		}
	}

  return out << endl;
}

// This function assumes node input from other functions is root
template <typename T>
int BTree<T>::get_total_search_time(Node<T>* node)
{
		if(node == nullptr){
			return 0;
		}

		return node->search_time + get_total_search_time(node->left) + get_total_search_time(node->right);
}

template <typename T>
float BTree<T>::get_average_search_time()
{
    float total = get_total_search_time(root);
    float treeSize = size;
    float avg = total / treeSize;
    return avg;
}
