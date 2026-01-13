class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = 1e18, high = -1e18;

        // Calculate total area and search range
        for (auto &s : squares) {
            double y = s[1], l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double half = totalArea / 2.0;

        // Binary search
        for (int i = 0; i < 100; i++) { // enough for 1e-5 precision
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;

            for (auto &s : squares) {
                double y = s[1], l = s[2];
                double bottom = y;
                double top = y + l;

                if (mid <= bottom) {
                    // no area below
                }
                else if (mid >= top) {
                    areaBelow += l * l;
                }
                else {
                    areaBelow += (mid - bottom) * l;
                }
            }

            if (areaBelow < half)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
