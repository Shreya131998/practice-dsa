// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

 
// sol1 
class Solution {
public:
    int solve(vector<int>& nums, int i, int j){
        if(i==j)return nums[i];
        int left = nums[i]-solve(nums,i+1,j);
        int right = nums[j]-solve(nums,i,j-1);
        return max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums,0,nums.size()-1)>=0;
    }
};
//  sol 2
class Solution {
public:
    bool solve(vector<int>& nums, int i, int j, int sum1, int sum2,int player){
        if(i>j){
            if(sum1>=sum2)return true;
            return false;
        }
        if(player==1){
            return solve(nums,i+1,j,sum1+nums[i],sum2,0) || solve(nums,i,j-1,sum1+nums[j],sum2,0);
        }
        else{
            return solve(nums,i+1,j,sum1,sum2+nums[i],1) && solve(nums,i,j-1,sum1,sum2+nums[j],1);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int sum1=0,sum2=0;
        return solve(nums,0,nums.size()-1,sum1,sum2,1);
    }
};