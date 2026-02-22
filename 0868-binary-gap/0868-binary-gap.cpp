class Solution {
public:
    int binaryGap(int n) {
        int first=-1,pos=0,dist=0;
        while(n>0){
            if(n&1){
                if(first!=-1){
                    dist=max(dist,pos-first);
                }
                first=pos;
            }
            n=n>>1;
            pos++;
        }
        return dist;
    }
};