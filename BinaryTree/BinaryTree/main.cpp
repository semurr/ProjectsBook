#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;

};

void printInorder(Node*);
void printPreorder(Node*);
void printPostorder(Node*);


int main()
{
	int value;
	Node *Head;
	Node *Traverse;
	int loop_count = 10;
	

	
	cout << "Populate the tree" << endl;



	for(int i = 0; i < loop_count; i++)
	{
		//if no nodes are present creat new one and set head to it.
		if(i == 0)
		{
			cout << "What number do you want to add?: ";
			cin >> value;
			Head = new Node();
			Head->data = value;			
		}

		cout << "What number do you want to add?: ";
		cin >> value;

		bool entered = false;
		Traverse = Head;

		do
		{
			//if the node value is greater than entered value, assing entered value to the left node
			if(Traverse->data > value)
			{
				if(Traverse->left)
				{
					Traverse = Traverse->left;
				}
				else
				{
					Node *Enter = new Node();
					Enter->data = value;
					Traverse->left = Enter;
					entered = true;
				}
			}
			else
			{
				if(Traverse->right)
				{
					Traverse = Traverse->right;
				}
				else
				{
					Node *Enter = new Node();
					Enter->data = value;
					Traverse->right = Enter;
					entered = true;
				}
			}
		}
		while(entered == false);
	}

	//display tree inorder LNR
	cout << "Print inorder " << endl;
	printInorder(Head);
	
	cout << "\nPrint preorder " << endl;
	printPreorder(Head);

	cout << "\nPrint postorder " << endl;
	printPostorder(Head);

	
	cin >> value;

	return 0;
}

void printInorder(Node* node)
{
	if(node == NULL)
		return;
	printInorder(node->left);
	cout << node->data;
	printInorder(node->right);
}

void printPreorder(Node* node)
{
	if(node == NULL)
		return;
	cout << node->data;
	printInorder(node->left);
	printInorder(node->right);
}
void printPostorder(Node* node)
{
	if(node == NULL)
		return;
	printInorder(node->left);
	printInorder(node->right);
	cout << node->data;
}