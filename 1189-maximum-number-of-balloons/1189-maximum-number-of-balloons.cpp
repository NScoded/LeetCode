class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>check(128,0);
        for(char c : text){
            check[c]++;
        }
        return min({check['b'],check['a'],check['l']/2,check['o']/2,check['n']});
        
    }
};