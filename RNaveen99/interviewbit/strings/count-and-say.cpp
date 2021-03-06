/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/count-and-say/
 */

string Solution::countAndSay(int n) {
    if (n == 0)
        return "";
    if (n == 1)
        return "1";

    string prev = "1";
    string current = "";

    for (int seqNum = 2; seqNum <= n; seqNum++) {

        for (int j = 0; j < prev.length(); j++) {

            // we have at least 1 occourence of each digit
            int count = 1;

            // get the number of times same digit occurred (be carefull with the end of the string)
            while ((j + 1 < prev.length()) && (prev[j] == prev[j + 1])) {
                count++;
                j++; // we need to keep increasing the index inside of the string
            }

            // add to new string "count" + "digit itself"
            current.append(to_string(count) + prev[j]);
        }

        prev = current;
        current.clear();
    }

    return current;
}