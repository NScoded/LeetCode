class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=n%2;
        n=n/2;
        while(n>0){
            int cur=n%2;
            if(prev==cur)return false;
            prev=cur;
            n=n/2;
        }
        return true;
        
    }
};