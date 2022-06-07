#include <iostream>

using namespace std;

typedef int Info;
struct Node
{
	Node* left,
		* right;
	Info info;
	char ch;
};

Node* CreateTree(int nodeCount);
void PrintTree(Node* root, int level);
Info InfixOrder(Node* root, Info& min, char& ch);

int main()
{
	char ch;
	int N, min = INT_MAX;
	cout << "Enter nodes count: "; cin >> N;
	Node* root = CreateTree(N);
	cout << endl;
	PrintTree(root, 0);
	cout << "Infix search: ";
	InfixOrder(root, min, ch);
	cout << endl << min << ch << endl;
	return 0;
}

Node* CreateTree(int nodeCount)
{
	if (nodeCount == 0)
		return NULL;
	else
	{
		Node* newNode = new Node;

		cout << " Enter node value: ";
		cin >> newNode->info;
		cout << " Enter node symbol: ";
		cin >> newNode->ch;

		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount);
		newNode->right = CreateTree(rightCount);
		return newNode;
	}
}

void PrintTree(Node* root, int level)
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << "   ";
		cout << root->info;
		cout << root->ch << endl;
		PrintTree(root->left, level + 1);
	}
}

Info InfixOrder(Node* root, Info& min, char& ch)
{
	if (root != NULL)
	{
		InfixOrder(root->left, min, ch);
		cout << root->info << "";
		cout << root->ch << "   ";
		InfixOrder(root->right, min, ch);
		if (root->info <= min) {
			min = root->info;
			ch = root->ch;
		}
	}
	return ch;
}