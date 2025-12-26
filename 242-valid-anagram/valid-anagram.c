bool isAnagram(char* s, char* t) {
    int array[26] = {0};
    int i;
    for (i=0; i<26; i++) array[i] = 0;
    for (i=0; i<strlen(s); i++) array[s[i] - 'a']++;
    for (i=0; i<strlen(t); t++) array[t[i] - 'a']--;

    for (i=0; i<26; i++){
        if (array[i] != 0) {
            return false;
        }
    }

    return true;
}