class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad, dir;
        // push to disired queue
        int len = senate.size();
        for (int i=0; i<len; i++) {
            if (senate[i] == 'R') rad.push(i);
            else dir.push(i);
        }
        // battle
        while (!rad.empty() && !dir.empty()) {
            if (rad.front() < dir.front()) {
                rad.push(len++);
            }
            else {
                dir.push(len++);
            }
            rad.pop(); dir.pop();
        }
        return (rad.empty()) ? "Dire" : "Radiant";
    }
};