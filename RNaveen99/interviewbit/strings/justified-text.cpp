/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/justified-text/
 */

vector<string> Solution::fullJustify(vector<string> &words, int lineLength) {
    vector<string> results;
    int size = words.size();
    int numOfWords = 0;
    int lengthOfWords = 0;
    for (int i = 0; i < size; i++) {
        while (i < size && (lengthOfWords + numOfWords + words[i].size()) <= lineLength) {
            numOfWords++;
            lengthOfWords += words[i].size();
            i++;
        }
        // justify the words from index (i - numOfWords) to (i - 1)
        // remember: at i(th) index the condition failed.
        int totalGapsAllowed = lineLength - lengthOfWords;
        int startIndex = i - numOfWords;
        int endIndex = i - 1;
        bool lastLine = (i == size) ? true : false;

        numOfWords--;
        int extraSpace = 0;
        int eachSpace = 0;

        if (numOfWords) {
            extraSpace = totalGapsAllowed % numOfWords;
            eachSpace = totalGapsAllowed / numOfWords;
        }
        if (lastLine) {
            eachSpace = 1;
            extraSpace = 0;
        }
        string result = "";
        string eachSpaceString = "";
        for (int k = 0; k < eachSpace; k++) {
            eachSpaceString += " ";
        }
        for (int j = startIndex; j < endIndex; j++) {
            result += words[j] + eachSpaceString;
            if (extraSpace) {
                result += " ";
                extraSpace--;
            }
        }
        // inserting last word of sentence
        result += words[endIndex];

        // padding space to match lineLength
        for (int j = result.size(); j < lineLength; j++) {
            result += " ";
        }
        results.emplace_back(result);
        numOfWords = 0;
        lengthOfWords = 0;
        i--;
    }
    return results;
}
