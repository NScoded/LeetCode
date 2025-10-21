class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> Set;
        int left=0,Max=0;
        for(int right=0; right<s.size(); right++){
            while(Set.count(s[right])){
                Set.erase(s[left]);
                left++;
            }
            Set.insert(s[right]);
            Max=max(Max,right-left+1);
        }
        return Max;

    }
};