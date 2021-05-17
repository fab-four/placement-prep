/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/word-ladder-ii/
 */

class Solution {
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        hash.erase(beginWord);
        vector<vector<string>> result;
        queue<vector<string>> q;
        q.push({beginWord});
        int minLength = INT_MAX;
        while (!q.empty()) {
            int size = q.size();
            while (size) {
                size--;
                vector<string> front = q.front();
                q.pop();
                if (front.size() > minLength)
                    continue;
                if (front.back() == endWord) {
                    if (minLength == INT_MAX) {
                        minLength = front.size();
                    }
                    if (front.size() == minLength)
                        result.emplace_back(front);
                    continue;
                }
                for (int i = 0; i < front.back().size(); i++) {
                    string word = front.back();
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (hash.find(word) != hash.end()) {
                            vector<string> newPath = front;
                            newPath.emplace_back(word);
                            q.push(newPath);
                            hash.erase(front.back());
                        }
                    }
                }
            }
        }
        return result;
    }
};