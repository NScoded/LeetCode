class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> vec(numRows);
        int dir=0,i=0;
        string ans;
        for( char c : s){
            vec[i].push_back(c);

            if(dir==0){
                i++;
                if(i==numRows){
                    i=i-2;
                    dir=1;
                    continue;
                }
            }
            if(dir==1){
                i--;
                if(i==-1){
                    i=1;
                    dir=0;
                }
            }
        }

        for(int i=0;i<vec.size();i++){
            for(char c:vec[i]){
                ans=ans+c;

            }
        }
        return ans;

        
    }
};