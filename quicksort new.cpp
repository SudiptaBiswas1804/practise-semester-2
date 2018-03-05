#include <iostream>
using namespace std;

int swap(int* a, int* b){
	int t= *a;
	*a= *b;
	*b= t;
}

int partition (int arr[], int left, int right){
	int i=left-1;
	int j;
	int temp=0;
	int pivot= arr[right];
            for(j=left; j<right-1; j++){
            	if(arr[j]<right){
            		i++;
            		swap(&arr[i],&arr[j]);
            		
            		}
            	swap(&arr[i+1],&arr[right]);
            }
	return (i+1);
}

int quicksort (int arr[], int left, int right, int n){
	if(left<right){
	int index=partition(arr,left,right);
	quicksort(arr,left,index-1,n);
	quicksort(arr,index+1,right,n);	
	}
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n;
	int arr[n];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	quicksort(arr,0,n-1,n);
	return 0;
	}
