class Solution {
public:

    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='U' || c=='O' )
        return true;
        return false;
    }


    int maxFreqSum(string s) {
        int mc=0,mv=0;
        vector<int>hash(127,0);
        for(char c:s){
            hash[c]++;
            if(isVowel(c)){
                mv=max(mv,hash[c]);
            }
            else mc=max(mc,hash[c]);
        }
        return mv+mc;
    }
};