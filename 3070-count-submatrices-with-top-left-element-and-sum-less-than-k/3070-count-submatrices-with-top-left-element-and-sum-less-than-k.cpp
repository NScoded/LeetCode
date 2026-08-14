class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int right=1;
        int sum=0;
        int down =1;
        int ans=0;
        if(grid[0][0]>k)return 0;
        ans++;


        for(int i=1;i<grid[0].size();i++){
            grid[0][i]+=grid[0][i-1];
            if(grid[0][i]>k)break;
            right++;
            ans++;

        }
        for(int i=1;i<grid.size();i++){
            grid[i][0]+=grid[i-1][0];
            if(grid[i][0]>k)break;
            down++;
            ans++;
        }
        if(down==1|| right==1)return ans;
    
        for(int column=1;column<right;column++){
        
            for(int row=1;row<down;row++){
                grid[row][column]+=grid[row-1][column] + grid[row][column-1] - grid[row-1][column-1];
                if(grid[row][column]>k){
                    
                    break;
                }
                ans++;

            }
        }
        return ans;

    }
};