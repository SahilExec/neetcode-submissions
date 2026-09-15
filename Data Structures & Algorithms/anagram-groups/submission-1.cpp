class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i=0; i<strs.size(); i++) {
            vector<int> freq(26, 0);

            string skey = strs[i];
            sort(skey.begin(), skey.end());

            mp[skey].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for (auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};
