/*
	LINK: https://leetcode.com/problems/3sum/submissions/

*/

// not a very good solution. need to do something faster!
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> s;
        map<int,int> mapp;
        for(int i =0; i < nums.size(); i++){ // map search takes log n time. so it can be an advantage in the third phase;
            mapp[nums[i]] = i;
        }
        for(int i =0; i< nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;	// skipping repitions since nums is sorted
            for(int j = i+1; j < nums.size(); j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                
                if(mapp[-(nums[i]+nums[j])] > j)
                    s.push_back(vector<int>({nums[i], nums[j], -(nums[i] + nums[j])}));
                
            }
        }
        return s;
    }
};


// A slightly better solution using two point finger algorithm


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i =0; i < nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            int j = i+1, k = nums.size()-1;
            while(j < k){
                if(j != i+1 && nums[j] == nums[j-1] ) {j++;continue;};
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    res.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    j++;
                } else if (sum < 0){
                    j++;
                }else {
                    k--;
                }
                
            }
        }
        return res;
    }
};


