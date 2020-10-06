#include <bits/stdc++.h>
using namespace std;


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
		int depth(Tnode*);
		void BreadthFirstDisplay(Tnode*);
		void printlevel(Tnode*, int);
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

//Breadth First Search Traversals

void Tree :: BreadthFirstDisplay(Tnode *Root)
{
	int i;
	if(Root!=NULL) {
		for(i=0;i<depth(Root);i++) {
			cout << "\n\tLevel " << i+1 << " : "; 
			printlevel(Root,i+1);
		}
	}
}

void Tree :: printlevel(Tnode *tempNode,int level)
{
	if(tempNode==NULL)
		return;
	if(level==1)
		cout << " " << tempNode->data << " ";
	else if(level>1) {
		printlevel(tempNode->left,level-1);
		printlevel(tempNode->right,level-1);
	}
}

int Tree :: depth(Tnode *tempNode)
{
	int dtl,dtr;
	if(tempNode==NULL)
		return 0;
	else {
		dtl = depth(tempNode->left)+1;
		dtr = depth(tempNode->right)+1;
	}
	if(dtl>dtr)
		return dtl;
	else
		return dtr;
}


int main() 
{
	Tree tree;
	Tnode* Root;
	Root = tree.getRoot();
	Root = tree.create();

	cout << "\n\tDEPTH OF GIVEN TREE : " << tree.depth(Root)-1;
	cout << endl;
	cout << "\n\tBREADTH FIRST DISPLAY OF THE TREE : " << endl;
	tree.BreadthFirstDisplay(Root);
	cout << endl;
	return 0;
}