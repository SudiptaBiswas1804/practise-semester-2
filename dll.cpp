#include <iostream>
using namespace std;

//Construction of the node structure
struct node{
int data;
node *prev;
node *next;
};

//Linked list class
class linkedList{
private:
node *head,*tail;
public:
linkedList(){
head = NULL;
tail = NULL;
}

//Addition function - function for adding a node at the end
void addnode(int n){
node *temp = new node;
temp->data = n;
if(head==NULL){
head = temp;
tail = temp;
temp->next = NULL;
temp->prev = NULL;
}
else {
tail->next = temp;
temp->prev = tail;
temp->next = NULL;
tail = temp;
}
}

//Display function - function used for displaying the elements of the linked list
void displaynode(){
node *temp;
temp=head;
cout<<"The elements of the linked list are : "<<"\n";
while(temp!=NULL){
cout<<temp->data<<"->";
temp=temp->next;
}
cout<<"NULL"<<"\n";
}

//Counting function - function for counting the number of elements in the linked list
int countnode(){
node *temp;
temp=head;
int length=0;
if (head==NULL){
cout<<"The list is empty"<<"\n";
}
else if(head!=NULL){
while(temp!=NULL) {
length++;
temp=temp->next;
}
cout<<"The number of elements in the linkedlist are : "<<length<<"\n";
}
return length;
}

//Insertion function - function for inserting a node at a particular position
void insertnode(int pos1, int n2){
int count=1;
node *cur=new node;
node *pr=new node;
node *temp=new node;
temp->data=n2;
temp->prev=NULL;
temp->next=NULL;
cur=head;
if(countnode()>pos1){
while(count!=pos1){
pr=cur;
cur=cur->next;
cur->prev=pr;
count++;
}
temp->next=cur;
temp->prev=pr;
pr->next=temp;
cur->prev=temp;
}
else if(countnode()<pos1) {
cout<<"The node does not exist "<<endl;
}
}

//Deletion function - function for deleting a node at end
void deletenode() {
//If the linked list is empty
if (head==NULL){
cout<<"The list is empty"<<"\n";
}
//If the linked list has only one node
else if(head==tail){
delete head;
head=NULL;
tail=NULL;
}
//If the linked list has more than one node
else {
node *temp,*cur;
temp=head;
cur=head->next;
cur->prev=head;
head=head->next;
delete temp;
head->prev=NULL;
}
}

//Delete function - function for deleting a node at any position
void deleteat(int pos2){
	node* temp=new node;
	node* cur=new node;
	node* pr=new node;
	cur=head;
	for(int i=1; i<pos2; i++){
		pr=cur;
		cur=cur->next;
		cur->prev=pr;
		temp=cur->next;
	}
	pr->next=temp;
	temp->prev=pr;
	delete cur;
}
}; 

//Main function for the programme
int main() {
int n2,pos1,pos2;
linkedList l;
l.addnode(1);
l.addnode(2);
l.addnode(3);
l.addnode(4);
l.addnode(5);
l.displaynode();
l.countnode();
cin>>pos1>>n2;
l.insertnode(pos1,n2);
cout<<"After the insertion of the node at "<<pos1<<" with the value of "<<n2<<" : "<<endl;
l.displaynode();
l.deletenode();
cout<<"After the deletion of the node at the end : "<<endl;
l.displaynode();
cin>>pos2;
l.deleteat(pos2);
cout<<"After the deletion of the node at "<<pos2<<" : "<<endl;
l.displaynode();
return 0;
}
