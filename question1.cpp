// 1113568 Alice 2024.11.28

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
	int value;
	Node* left, * right;

	Node(int v) {
		value = v;
		left = nullptr;
		right = nullptr;
	}
};

class BinaryTree {
public:
	Node* root;
	int d;

	Node* Insert(vector<int> inp) {
		if (inp[0] == -1) return root;

		int i = 0;
		root = new Node(inp[i]);

		queue<Node*> q;
		q.push(root);

		while (i < inp.size()) {
			Node* current = q.front();
			q.pop();

			i++;
			if (i < inp.size() && inp[i] != -1) {
				current->left = new Node(inp[i]);
				q.push(current->left);
			}
			i++;
			if (i < inp.size() && inp[i] != -1) {
				current->right = new Node(inp[i]);
				q.push(current->right);
			}
		}
		return root;
	}

	void PrintBFS() {
		queue<Node*> q;
		q.push(root);

		while (!q.empty()) {
			Node* current = q.front();
			q.pop();

			cout << current->value << ' ';

			if (current->left != nullptr) {
				q.push(current->left);
			}
			
			if (current->right != nullptr) {
				q.push(current->right);
			}
		}
		cout << endl;
	}

	int DiameterDFS(Node* node, int& d) {
		if (node == nullptr) return 0;

		int leftD = DiameterDFS(node->left, d);
		int rightD = DiameterDFS(node->right, d);

		d = max(d, leftD + rightD);

		return 1 + max(leftD, rightD);
	}

	int Diameter() {
		int d = 0;
		DiameterDFS(root, d);
		return d;
	}
};

int main() {
	vector<int> inp;
	int s, tmp;
	cout << "The number of elements you want to enter: ";
	cin >> s;

	cout << "The elements:" << endl;
	for (int i = 0; i < s; i++) {
		cin >> tmp;
		inp.push_back(tmp);
	}

	BinaryTree T;
	T.Insert(inp);

	cout << "BFS traversal: ";
	T.PrintBFS();

	cout << "The number of the path in the tree: " << T.Diameter() << endl;
}
