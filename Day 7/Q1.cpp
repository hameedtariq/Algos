/*
	LINK:https://leetcode.com/problems/product-of-array-except-self/submissions/
*/

//bruteforce approach

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        for(int i =0; i< nums.size(); i++){
            int res = 1;
            for(int j =0; j< nums.size(); j++){
                if(i !=j ){
                    res *= nums[j];
                }
            }
            answer.push_back(res);
        }
        return answer;
    }
};

// using division approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int prod = 1;
        int zeros = 0;
        for(int i= 0; i < nums.size(); i++){
            if(nums[i]!= 0) {
                prod *= nums[i];
            }
            else {
              zeros++;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) {
                if(zeros > 1) {
                    ans[i] = 0;
                }
                else {
                    ans[i] = prod;
                }
            }
            else {
                if(zeros > 0){
                    ans[i] = 0;
                }
                else {
                    ans[i] = prod / nums[i];
                }
            }
        }
        
        return ans;
    }
};








// two pointer survey approach
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int prefix = 1;
        for(int i=0; i< nums.size();i++){
            ans[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for(int i=nums.size()-1; i >= 0 ;i--){
            ans[i] = postfix * ans[i];
            postfix *= nums[i];
            
        }
        return ans;
    }
};