// Prakhar Pratyush
// pnation2020@gmail.com
// pnation @irc.oftc.net
//
// Level order tree traversal (breadth first traversal)
//
// Recursive implementation
//
///////////////////////////////////////////////////////////////////////////////////////////
//                                         [1]
//                                        /   \
//                                      [2]   [3]        level order traversal => 1-2-3-4-5
//                                      /        \
//                                    [4]         [5]
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

////////////////////////////////////////////////////////////////////////////////////////////

int height(Node* node)
{
	if(node == NULL) return 0;
	else
	{
		int l_height = height(node->left);
		int r_height = height(node->right);

        // total height = 1 + max height of its children
		return max(l_height+1, r_height+1); 
	}

}

////////////////////////////////////////////////////////////////////////////////////////////

void print_level(Node* root, int level)
{
	if(root == NULL) return;
	if(level == 1)  cout<<root->data<<" "<<endl; 
	else if(level > 1) 
	{
		print_level(root->left, level-1);
		print_level(root->right, level-1);
	}

}

void level_order(Node* root)
{
	int h = height(root);
	for(int i=1;i<=h;i++)     
	{
		print_level(root, i);
	}

}

///////////////////////////////////////////////////////////////////////////////////////////

Node* newNode(int x){
	Node* node = new Node();
	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout<<"level order traversal of given tree is :-"<<endl;

	level_order(root);

	return 0;
}



//////////////////////////@pnation inc..///////////////////////////////////////////////////////