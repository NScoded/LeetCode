class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a=-1,b=-1;
        vector<int>dummy(grid.size()*grid.size()+1,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                dummy[grid[i][j]]++;
            }
        }
        for(int i=0;i<dummy.size();i++){
            if(dummy[i]==2) a=i;
            if(dummy[i]==0) b=i;
        }
        return {a,b};
        
    }
};