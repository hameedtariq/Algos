/*
	LINK: https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1#
	Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.
*/










int doUnion(int a[], int n, int b[], int m)  {
    set<int> s;
    for(int i =0; i < n; i++){
        s.insert(a[i]);
    }
    for(int i =0; i < m; i++){
        s.insert(b[i]);
    }
    return s.size();
}