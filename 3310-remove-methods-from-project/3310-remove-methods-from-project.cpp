class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>>chain;
        unordered_set<int>remove;
        vector<int>original;
        vector<int>ans;

        for(int i=0;i<n;i++){
            vector<int>val;
            chain[i]=val;
            original.push_back(i);
        }

        for(int i=0;i<invocations.size();i++){
            int from=invocations[i][0];
            int to=invocations[i][1];
            vector<int>val=chain[from];
            val.push_back(to);
            chain[from]=val;
        }
        queue<int>buffer;


        do{
            if(!buffer.empty())buffer.pop();
            vector<int>members;
            members=chain[k];
            chain.erase(k);
            remove.insert(k);
            for(int val:members)buffer.push(val);
            k=buffer.front();

        }while(!buffer.empty());
        
        for(int i=0;i<n;i++){
            if(chain.find(i)!=chain.end()){
                vector<int>val;
                val=chain[i];
                for(int node:val){
                    if(remove.find(node)!=remove.end())return original;
                }
                ans.push_back(i);

            }
        }
        return ans;
    }
};