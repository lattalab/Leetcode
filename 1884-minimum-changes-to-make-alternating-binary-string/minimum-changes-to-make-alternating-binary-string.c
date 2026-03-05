int minOperations(char* s) {
    // optimization solution by bit-wise operation
    int diff = 0;
    int len = strlen(s);
    for (int i=0; i<len; i++) {
        // test if matching to '0101...' pattern
        diff += (s[i] - '0') ^ (i & 1);
    }
    // while the opposite side pattern if '1010...'
    // the difference is symtric to s.size() - diff
    if (diff > (len - diff)) return len - diff;
    return diff;
}