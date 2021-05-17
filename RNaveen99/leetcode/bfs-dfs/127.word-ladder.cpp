/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/word-ladder/
 */

class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int size = q.size();
            while (size) {
                size--;
                string front = q.front();
                q.pop();
                if (front == endWord) {
                    return steps;
                }
                for (int i = 0; i < front.size(); i++) {
                    char c = front[i];
                    for (int alphabet = 0; alphabet < 26; alphabet++) {
                        front[i] = 'a' + alphabet;
                        if (hash.find(front) != hash.end()) {
                            q.push(front);
                            hash.erase(front);
                        }
                    }
                    front[i] = c;
                }
            }
            steps++;
        }
        return 0;
    }
};