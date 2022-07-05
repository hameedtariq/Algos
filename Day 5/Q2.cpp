int guessNumber(int n) {
    int start = 0;
    int end = n;
    while(start <= end){
        int mid = start+(end - start)/2;
        int res = guess(mid);
        if(res == 0){
            return mid;
        }else if (res == -1){
            end = mid -1;
        } else if (res == 1){
            start = mid+1;
        }
    }
    
    return 0;
}