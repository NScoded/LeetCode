class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> res;
        int count = 0, start = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') count++;
            else count--;
            
            if(count == 0) {
                // recursive call for inner substring
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                res.push_back("1" + inner + "0");
                start = i + 1;
            }
        }
        
        sort(res.rbegin(), res.rend());  // descending order
        
        string ans = "";
        for(string &str : res)
            ans += str;
            
        return ans;
    }
};