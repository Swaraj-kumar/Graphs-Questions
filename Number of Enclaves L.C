https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(int r, int c,int n,int m, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[r][c] = 1;
        
        int delRow[4] = {-1, 0, +1, 0};
        int delCol[4] = {0, 1, 0, -1}; 
        
        for(int i=0; i<4; i++){
            int nRow = r + delRow[i];
            int nCol = c + delCol[i];
            
            if(nRow >=0 && nRow < n && nCol >=0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1){
                dfs(nRow,nCol,n,m,vis, grid);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //for first and last row
        for(int j=0; j<m; j++){
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0, j,n,m,vis,grid);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                dfs(n-1, j, n,m,vis, grid);
            }
        }
        //for first and last col
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0,n,m, vis, grid);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i, m-1,n,m,vis, grid);
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};
