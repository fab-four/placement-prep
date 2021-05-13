/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://www.interviewbit.com/problems/simplify-directory-path/
 */

string Solution::simplifyPath(string A) {
    vector<string> collection;
    string name = "";

    // For path ending with ..
    A.push_back('/');

    for (auto i = 0; i < A.length(); ++i) {
        if (A[i] == '/') {
            if (name.size() == 0)
                continue;
            else if (name == ".") {
                // do nothing
            } else if (name == "..") {
                if (collection.size() > 0)
                    collection.pop_back();
            } else
                collection.emplace_back(name);

            name.clear();
        } else
            name.push_back(A[i]);
    }

    if (collection.empty())
        return "/";

    A.clear();
    for (auto j = 0; j < collection.size(); ++j)
        A.append("/" + collection[j]);

    return A;
}