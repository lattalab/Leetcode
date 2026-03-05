class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;
        for (int i=0; i<chars.size(); i = read + 1) {
            read = i;
            // finding group
            while (read + 1< chars.size() && chars[read] == chars[read+1]) {
                read++;
            }
            
            // using write pointer to replace old string
            chars[write++] = chars[i];
            int count = read - i + 1;
            // enter multiple digits
            if (count > 1) {
                string s = to_string(count);
                for (auto ch : s) {
                    chars[write++] = ch;
                }
            }
        }
        return write;
    }
};