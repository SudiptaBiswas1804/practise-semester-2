#include <iostream>
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
	void heapify(int i);
	void heapsort();
	void show();
};

Maxheap::Maxheap(int cap){
	hlength=0;
	size=cap;
	arr=new int[cap];
}

void Maxheap::insert(int key){
	if(hlength==size){
		return ;
	}
	else{
		hlength++;
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
	arr[0]=arr[hlength-1];
	hlength--;
	heapify(0);
}

void Maxheap::heapify(int i){
	if(left(i)==hlength && right(i)==hlength){
		return;
	}
  while(left(i)<hlength){
         if(right(i)==hlength){
                  if(arr[left(i)]>arr[i]){
                        swap(arr[left(i)],arr[i]);
                        i=left(i);
                   }
                   break;
         }
       
        else if(right(i)<hlength){
              if(arr[left(i)]>arr[right(i)]){
                   if(arr[left(i)]>arr[i]){
                         swap(arr[left(i)],arr[i]);
                         i=left(i);
                    }
              }
              else if(arr[right(i)]>arr[left(i)]){
                    if(arr[right(i)]>arr[i]){
                    	swap(arr[right(i)],arr[i]);
                    	i=right(i);
                    }
              }
        }
  }
}

void Maxheap::heapsort(){
	for(int i=0; i<hlength; i++){
		heapify(0);
	}
	
	for(int i=hlength-1; i<hlength; i--){
		swap(arr[0],arr[i]);
	            hlength--;
	            heapify(0);
	}
	
}
 	
int main(){
	Maxheap h(100);
	h.insert(4);
            h.insert(3); 
            h.insert(6);
            h.insert(2);
            h.insert(5);
            h.insert(20);
            h.insert(45);
            h.insert(33);
            h.insert(7);
            h.show();
            h.deletion();
            cout<<endl;
            h.show();
            h.heapsort();
            cout<<endl;
            h.show();
            return 0;
}
