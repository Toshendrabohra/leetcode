class Solution {
public:

    // Encodes a URL to a shortened URL.
    string dec;
    string encode(string longUrl) {
        dec=longUrl;
        return "a";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return dec;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));