class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,best=0;

        while(r>l){
            best=max(best,(min(height[l],height[r]))*(r-l));
            (height[l]>height[r])? r--:l++;
        }
        return best;
    }
};