class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int right=0;
        int sum=0;
        int down =0;
        int ans=0;
        for(int i=0;i<grid.size();i++){

            if(sum+grid[i][0]<=k){
                
                sum+=grid[i][0];
                if(i)ans++;
        
                down++;
            }
            else{
                break;
            }

        }
        
    
        
        sum=0;
        vector<int>buffer;
        for(int i=0;i<grid[0].size();i++){
            if(sum+grid[0][i]<=k){
                sum+=grid[0][i];
                ans++;
                right++;
                if(buffer.empty()){
                    buffer.push_back(grid[0][i]);
                }
                else{
                    buffer.push_back(buffer.back()+grid[0][i]);
                }
            }
            else{
                break;
            }

        }
        if(down==1|| right==1)return ans;

        for(int column=1;column<right;column++){
            sum=buffer[column];
            int j=column;
            for(int row=1;row<grid.size();row++){
                sum+=grid[row][column];
                if(sum>k)break;
                int j=column;
                j--;
                while(sum<=k && j>=0){
                    sum+=grid[row][j];
                    j--;
                }
                if(sum>k){
                    break;
                }
                else{
                    ans++;
                }

            }
        }
        return ans;

    }
};