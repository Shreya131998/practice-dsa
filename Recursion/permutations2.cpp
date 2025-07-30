// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
class Solution {
public:
    void solve(vector<int>&nums,int index,vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,bool>m;
        for(int i=index;i<nums.size();i++){
            if(m.find(nums[i])!=m.end())continue;
            m[nums[i]]=true;
            swap(nums[i],nums[index]);
            solve(nums,index+1,ans);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,0,ans);
        return ans;
    }
};