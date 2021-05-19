/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
 */

string Solution::multiple(int N) {
    if (N == 1)
        return "1";
    vector<int> parent(N, -1);
    vector<int> s(N, -1);
    int steps[2] = {0, 1};
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (front == 0)
            break;
        for (int step : steps) {
            int remainder = (front * 10 + step) % N;
            if (parent[remainder] == -1) {
                parent[remainder] = front;
                s[remainder] = step;
                q.push(remainder);
            }
        }
    }

    string number;
    for (int it = 0; it != 1; it = parent[it])
        number.push_back('0' + s[it]);
    number.push_back('1');
    return string(number.rbegin(), number.rend());
}