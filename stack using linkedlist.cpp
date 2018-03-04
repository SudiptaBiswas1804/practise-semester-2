//Programme for implementation of stack using linked list method and performing push and pop function
#include <iostream>
using namespace std;

//Constuction of the node structure
struct node{
int data;
node *next;
node *prev;
}; 

//Stack Class
class stack{
private:
node *top;
public:
stack(){
top==NULL;	
}

//Push function - function used for adding node at the top
void addnode(int n){
node *temp=new node;
temp->data=n;
temp->next=NULL;
if(top==NULL){
top=temp;
}
else{
top->next=temp;
temp->prev=top;
top=temp;
}
}

//Display function - function used for displaying all the elements of the stack
void displaynode() {
node *temp;
temp=top;
if(top==NULL){
cout<<"The stack is empty"<<"\n";
}
else {
while(temp->prev!=NULL){
cout<<temp->data<<"->";
temp=temp->prev;
}
}
cout<<"NULL"<<endl;
}

//Pop function - function used for deleting a node from the top
void deletenode(){
node *temp=new node;
temp=top;
top=top->prev;
delete temp;
}
};

//Main function
int main(){
int n;
stack s;
s.addnode(1);
s.addnode(2);
s.addnode(3);
s.addnode(4);
s.addnode(5);
s.displaynode();
s.deletenode();
cout<<"The stack after popping the top element"<<endl;
s.displaynode();
return 0;
}
