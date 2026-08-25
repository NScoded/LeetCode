class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>multiple;
        for(int num :nums){
            if(num%k==0){
                multiple.insert(num);
            }
        }
        int i=1;
        while(true){
            if(multiple.find(i*k)==multiple.end())return i*k;
            i++;
        }
        return 0;
    }
};