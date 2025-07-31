// A maze is given as n*n matrix of blocks where source block is the upper left most block i.e., matrix[0][0] and destination block is lower rightmost block i.e., matrix[n-1][n-1]. A rat starts from source and has to reach the destination.

// The rat can move in only two directions: first forward (if possible) or down.

// In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be used in the path from source to destination. The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j]. 

// Return a maxtrix of size n*n in which 1 at (i, j) represents the cell is taken into the path otherwise 0 .

// Note : If multiple solutions exist, the shortest earliest hop will be accepted. For the same hop distance at any point, forward will be preferred over downward. 

// Example:

// Input: {{2,1,0,0},{3,0,0,1},{0,1,0,1},
// {0,0,0,1}}
// Output: {{1,0,0,0},{1,0,0,1},{0,0,0,1},
// {0,0,0,1}}

class Solution {
  public:
    bool isValid(vector<vector<int>>& m,int i, int j){
        if(i>=0 && j>=0 && i<m.size() && j<m[0].size() && m[i][j]!=0)return true;
        return false;
    }
    bool solve(vector<vector<int>>& m,int i, int j, vector<vector<int>>& vis){
        if(i==m.size()-1 && j==m[0].size()-1){
            vis[i][j]=1;
            return true;
        }
        if(isValid(m,i,j) && !vis[i][j]){
            vis[i][j]=1;
            for(int t=1;t<=m[i][j];t++){
                if(solve(m,i,j+t,vis))return true;
                if(solve(m,i+t,j,vis))return true;
            }
            vis[i][j]=0;
        }
        return false;
    }
    vector<vector<int>> ShortestDistance(vector<vector<int>>& matrix) {
        // Code here
        vector<vector<int>>vis(matrix.size(),vector<int>(matrix[0].size(),0));;
        // if(matrix[0][0]==0)return {{-1}};
        bool t = solve(matrix,0,0,vis);
        if(t==false)return{{-1}};
        return vis;
        
    }
};