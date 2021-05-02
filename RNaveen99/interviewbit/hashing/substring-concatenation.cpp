/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/substring-concatenation/
 */

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> ans;
    int numberOfWords = B.size();
    int textSize = A.length();
    if (numberOfWords == 0 || textSize == 0)
        return ans;

    // length of 1 string
    int eachWordSize = B[0].length();
    // length of required substring
    int permutationSize = numberOfWords * eachWordSize;

    if (permutationSize > textSize)
        return ans;

    unordered_map<string, int> frequency;
    for (int i = 0; i < numberOfWords; i++)
        frequency[B[i]]++;

    for (int i = 0; i <= textSize - permutationSize; i++) {
        // start with each index and consider a substring of length permutationSize
        unordered_map<string, int> m;
        m = frequency;
        int count = 0;
        for (int j = i; j < i + permutationSize; j += eachWordSize) {
            string temp = A.substr(j, eachWordSize);
            if (m.find(temp) != m.end() && m[temp] > 0) {
                m[temp]--;
                if (m[temp] == 0)
                    count++;
            } else
                break;
        }
        if (count == frequency.size())
            ans.push_back(i);
        m.clear();
    }
    return ans;
}
