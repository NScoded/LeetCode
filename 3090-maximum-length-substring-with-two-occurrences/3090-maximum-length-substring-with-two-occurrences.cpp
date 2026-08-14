class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int size=0;
            unordered_map<int,int>freq;
            freq[s[i]]++;
            for(int j=i+1;j<s.size();j++){
                if(freq[s[j]]<2){
                    freq[s[j]]++;
                    size++;
                }
                else{
                    break;
                }
            }
            ans=max(size,ans);
        }
        return ans+1;
    }
};