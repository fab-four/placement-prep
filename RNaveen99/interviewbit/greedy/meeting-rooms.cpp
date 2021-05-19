/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/meeting-rooms/
 */

// similar to hotel bookings possible
int Solution::solve(vector<vector<int>> &A) {
    int N = A.size();
    if (N == 0) {
        return 0;
    }
    sort(A.begin(), A.end());

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int roomsAllocated = 1;

    // insert finishing time
    pq.push(A[0][1]);

    for (int i = 1; i < N; i++) {
        int earliestEndingTime = pq.top();
        int startingTime = A[i][0];
        if (startingTime >= earliestEndingTime) {
            pq.pop();
        } else {
            roomsAllocated++;
        }
        // insert finishing time
        pq.push(A[i][1]);
    }
    return roomsAllocated;
}