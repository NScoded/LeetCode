class Solution {
public:
    bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {

        // move left pointer to next alphanumeric
        while (i < j && !isalnum(s[i])) i++;

        // move right pointer to next alphanumeric
        while (i < j && !isalnum(s[j])) j--;

        // compare lowercased characters
        if (tolower(s[i]) != tolower(s[j]))
            return false;

        i++;
        j--;
    }
    return true;
}

};