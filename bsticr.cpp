#include <iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
	node* parent;
};

class bst{
	node* root;
	int n=1;
	
	node* insert(int n, node* temp){
		if(temp==NULL){
			temp=new node;
			temp->data=n;
			temp->left=NULL;
			temp->right=NULL;
		}
			else if(temp->data>n){
				temp->left=insert(n,temp->left);
	                                    temp->left->parent=temp;
			}
			else if(temp->data<n){
				temp->right=insert(n,temp->right);
				temp->right->parent=temp;
			}
		
		return temp;
	}
	
	void inorder(node* temp){
		if(temp==NULL){
			return ;
		}
		else{
			inorder(temp->left);
			cout<<temp->data<<" ";
			inorder(temp->right);
		}
	}
	
int count(node* temp){
		if(temp==NULL){
			return n;
		}
		else{
			if(temp->left!=NULL){
				n=n+1;
				n=count(temp->left);
			}
			if(temp->right!=NULL){
				n=n+1;
				n=count(temp->right);
			}
			else if(temp->left==NULL || temp->right==NULL){
				n=n+0;
			}
		}
		return n;
	}
	
	void rangesearch(node* temp, int s1, int s2){
		if(temp==NULL){
			return ;
		}
		else{
			if(s1<temp->data){
				rangesearch(temp->left,s1,s2);
			}
			if(s2>temp->data){
				rangesearch(temp->right,s1,s2);
		}
		    if(s1<=temp->data && s2>=temp->data){
		    cout<<temp->data<<" ";
		    	
		    }
	}
}
 public:
bst(){
	root=NULL;
}

void insert(int n){
	root=insert(n,root);
}

void inorder(){
	inorder(root);
}

int count(){
	int n2=count(root);
	return n2;
}

void rsearch(int s1, int s2){
	rangesearch(root,s1,s2);
}
};

int main() {
	bst b;
	b.insert(2);
	b.insert(22);
	b.insert(32);
	b.insert(25);
	b.insert(24);
	b.inorder();
	cout<<endl;
    int n2=b.count();
    cout<<n2;
    cout<<endl;
    b.rsearch(22,32);
	return 0;
}
