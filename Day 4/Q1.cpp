/*
	LINK: https://leetcode.com/problems/reverse-string/submissions/
	
*/


void reverseString(vector<char>& s) {
    auto i = s.begin(), j = s.end() - 1;
    while(i < j){
        swap(*i, *j);
        i++;
        j--;            
    }
}