class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int R=0,L=0,D=0;
        for(char c : moves){
            if(c=='L')L++;
            if(c=='R')R++;
            if(c=='_')D++;
        }
        return abs(R-L)+D;
    }
};