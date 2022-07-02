/*
	LINK: https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1/

	Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place).
	In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....
	
	If there are multiple solutions, find the lexicographically smallest one.
*/


void convertToWave(int n, vector<int>& arr){
        
        // Your code here
        for(int i =0; i< n; i += 2){
            if(i < n-1)
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
            
        }
    }