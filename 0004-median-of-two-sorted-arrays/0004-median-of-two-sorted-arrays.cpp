class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr=nums1;
        double ans=0;
        arr.insert(arr.end(),nums2.begin(),nums2.end());
        sort(arr.begin(),arr.end());
        if(arr.size()%2!=0){
            ans=arr[arr.size()/2];
        }
        else{
            ans=(arr[(arr.size()/2)-1]+arr[arr.size()/2]);
            ans=ans/2;
        }

        return ans;
    }
};