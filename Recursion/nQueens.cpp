// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
class Solution {
public:
    bool isValid(int r, int c, vector<string>&v){
        // prev row
        int i =r;
        int j = c;
        while(j>=0){
            if(v[r][j]=='Q')return false;
            j--;
        }
        // diagonal up
        i =r;
        j =c;
        while(i>=0 && j>=0){
            if(v[i][j]=='Q')return false;
            i--;
            j--;
        }
        i=r;
        j=c;
        while(i<v.size() && j>=0){
            if(v[i][j]=='Q')return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans,vector<string>&v,int j, int n){
        if(j==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(i,j,v)){
                v[i][j]='Q';
                solve(ans,v,j+1,n);
                v[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==1){
            return {{"Q"}};
        }
        if(n<=3)return {};
        vector<vector<string>>ans;
        vector<string>v(n,string(n,'.'));
        solve(ans,v,0,n);
        return ans;

    }
};