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