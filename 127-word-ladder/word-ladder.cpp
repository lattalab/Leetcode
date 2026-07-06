class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // set is better for quick find whether the elements appeared
        unordered_set<string> st(wordList.begin(), wordList.end());
        // store the path length, also act as visited array
        unordered_map<string, int> mp;

        // bfs
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;

        while(!q.empty()) {
            string word = q.front();
            q.pop();
            for (int i=0; i<word.size(); i++) {
                string new_word = word;
                // try to replace each character
                for (int j=0; j<26; j++) {
                    new_word[i] = j + 'a';
                    // new_word is in wordList, and haven't pass through
                    if (st.find(new_word) != st.end() &&
                        mp.find(new_word) == mp.end()) {
                            mp[new_word] = mp[word] + 1;
                            q.push(new_word);
                        }
                }
            }
        }
        return mp[endWord];
    }
};