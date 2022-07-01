/*
LINK: https://www.hackerearth.com/problem/algorithm/jiyas-sequence/

Problem
Jiya likes a sequence if all its elements when multiplied yields a number , whose least significant digit is either 2, 3 or 5.

Given the number of  test case t.The first line of each test case is a number n.Next line contains n integers - A1,A2,......An.For each given test case tell whether the given sequence will be liked by Jiya.

INPUT FORMAT-

First line constains t number of test cases.

Every test case has first line as the number of intergers the sequence contains, followed by sequence in the next line.

OUTPUT FORMAT -

Print "YES" or "NO",whether Jiya likes the sequence or not.

CONSTRAINTS-

1≤t≤100

1≤n≤15

1≤Ai≤10, for all i



*/




#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int noOfdigits,digit;
		long long int product = 1;
		cin >> noOfdigits;
		for(int i =0; i< noOfdigits; i++){
			cin>>digit;
			product *= digit; 
		}
		
		if(product % 10 == 2 || product % 10 == 3 || product % 10 == 5  )		{
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
	
	return 0;
}