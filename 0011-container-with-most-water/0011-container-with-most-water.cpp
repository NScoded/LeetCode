class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int best=0;
        while(l<r){
            best=max(best,min(height[r],height[l])*(r-l));
            (height[l]<height[r])?l++:r--;
        }
        return best;
    }
};