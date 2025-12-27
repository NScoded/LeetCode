


/// Solution 1
class Solution {
public:
    int mostBooked(int n, vector<vector<int>> meetings) {

    sort(meetings.begin(), meetings.end());

    // free rooms (min room index)
    priority_queue<int, vector<int>, greater<int>> freeRooms;

    // busy rooms {endTime, roomIndex}
    priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> busyRooms;

    vector<int> count(n, 0);

    // initially all rooms are free
    for(int i = 0; i < n; i++)
        freeRooms.push(i);

    for(auto &m : meetings) {
        long long start = m[0], end = m[1];
        long long duration = end - start;

        // free rooms that have finished
        while(!busyRooms.empty() && busyRooms.top().first <= start) {
            freeRooms.push(busyRooms.top().second);
            busyRooms.pop();
        }

        int room;
        long long finishTime;

        if(!freeRooms.empty()) {
            room = freeRooms.top();
            freeRooms.pop();
            finishTime = end;
        } else {
            auto [t, r] = busyRooms.top();
            busyRooms.pop();
            room = r;
            finishTime = t + duration;
        }

        count[room]++;
        busyRooms.push({finishTime, room});
    }

    // find most booked room
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(count[i] > count[ans])
            ans = i;
    }
    return ans;
}
};