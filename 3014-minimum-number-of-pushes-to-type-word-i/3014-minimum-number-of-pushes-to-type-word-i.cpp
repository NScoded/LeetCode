class Solution {
public:
    int minimumPushes(string word) {
        int r=word.size()%8;
        int q=word.size()/8;
        
        return 8*(q*(q+1)/2)+r*(q+1);
    }
};