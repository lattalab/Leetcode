bool canConstruct(char* ransomNote, char* magazine) {
    int table[26] = {0};
    // calculate for the frequency for each character
    for (int i=0; i<strlen(magazine); i++){
        table[magazine[i] - 'a']++;
    }

    for (int j=0; j<strlen(ransomNote); j++){
        table[ransomNote[j] - 'a']--;
        // magazine have not enough characters
        if (table[ransomNote[j] - 'a'] < 0) return false;
    }
    return true;
}