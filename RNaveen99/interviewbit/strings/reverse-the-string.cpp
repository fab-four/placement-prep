/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/reverse-the-string/
 */

void Solution::reverseWords(string &A) {
    stringstream ss(A);
    string word, res;
    while (ss.good()) {
        ss >> word;
        if (!res.empty())
            word += " ";
        res = word + res;
    }
    A = res;
}

void Solution::reverseWords(string &A) {
    reverse(A.begin(), A.end());
    stringstream ss;
    ss << A;
    string result = "";
    string word;
    while (ss.good()) {
        ss >> word;
        reverse(word.begin(), word.end());
        if (result == "") {
            result = word;
        } else {
            result += " " + word;
        }
    }
    A = result;
}