#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
	node* prev;
};

class stack{
	private:
	node* top;
	public:stack(){
	top=NULL;
}

void addnode(int n){
	node* temp=new node;
	temp->data=n;
	temp->next=NULL;
	temp->prev=NULL;
	if(top==NULL){
		top=temp;
		temp->prev=NULL;
		temp->next=NULL;
            }
            else{
            	top->next=temp;
            	temp->prev=top;
            	temp->next=NULL;
            	top=temp;
            	
            }
}

void display(){
	node* temp=new node;
	temp=top;
	while(temp->prev!=NULL){
		temp=temp->prev;
	}
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
 
void deletion(){
	node* temp= new node;
	temp=top;
	top=top->prev;
	delete temp;
	top->next=NULL;
}
};

int main(){
	stack s;
	s.addnode(1);
	s.addnode(2);
	s.addnode(3);
	s.addnode(4);
            s.display();
            s.deletion();
            s.display();
            return 0;
}
