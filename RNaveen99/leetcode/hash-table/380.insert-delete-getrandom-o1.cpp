/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/insert-delete-getrandom-o1/
 */

// design
// Note: does the order of elements should be preserved or not when removing a element.
class RandomizedSet {
    vector<int> numbers;
    unordered_map<int, int> hash;

  public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash.count(val)) {
            return false;
        }
        numbers.emplace_back(val);
        hash[val] = numbers.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hash.count(val) == 0) {
            return false;
        }
        hash[numbers.back()] = hash[val];
        numbers[hash[val]] = numbers.back();
        numbers.pop_back();
        hash.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() { return numbers[rand() % numbers.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */