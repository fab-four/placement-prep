class Solution {
public:
  // Time Complexity: O(n log(n))
  // Space Complexity: O(n)
  vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    unordered_map<int, int> freq;
    for (int barcode : barcodes) {
      freq[barcode]++;
    }
    priority_queue<pair<int, int>> pq;
    for (const auto &[key, value] : freq) {
      pq.push({value, key});
    }
    vector<int> res;
    res.reserve(barcodes.size());
    int n = barcodes.size();
    while (n && !pq.empty()) {
      auto first_most_freq = pq.top();
      pq.pop();
      res.push_back(first_most_freq.second);
      n--;
      if (!pq.empty()) {
        auto second_most_freq = pq.top();
        pq.pop();
        res.push_back(second_most_freq.second);
        n--;
        if (second_most_freq.first > 1) {
          pq.push({second_most_freq.first - 1, second_most_freq.second});
        }
      }
      if (first_most_freq.first > 1) {
        pq.push({first_most_freq.first - 1, first_most_freq.second});
      }
    }
    return res;
  }
};
