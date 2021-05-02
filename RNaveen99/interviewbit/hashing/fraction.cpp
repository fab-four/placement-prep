/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/fraction/
 */

string Solution::fractionToDecimal(int numerator, int denominator) {

    int64_t n = numerator, d = denominator;
    if (n == 0)
        return "0";

    string result;
    if ((n < 0) ^ (d < 0))
        result += '-';

    n = abs(n), d = abs(d);
    result += to_string((n / d));
    if (n % d == 0)
        return result;

    result += '.';
    unordered_map<int, int> map;
    int64_t remainder = n % d;
    while (remainder) {
        if (map.find(remainder) != map.end()) {
            result.insert(map[remainder], 1, '(');
            result += ')';
            break;
        }
        map[remainder] = result.size();
        remainder *= 10;
        result.push_back((char)('0' + (remainder / d)));
        remainder %= d
    }
    return result;
}