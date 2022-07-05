/*
	LINK: https://www.codingninjas.com/codestudio/problems/valid-perfect-square_1082552?leftPanelTab=1
*/


bool isPerfectSquare(long long n) {
    if(n == 1) return 1;
    long long end = n, start = 0, guess;
//     long long pguess;
    while(start <= end){
        guess = (start + end)/2;
        long long int prod = guess * guess;
        if(prod == n){
            return guess;
        }else if (prod > n){
            end = guess - 1;
        } else {
            start = guess + 1;
        }
   
    }
    
    return false;
}