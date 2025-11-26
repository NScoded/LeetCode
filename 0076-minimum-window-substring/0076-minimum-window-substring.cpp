class Solution {
public:
   string minWindow(string s, string t) {
    // Written by myself
     if(s.size()<t.size()) return "";

     vector<int>need(128,0);
     int req=0;
     for(char c : t){
        need[c]++;req++;
     }
     int i=0,minwindow=INT_MAX,start=0;

     for(int j=0;j<s.size();j++){
        if(need[s[j]]>0) req--;
        need[s[j]]--;

        while(req==0){
            if(j-i+1<minwindow){
                minwindow=j-i+1;
                start=i;
            }
            need[s[i]]++;
            if(need[s[i]]>0) req++;
            i++;
        }

     }
     return (minwindow==INT_MAX)? "" : s.substr(start,minwindow);
    }



};