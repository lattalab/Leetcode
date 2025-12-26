class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int hash[26] = {0};
        // use first word to store in hash
        for (int i = 0; i < words[0].size(); i++) { 
            hash[words[0][i] - 'a']++;
        }

        int temp_hash[26] = {0};
        for (int i=1; i<words.size(); i++){
            // store hash for this word
            memset(temp_hash, 0, 26 * sizeof(int));
            for (int j=0; j<words[i].size(); j++){
                temp_hash[words[i][j] - 'a']++;
            }
            // update hash
            for (int k=0; k<26; k++){
                hash[k] = min(hash[k], temp_hash[k]);
            }
        }

        // use the information from hash and transfer to result string
        vector<string> results;
        for (int i=0; i<26; i++){
            // number of character can be repetitive
            while (hash[i]){
                string s(1, i+'a');
                results.push_back(s);
                hash[i]--;
            }
        }
        return results;
    }
};