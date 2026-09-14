class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string output;

        string first = strs[0];
        int i=0;

        while(i < strs[0].length()){

            for(int j=0; j<strs.size(); j++){
                string curr = strs[j];

                if(i == curr.length() || curr[i] != first[i]){
                    return output;
                }
            }
            output += first[i];

            i++;
        }
        return output;
    }
};