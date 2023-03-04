class Node {
public:
	int datum;
	Node *left, *right, *parent;
	Node(int);
};

class Heap {
	Node *tail, *root;
	void destr_helper(Node*);
	void upheap();
	void downheap();
	Node* smaller_child(Node*);
public:
	Heap();
	~Heap();
	bool is_empty();
	int peek();
	void push(int);
	int pop();
};
