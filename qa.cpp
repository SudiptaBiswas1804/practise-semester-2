#include <iostream>
using namespace std;
#define MAX_SIZE 101

class queue{
	int arr[MAX_SIZE];
	int front, rear;
	public:queue(){
	front=0;
	rear=-1;
	}
	
void add(int n){
	if(rear==MAX_SIZE-1){
		return;
	}
	else{
		arr[++rear]=n;
	}
}

void deletion(){
	if(rear<front){
		return ;
	}
		front++;
}

void display(){
	for(int i=front; i<=rear; i++){
		cout<<arr[i]<<"->";
	}
	cout<<"NULL"<<endl;
}
};

int main(){
	queue q;
	q.add(1);
	q.add(2);
	q.add(3);
	q.add(4);
            q.display();
	q.deletion();
	q.display();
}
