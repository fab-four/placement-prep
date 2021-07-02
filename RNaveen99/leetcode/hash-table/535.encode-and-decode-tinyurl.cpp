/**
 * Author : Naveen Rohilla
 * User   : RNaveen99
 * Link   : https://leetcode.com/problems/encode-and-decode-tinyurl/
 */

// design
class Solution {
    unordered_map<string, string> url2code;
    unordered_map<string, string> code2url;
    random_device rd;
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (!url2code.count(longUrl)) {
            string code = "";
            for (int i = 0; i < 6; i++) {
                code += charset[rd() % charset.size()];
            }
            if (!url2code.count(code)) {
                url2code[longUrl] = code;
                code2url[code] = longUrl;
            }
        }
        return "http://tinyurl.com/" + url2code[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (shortUrl.size() != 25 || !code2url.count(shortUrl.substr(19, 6))) {
            return "";
        }
        return code2url[shortUrl.substr(19, 6)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));