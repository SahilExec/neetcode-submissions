class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }

        vector<vector<int>> vec(nums.size() + 1);
        for(auto p : freq){
            vec[p.second].push_back(p.first);
        }

        vector<int> result;
        for(int j = vec.size()-1; j >= 0 && result.size() < k; j--){

            for(int num : vec[j]){
                result.push_back(num);

                if(result.size() == k)
                    break;
                }
        }

        return result;
    }
};
