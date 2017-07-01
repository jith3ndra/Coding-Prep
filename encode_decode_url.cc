class Solution {
private:
    unordered_map<string,string> map1;
    string str ="http://tinyurl.com/";
public:
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        unordered_map<string,string>::hasher fn = map1.hash_function();
        //cout << fn(longUrl)<<endl;
        map1[to_string(fn(longUrl))] = longUrl;
        return str+to_string(fn(longUrl));
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map1[shortUrl.substr(str.size())];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
