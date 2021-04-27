/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/pretty-json/
 */

vector<string> Solution::prettyJSON(string A) {
    vector<string> ans;

    int size = A.size();
    int i = 0;
    int indentation = 0;
    bool rowFilled = false;

    while (i < size) {
        string row = "";
        for (int j = 0; j < indentation; j++)
            row += '\t';
        rowFilled = false;

        while (i < size) {
            if (A[i] == '[' || A[i] == '{') {
                if (rowFilled)
                    ans.push_back(row);
                row = "";
                for (int j = 0; j < indentation; j++)
                    row += '\t';
                row += A[i];
                ans.push_back(row);
                i++;
                indentation++;
                break;
            }
            if (A[i] == ']' || A[i] == '}') {
                if (rowFilled)
                    ans.push_back(row);
                row = "";
                indentation--;
                for (int k = 0; k < indentation; k++)
                    row += '\t';
                row += A[i];
                if (i + 1 < size && A[i + 1] == ',')
                    row += A[++i];
                ans.push_back(row);
                i++;
                break;
            }
            row += A[i];
            rowFilled = true;
            if (A[i] == ',') {
                if (rowFilled)
                    ans.push_back(row);
                i++;
                break;
            }
            i++;
        }
    }
    return ans;
}