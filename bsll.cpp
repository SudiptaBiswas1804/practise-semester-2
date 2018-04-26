#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
	};
	
	class linkedlist{
		private:
		node* head;
		node* tail;
		int size;
		public:
		linkedlist(){
		head=NULL;
		tail=NULL;
	}
	
	void addnode(int n){
		node* temp=new node;
		temp->data=n;
		temp->next=NULL;
		if(head==NULL){
			head=temp;
		}
		else{
			tail->next=temp;
			
		}
		temp->next=NULL;
		tail=temp;
	}
	
	void insertnode(int n1,int pos){
		node* cur=new node;
		node* prev=new node;
		node* temp=new node;
		temp->data=n1;
		temp->next=NULL;
		cur=head;
		for(int i=1; i<pos; i++){
			prev=cur;
			cur=cur->next;
			}
			prev->next=temp;
			temp->next=cur;
			}
			
	int countnode(){
		int length=0;
		node* temp=new node;
		temp=head;
		while(temp!=NULL){
			length++;
			temp=temp->next;
		}
		return length;
		cout<<length;
	}		
	
	void display(){
		node* temp=new node;
		temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;

	}
	
	void deleteat(int pos2){
		node* temp=new node;
		node* cur=new node;
		node* prev=new node;
		cur=head;
		for(int i=1; i<pos2; i++){
			prev=cur;
			cur=cur->next;
			temp=cur->next;
		}
		prev->next=temp;
		delete cur;
		
	}
	

	int bubblesort(int n){
		node* cur=new node;
		node* p=new node;
		for(int i=0; i<n; i++){
			p=head;
			for(int j=0; j<(n-i)-1; j++){
				if(p->data>p->next->data){
					cur->data=p->data;
					p->data=p->next->data;
					p->next->data=cur->data;
				}
				p=p->next;
			}
		}
		return 0;
	}
	};
	
	int main(){
		linkedlist l;
		l.addnode(1);
		l.addnode(22);
		l.addnode(6);
		l.addnode(24);
        l.insertnode(7,3);
        int k=l.countnode();
        cout<<k;
                cout<<endl;

        l.display();
        l.deleteat(4);
        l.display();
        int n=l.countnode();
        l.bubblesort(n);
        l.display();
        return 0;
	}
