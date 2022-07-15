/*
	LINK: https://leetcode.com/problems/subarray-sum-equals-k/submissions/
*/

// BRUTE FORCE solution. 

int subarraySum(vector<int>& nums, int k) {
       int count = 0;
    for(int i =0; i < nums.size(); i++ ){
        int sum = 0, j = i;
        while(j < nums.size()){
            sum += nums[j++];
            if(sum == k) {
                count++;
                while(j< nums.size() && nums[j] == 0){
                    count ++;
                    j++;
                }
            }
        }
    }
    return count;
}