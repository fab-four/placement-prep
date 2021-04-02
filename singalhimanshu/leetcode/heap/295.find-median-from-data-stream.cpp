// @author: Himanshu
// @user: singalhimanshu
// Link: https://leetcode.com/problems/find-median-from-data-stream/

/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    auto left_pq_size = m_left_pq.size();
    auto right_pq_size = m_right_pq.size();
    if (num >= m_median) {
      if (right_pq_size > left_pq_size) {
        m_left_pq.push(m_right_pq.top());
        m_right_pq.pop();
        m_right_pq.push(num);
        m_median = (m_right_pq.top() + m_left_pq.top()) / 2.0;
      } else if (right_pq_size == left_pq_size) {
        m_right_pq.push(num);
        m_median = m_right_pq.top();
      } else {
        m_right_pq.push(num);
        m_median = (m_right_pq.top() + m_left_pq.top()) / 2.0;
      }
    } else {
      if (left_pq_size > right_pq_size) {
        m_right_pq.push(m_left_pq.top());
        m_left_pq.pop();
        m_left_pq.push(num);
        m_median = (m_left_pq.top() + m_right_pq.top()) / 2.0;
      } else if (right_pq_size == left_pq_size) {
        m_left_pq.push(num);
        m_median = m_left_pq.top();
      } else {
        m_left_pq.push(num);
        m_median = (m_left_pq.top() + m_right_pq.top()) / 2.0;
      }
    }
  }

  double findMedian() { return m_median; }

private:
  priority_queue<int> m_left_pq;
  priority_queue<int, vector<int>, greater<int>> m_right_pq;
  double m_median;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end