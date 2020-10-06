#include <bits/stdc++.h>
using namespace std;

//Create a simple binary tree with depth first traversals for display

//tree node
class Tnode {

	int data;
	Tnode *left;
	Tnode *right;
	friend class Tree;

};

//tree
class Tree {

	Tnode *Root; //root of the tree
	public :
		Tree(){
			Root=NULL;
		}
		Tnode* getRoot();
		Tnode* create();
		void InOrder(Tnode*);
		void PreOrder(Tnode*);
		void PostOrder(Tnode*);
};

//returns root of the tree
Tnode* Tree :: getRoot() {
	return Root;
}

//creates binary tree dynamically
Tnode* Tree :: create() {

	Tnode* temp;
	int data;

	cout << "\n\tEnter data for node(-1 if NULL) : ";
	cin >> data;

	if(data==-1) return NULL;

	temp = new Tnode;
	temp->data = data;
	cout << "\n\tEnter left child of node " << data << " : ";
	temp->left = create();
	cout << "\n\tEnter right child of node " << data << " : ";
	temp->right = create();

	return temp;
}

//Depth First Search Traversals

//inorder traversal
void Tree :: InOrder(Tnode* t) {

	if(t!=NULL) {
		InOrder(t->left);
		cout << "\t" << t->data;
		InOrder(t->right);
	}

}

//preorder traversal
void Tree :: PreOrder(Tnode* t) {

	if(t!=NULL) {
		cout << "\t" << t->data;
		PreOrder(t->left);
		PreOrder(t->right);
	}

}

//postorder traversal
void Tree :: PostOrder(Tnode* t) {

	if(t!=NULL) {
		PostOrder(t->left);
		PostOrder(t->right);
		cout << "\t" << t->data;
	}

}

int main() 
{
	Tree tree;
	Tnode* Root;
	Root = tree.getRoot();
	Root = tree.create();

	//left->root->right
	cout << "\n\t=========================INORDER TRAVERSAL========================\n";
	tree.InOrder(Root);
	cout << "\n\t==================================================================\n";

	//root->left->right
	cout << "\n\t=========================PREORDER TRAVERSAL=======================\n";
	tree.PreOrder(Root);
	cout << "\n\t==================================================================\n";

	//left->right->root
	cout << "\n\t=========================POSTORDER TRAVERSAL======================\n";
	tree.PostOrder(Root);
	cout << "\n\t==================================================================\n";

	return 0;
}

/*
sakshee@sakshee-Vostro-3580:~/Data Structures$ ./a.out

	Enter data for node(-1 if NULL) : 1

	Enter left child of node 1 : 
	Enter data for node(-1 if NULL) : 2

	Enter left child of node 2 : 
	Enter data for node(-1 if NULL) : 3

	Enter left child of node 3 : 
	Enter data for node(-1 if NULL) : -1

	Enter right child of node 3 : 
	Enter data for node(-1 if NULL) : -1

	Enter right child of node 2 : 
	Enter data for node(-1 if NULL) : 4

	Enter left child of node 4 : 
	Enter data for node(-1 if NULL) : -1

	Enter right child of node 4 : 
	Enter data for node(-1 if NULL) : -1

	Enter right child of node 1 : 
	Enter data for node(-1 if NULL) : 5

	Enter left child of node 5 : 
	Enter data for node(-1 if NULL) : 6

	Enter left child of node 6 : 
	Enter data for node(-1 if NULL) : -1

	Enter right child of node 6 : 
	Enter data for node(-1 if NULL) : -1

	Enter right child of node 5 : 
	Enter data for node(-1 if NULL) : -1

	=========================INORDER TRAVERSAL========================
	3	2	4	1	6	5
	==================================================================

	=========================PREORDER TRAVERSAL=======================
	1	2	3	4	5	6
	==================================================================

	=========================POSTORDER TRAVERSAL======================
	3	4	2	6	5	1
	==================================================================

*/
