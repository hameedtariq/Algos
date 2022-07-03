/*
	LINK: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
	Move all negative numbers to beginning and positive to end with constant extra space
	

*/


#include <bits/stdc++.h>
using namespace std;
void rearrange(int arr[], int n){ // implemented using the idea of quickSort;
    int i =0, j = n;
    while(i < j){
        while(i < n-1 && arr[i] < 0) i++;
        while(j > i && arr[j] >= 0 ) j--;
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
	int arr[] = { -13, 11, -5, 4, 50, -42, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}