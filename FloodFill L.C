BFS

class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int n, int m, int startingcol, int color) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int arr1[4] = {-1,0,1,0};
            int arr2[4] = {0,1,0,-1};

            for(int i=0;i<4;i++){ 
                int delRow = arr1[i] + row;
                int delCol = arr2[i] + col;
                //agar starting col hua ya assigned color jo diya hai woh nhi hua uska mtlb 0 hoga pakka
                if (delRow >= 0 && delRow < n && delCol >= 0 && delCol < m &&
                    image[delRow][delCol] == startingcol && image[delRow][delCol] != color) {
                    image[delRow][delCol] = color;
                    q.push({delRow, delCol});
                  }
            }     
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int startingcol = image[sr][sc];
        bfs(image, sr, sc, n, m, startingcol, color);
    
        return image;
    }
};


DFS

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int row = image.size();
    int col = image[0].size();
    int startcol = image[sr][sc];
    DFS(image,startcol,row,col,sr,sc,newColor);
    
    return image;
    }
    
    void DFS(vector<vector<int>>& image,int startcol,int row,int col,int sr, int sc, int newColor)
    {
        if(isValid(image,startcol,row,col,sr,sc,newColor))return;
        
        image[sr][sc] = newColor;
        
         DFS(image,startcol,row,col,sr+1,sc,newColor);
         DFS(image,startcol,row,col,sr-1,sc,newColor);
         DFS(image,startcol,row,col,sr,sc+1,newColor);
         DFS(image,startcol,row,col,sr,sc-1,newColor);
    }
    
    bool isValid(vector<vector<int>>& image,int startcol,int row,int col,int sr, int sc, int newColor)
    {
        if(sr<0 || sr>=row || sc<0 ||sc>=col || image[sr][sc]!=startcol || image[sr][sc]==newColor)return true;
        return false;
    }
};
