bool isMatch(char* s, char* p) {
    if (*p == '\0') return *s == '\0';
    
    if(*(p+1) != '*') {
        if (*p == *s || (*p=='.' && *s!='\0')) {
            return isMatch(++s, ++p);
        } else {
            return false;
        }
    } else {
        while(*p==*s || (*p=='.' && *s!='\0')) {
            if (isMatch(s, p+2)) {
                return true;
            }
            
            s++;
        }
        
        return isMatch(s, p+2);
    }
}