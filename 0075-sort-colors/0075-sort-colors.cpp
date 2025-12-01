class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        
        for(int col:nums){
            if(col==0)zero++;
            if(col==1)one++;
            if(col==2)two++;
        }
        int i=0;
        while(zero){
            nums[i]=0;
            i++;
            zero--;
        }
        while(one){
            nums[i]=1;
            one--;
            i++;
        }
        while(two){
            nums[i]=2;
            two--;
            i++;
        }
    }
};