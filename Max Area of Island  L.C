https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    void dfs(int i,int j,int n,int m, vector<vector<int>>&grid, vector<vector<int>>&vis,int &count){
        vis[i][j]=1;
        count++;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nrow = i + dx[k];
            int ncol = j + dy[k];
            if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]==1 && vis[nrow][ncol]!=1 ){
               dfs(nrow,ncol,n,m,grid,vis,count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0,ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(i,j,n,m,grid,vis, count);
                    ans=max(ans,count);
                    count=0;
                }
            }
        }
        return ans;
    }
};
