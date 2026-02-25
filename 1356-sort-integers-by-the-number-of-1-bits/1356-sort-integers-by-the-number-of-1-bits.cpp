class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // priority_queue<int,vector<int>>map;
        // for(int val:arr){
        //     int bits=__builtin_popcount(val);
        //     vector<int>curr=map[bits];
        //     curr.push_back(val);
        //     map[bits]=curr;
        // }
        // return map[1];

        // for(int i=0;i<arr.size()-1;i++){
        //     for(int j=i+1;i<arr.size();i++){
        //         if(__builtin_popcount(arr[i])==__builtin_popcount(arr[j]) && arr[i]>arr[j]){
        //             swap(arr[i],arr[j]);
        //             continue;
        //         }
        //         if(__builtin_popcount(arr[i])>__builtin_popcount(arr[j])){
        //             swap(arr[i],arr[j]);
        //         }
        //     }
        // }
        // return arr;

        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                int Lbit=__builtin_popcount(arr[i]);
                int Rbit=__builtin_popcount(arr[j]);
                if(Lbit>Rbit){
                    swap(arr[i],arr[j]);
                    continue;
                }
                if(Lbit==Rbit && arr[i]>arr[j]){
                    swap(arr[i],arr[j]);

                }
            }
        }
        return arr;
    }
};