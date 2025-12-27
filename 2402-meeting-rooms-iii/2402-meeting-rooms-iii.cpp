// Solution 2
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Min heap of available rooms
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; i++) {
            availableRooms.push(i);
        }

        // Min heap of busy rooms: {endTime, roomIndex}
        priority_queue<pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>> busyRooms;

        vector<int> count(n, 0);

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            // Free up rooms
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                availableRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                busyRooms.push({end, room});
                count[room]++;
            } else {
                // Delay meeting
                auto [finishTime, room] = busyRooms.top();
                busyRooms.pop();
                busyRooms.push({finishTime + duration, room});
                count[room]++;
            }
        }

        // Find room with max meetings
        int result = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[result]) {
                result = i;
            }
        }

        return result;
    }
};
