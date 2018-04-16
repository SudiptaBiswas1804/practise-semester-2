#include<iostream>
using namespace std;

void swap(int *x, int *y);
class Maxheap{
	int *arr;
	int size;
	int hlength;
	
	public:
	Maxheap(int size);
	int parent(int i){return (i-1)/2;}
	int left(int i){return 2*i+1;}
	int right(int i){return 2*i+2;}
	void insert(int key);
	void deletion();
	void heap(int i);
	void heapsort();
	void show();
};

Maxheap(int cap){
	hlength=0;
	size=cap;
	arr=new int[cap];
}

void Maxheap::insert(int key){
	if(hlength==size){
		return 0;
	}
	else{
		int i=hlength-1;
		arr[i]=key;
		while(arr[i]>arr[parent(i)]){
			swap(arr[i],arr[parent(i)]);
			i=parent(i);
		}
		}
}

void Maxheap::show(){
	for(int i=0; i<hlength; i++){
		cout<<arr[i]<<" ";
		}
}

void Maxheap::deletion(){
	if(arr[left(i)]==hlength && arr[right(i)]==hlength){
		return;
	}
	
}
