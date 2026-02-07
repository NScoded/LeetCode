class Solution {
public:

    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='U' || c=='O' )
        return true;
        return false;
    }

    bool doesAliceWin(string s) {
        for(char c : s){
            if(isVowel(c))return true;
        }
        return false;
    }
};