#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int l, int h ){
	int pv = l;
	int i = l+1;
	int j = h;
	while(i < j){
		
		while(i < h && arr[i] <= arr[pv]){
			i++;
		}
		while(arr[j] > arr[pv]){
			j--;
		}
		if(i < j){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		
	}
	
	int temp = arr[pv];
	arr[pv] = arr[j];
	arr[j] = temp;
	return j;
}

void quickSort(int arr[], int l, int h ){
	if(l < h){
		int pv = partition(arr,l,h);
		quickSort(arr, l, pv - 1);
		quickSort(arr, pv+1, h);		
	}
}


int main(){
	
	int arr[] = {10,3,8,2,1,9,4,6,7};
	quickSort(arr,0,8);
	for(int i=0; i< 9; i++){
		cout << arr[i] << "-> "; 
	}
	
	 return 0;

}