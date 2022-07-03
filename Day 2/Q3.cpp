/*
	LINK: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#
	Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

*/

// also try implementing this using your own sort function!


int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr,arr+r+1);
        return arr[k-1];
    }