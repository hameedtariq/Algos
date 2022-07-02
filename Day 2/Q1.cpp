/*
	LINK: https://practice.geeksforgeeks.org/problems/form-a-number-divisible-by-3-using-array-digits0717/1/#
	Given an array arr of integers of length N, the task is to find whether it’s possible to construct an integer using all the digits of these numbers such that it would be divisible by 3. If it is possible then print “1” and if not print “0”.

*/




int isPossible(int N, int arr[]) {
        long long int sum = 0;
        // for some reason if you only add the numbers together and not every digit. It still works, but I'm not sure about the math behind it. Will Update if I figured out!
        for(int i = 0; i< N; i++){
            while(arr[i] != 0){
                sum += arr[i] % 10;
                arr[i] /= 10;
            }
        }
        if(sum % 3 == 0){
            return true;
        }
        return false;
        
}