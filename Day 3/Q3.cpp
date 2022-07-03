/*
	LINK: https://leetcode.com/problems/find-the-duplicate-number/submissions/
	Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
	
	There is only one repeated number in nums, return this repeated number.
	
	You must solve the problem without modifying the array nums and uses only constant extra space.
*/

// using map... its slow
int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        for(auto &a: nums){
            m[a] = m[a] + 1;
        }
        for(auto &a: nums){
           if(m[a] > 1){
               return a;
           }
        }
        return 0;
}

// sorting first and then looking. faster!!
 int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i =0; i < nums.size(); i++){
            if(i != nums.size()-1 && nums[i] == nums[i+1]) return nums[i];
        }
        return 0;
}