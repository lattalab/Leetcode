bool hasAlternatingBits(int n) {
    // become leading 1
    unsigned int x = n ^ (n >> 1);
    return (x & (x + 1)) == 0;   
}