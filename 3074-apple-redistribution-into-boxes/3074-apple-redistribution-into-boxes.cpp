class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=0;
        for(int val:apple){
            total+=val;
        }
        sort(capacity.begin(),capacity.end());
        int i;
        for(i=capacity.size()-1;i>=0;i--){
            if(total-capacity[i]<=0)break;
            total=total-capacity[i];
        }
        return capacity.size()-i;
    }
};