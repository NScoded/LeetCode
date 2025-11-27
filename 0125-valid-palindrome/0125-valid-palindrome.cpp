class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while(j>i && !isalnum(s[j])) j--;
            while(i<j && !isalnum(s[i]))i++;
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++;j--;
        }
        return true;
}

};