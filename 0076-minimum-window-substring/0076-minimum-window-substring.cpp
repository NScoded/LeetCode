class Solution {
public:
   string minWindow(string s, string t) {
    if(s.size()<t.size()) return "";
    vector<int>v(128,0);
    for(char c:t)v[c]++;
    int req=t.size();
    int j=0,minwin=INT_MAX,start=0;
    for(int i=0;i<s.size();i++){
        if(v[s[i]]>0)req--;
        v[s[i]]--;

        while(req==0){
            if(i-j+1<minwin){
                minwin=i-j+1;
                start=j;
            }

            v[s[j]]++;
            if(v[s[j]]>0)req++;
            j++;
        }
    }
    return (minwin==INT_MAX)?"":s.substr(start,minwin);
   }

};