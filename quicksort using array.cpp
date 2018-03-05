#include <iostream>
using namespace std;

int partition (int arr[], int left, int right){
	int i=left;
	int j=right;
	int pivot= arr[(left+right)/2];
	while (i<=j){
		while(arr[i]<pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
	}
	int temp=0;
	if(i<=j){
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
	}
	return i;
}

int quicksort (int arr[], int left, int right, int n){
	int index=partition(arr,left,right);
	if (left<index-1){
		quicksort(arr,left,index-1,n);
	}
	if (right>index){
		quicksort(arr,index,right,n);
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
