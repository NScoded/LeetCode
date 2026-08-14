class Solution {
public:

    struct Val{
        int X=0;
        int Y=0;
    };

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int x=0,y=0;
        int ans=0;
        vector<vector<Val>>tab(grid.size(),vector<Val>(grid[0].size()));
        if(grid[0][0]=='X'){
            tab[0][0].X=1;
            x++;
        }
        if(grid[0][0]=='Y'){
            tab[0][0].Y=1;
            y++;

        }
        
        
        
        for(int i=1;i<grid.size();i++){
            if(grid[i][0]=='X')x++;
            if(grid[i][0]=='Y')y++;
            if(x==y && x && y)ans++;
            tab[i][0].X=x;
            tab[i][0].Y=y; 

        }

        x=tab[0][0].X;
        y=tab[0][0].Y;
        for(int i=1;i<grid[0].size();i++){
            if(grid[0][i]=='X')x++;
            if(grid[0][i]=='Y')y++;
            if(x==y && y && x)ans++;
            tab[0][i].X=x;
            tab[0][i].Y=y; 

        }
        for(int j=1;j<grid[0].size();j++){
            for(int i=1;i<grid.size();i++){
                x=0;y=0;
                if(grid[i][j]=='X')x++;
                if(grid[i][j]=='Y')y++;
                tab[i][j].X=x + tab[i-1][j].X + tab[i][j-1].X - tab[i-1][j-1].X;
                tab[i][j].Y=y + tab[i-1][j].Y + tab[i][j-1].Y - tab[i-1][j-1].Y;
                if(tab[i][j].X == tab[i][j].Y && tab[i][j].X && tab[i][j].Y)ans++;
                

            }
        }

        
        return ans;
    }
};
