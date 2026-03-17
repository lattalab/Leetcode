class Solution {
public:
    int hIndex(vector<int>& citations) {
        // counting sort
        int papers = citations.size();
        // H-index at most equal to the published papers
        vector<int> Hindex(papers+1, 0);
        for (int i=0; i<papers; i++) {
            Hindex[min(papers, citations[i])]++;
        }
        // iterate from the end, find if satisfy the condition
        int count = 0;
        for (int i=Hindex.size()-1; i>=0; i--) {
            count += Hindex[i];
            if (count >= i)
                return i;
        }
        return 0;
    }
};