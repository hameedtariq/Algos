/*
LINK: https://www.hackerearth.com/problem/algorithm/gpl/

Problem
It's Binod's Birthday and all his friends want to have a great GPL for him. But Binod being so schemy, he locked his room with a secret number and given his friends a Binary string of secret number.

His friends have no knowledge about binary strings. Would you help his friends to convert given Binary String to Decimal and participate in Binod's GPL.

Binary String is a string with only '0' and '1'  as it's characters.

Examples : "000101", "10101", "1", "0", "01" are Binary Strings.

    "Ab3024", "123", "1A", "6", "AA" are not Binary Strings

Input Format

First Line : Integer  that denotes number of test cases .
For each Test Case : Integer  for size of Binary String  and Binary String  .
Output Format

For each Test case, print Single Line integer containing the secret number.
Note: Secret number will always be greater than or equal to 0.

*/




#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int size; 
		cin >> size;
		string BN;
		cin >> BN;
		long long int num = 0;
		long long int mul = 1;
		// don't use pow(). it's an expensive function, instead maintain a multiplier to add as you move one position ahead;
		for(auto i = BN.rbegin(); i != BN.rend(); i++)
		{
			if((*i -48) == 1)
			{
				num += mul;
			}
			mul *= 2;
		}
		cout << num << endl;
	}
	
	
	return 0;
}