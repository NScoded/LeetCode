class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        double ans=0;
        int size=nums1.size();
        if(nums1.size()%2==0){
            ans=nums1[size/2]+nums1[(size/2)-1];
            return ans/2;
        }
        ans=nums1[size/2];
        return ans;
    }
};