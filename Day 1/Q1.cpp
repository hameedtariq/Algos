/*
LINK: https://www.hackerearth.com/problem/algorithm/capitalbaazi/
Problem
Cheems doesn't like extra content so coming straight to the point. Given the input of one line, having words separated by a single space, print each word of the input, each in a new line.
Also, change all the alphabets to uppercase along with doing this.

Input:-
Given in one line, all letters are lowercase only, separated by a single space.

Characters used in input are from 'a' to 'z' only ( 26 in total ) , both included.

Length of input   

Output:-
Output each word with characters in uppercase.

Note:- A testcase contains only one word as the input to get partial marks. Also, the ideal solution has been provided, you can test any of your legal input to get its answer.


*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
	string word;
	
	while(cin >> word)
	{
		for(auto &x: word )
		{
			x = toupper(x);	
		}
		cout << word << endl;
	}	
	return 0;
}