class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for(int i = s.size() - 1; i > 0; i--) {
            if((s[i] - '0' + carry) % 2 == 0) {
                steps += 1;   // even → divide by 2
            } else {
                steps += 2;   // odd → +1 then divide
                carry = 1;
            }
        }

        return steps + carry;
    }
};