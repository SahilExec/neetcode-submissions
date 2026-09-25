class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for(int i=0; i<strs.size(); i++){
            encoded += to_string(strs[i].length()) + "#" + strs[i];
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;

        for(int i=0; i<s.length(); i++){
            string length = "";

            while(s[i] != '#'){
                length += s[i];
                i++;
            }

            string decoded = "";
            
            int j = 0;
            while(j < stoi(length)){
                i++;
                decoded += s[i];
                j++;
            }

            res.push_back(decoded);
        }
        return res;
    }
};
