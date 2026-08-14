class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=0;
        int window=0;
        int j=0;
        unordered_map<int,int>freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            window++;
            while(freq[s[i]]>2){
                freq[s[j]]--;
                window--;
                j++;
            }
            ans=max(ans,window);
        }
        return ans;
    }
};