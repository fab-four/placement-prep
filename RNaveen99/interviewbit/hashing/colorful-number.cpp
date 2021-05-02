/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/colorful-number/
 */

int Solution::colorful(int A) {
    vector<int> digits;
    while (A) {
        digits.push_back(A % 10);
        A /= 10;
    }
    reverse(digits.begin(), digits.end());
    unordered_map<long long, bool> hash;

    for (int i = 0; i < digits.size(); i++) {
        long long value = 1;
        for (auto j = i; j < digits.size(); j++) {
            value *= digits[j];
            if (hash.find(value) != hash.end())
                return 0;
            hash.insert({value, true});
        }
    }
    return 1;
}