/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/partitions/
 */

int Solution::solve(int A, vector<int> &B) {
    int sum = 0;
    for (int ele : B) {
        sum += ele;
    }
    int result = 0;
    if (sum % 3 != 0) {
        return result;
    }
    vector<int> prefix;
    int tempSum = 0;
    int oneThird = sum / 3;
    for (int i = 0; i < B.size(); i++) {
        tempSum += B[i];
        if (tempSum == oneThird) {
            prefix.emplace_back(i);
        }
    }
    tempSum = 0;
    vector<int> suffix;
    for (int i = B.size() - 1; i >= 0; i--) {
        tempSum += B[i];
        if (tempSum == oneThird) {
            suffix.emplace_back(i);
        }
    }
    for (int i = 0; i < prefix.size(); i++) {
        for (int j = 0; j < suffix.size(); j++) {
            tempSum = 0;
            bool flag = false;
            for (int k = prefix[i] + 1; k < suffix[j]; k++) {
                tempSum += B[k];
                flag = true;
            }
            if (flag && tempSum == oneThird) {
                result++;
            }
        }
    }
    return result;
}

int Solution::solve(int A, vector<int> &B) {
    int sum = 0;
    for (int ele : B) {
        sum += ele;
    }
    int result = 0;
    if (sum % 3 == 0) {
        int oneThird = sum / 3;
        int twoThird = 2 * oneThird;
        int oneThirdCount = 0;

        sum = 0;
        for (int i = 0; i < B.size() - 1; i++) {
            sum += B[i];

            if (sum == twoThird) {
                result += oneThirdCount;
            }
            if (sum == oneThird) {
                oneThirdCount++;
            }
        }
    }
    return result;
}
