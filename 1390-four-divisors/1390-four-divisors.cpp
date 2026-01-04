class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            // case 1: n = p^3
            int p = round(cbrt(n));
            if (p * p * p == n && isPrime(p)) {
                ans += 1 + p + p*p + n;
                continue;
            }

            // case 2: n = p * q
            for (int d = 2; d * d <= n; d++) {
                if (n % d == 0) {
                    int e = n / d;
                    if (d != e && isPrime(d) && isPrime(e)) {
                        ans += 1 + d + e + n;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
