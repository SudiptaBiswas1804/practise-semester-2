#include <iostream>
using namespace std;

void swap(int *x, int *y);
class heap{
	public:
	int *arr;
	int hlength;
	int size;
	
	heap(int size);
	void insert(int key);
	int parent(int i){return (i-1)/2;}
	int left(int i){return 2*i+1;}
	int right(int i){return 2*i+2;}
	void deletion();
	void heapify(int *arr, int i);
	void heapsort();
	void display();
};

heap::heap(int cap){
	hlength=0;
	size=cap;
	arr= new int[cap];
}

void heap::insert(int key){
	if(hlength==size){
		return ;
	}
	else{
		hlength++;
		int i=hlength-1;
		arr[i]=key;
		while(arr[i]>arr[parent(i)]){
			swap(&arr[i],&arr[parent(i)]);
			i=parent(i);
		}
	}
}

void heap::display(){
	for(int i=0; i<hlength; i++){
		cout<<arr[i]<<" ";
	}		
	cout<<endl;
}

void heap::deletion(){
	int i=hlength-1;
	swap(&arr[0],&arr[i]);
	hlength--;
	heapify(arr,0);
}

void heap::heapify(int *arr, int i){
	//cout  << arr[hlength - 1] << "Hello"<< endl;
	if(left(i)==hlength){
		return;
	}
  while(left(i)<hlength){
         if(right(i)==hlength){
                  if(arr[left(i)]>arr[i]){
                        swap(&arr[left(i)],&arr[i]);
                        i=left(i);
                   }
                   break;
         }
 
        else if(right(i)<hlength){
        	// if (i > left and i > right) break;
              if(arr[left(i)]>arr[right(i)]){
                   if(arr[left(i)]>arr[i]){
                         swap(&arr[left(i)],&arr[i]);
                         i=left(i);
                    }
                    else
                    break;
              }
              else if(arr[right(i)]>arr[left(i)]){
                    if(arr[right(i)]>arr[i]){
                    	swap(&arr[right(i)],&arr[i]);
                    	//void swap(int *x, int *y);
                    	i=right(i);
                    }
                    else 
                    break;
              }
        }
  }
}


void heap:: heapsort(){
	heapify(arr,0);
            for(int i=hlength-1; i>0; i--){
                  swap(&arr[0],&arr[i]);
                  cout<<arr[i]<<" ";
                  hlength--;
                  heapify(arr,0);

         }
}

void swap(int *x, int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

int main(){
	heap h(100);
	h.insert(4);
	h.insert(6);
	h.insert(9);
	h.insert(3);
	h.insert(2);
            h.display();
            h.deletion();
            h.display();
            h.heapify(h.arr,0);
            h.heapsort();
            h.display();
            return 0;
}
