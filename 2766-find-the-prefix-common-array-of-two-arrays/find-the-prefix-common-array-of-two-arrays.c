/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int freq[60] = {0};
    int n = ASize;
    int *ans = malloc(n *sizeof(int));
    int count = 0;
    for (int i=0; i<n; i++) {
        
        freq[A[i]]++;
        if (freq[A[i]] == 2) count++;

        freq[B[i]]++;
        if (freq[B[i]] == 2) count++;

        *(ans + i) = count;
    }
    *returnSize = n;
    return ans;
}