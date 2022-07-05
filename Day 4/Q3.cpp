/*
	LINK: https://www.codingninjas.com/codestudio/problems/binary-search_972?leftPanelTab=1

*/
int BS(int *input, int start, int end,int k){
    if(start > end){
        return -1;
    }
    int mid = (start+end)/2;
    if(input[mid] == k){
        return mid;
    }else if (input[mid] > k){
        return BS(input,start,mid-1,k);
    }else{
        return BS(input,mid+1,end,k);
    }
}

int binarySearch(int *input, int n, int val)
{
    return BS(input,0,n-1,val);
}