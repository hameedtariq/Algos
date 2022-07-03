#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int l, int h ){
	int pv = l;
	int i = l;
	int j = h;
	while(i < j){
		
		while(i < h && arr[i] < arr[pv]){
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
	
	int arr[] = {12 ,5, 787, 1, 23};
	quickSort(arr,0,4);
	for(int i=0; i< 5; i++){
		cout << arr[i] << "-> "; 
	}
	
	 return 0;

}