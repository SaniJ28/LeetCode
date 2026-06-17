class Solution {
public:
    char processStr(string s, long long k) {
        long long m = 0; // Tracks the true length

        // Step 1: Compute the exact final length (No capping needed!)
        for (char c : s) {
            if (c == '*') {
                m = max(0LL, m - 1);
            } else if (c == '#') {
                m *= 2;
            } else if (c != '%') {
                m += 1; // Standard letters increase the length
            }
        }

        // If k is out of bounds of the final string
        if (k >= m) return '.';

        // Step 2: Work backwards to pinpoint the character
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            
            if (c == '*') {
                // Before deletion, the string was 1 character longer
                m += 1;  
            } 
            else if (c == '#') {
                // Before duplication, the string was exactly half the size
                m /= 2;  
                if (k >= m) {
                    k -= m; // If k is in the duplicated half, wrap it back
                }
            } 
            else if (c == '%') {
                // Exact reverse mirror
                k = m - 1 - k; 
            } 
            else {
                // Before appending, the string was 1 character shorter
                m -= 1; 
                // If k matches the length right before this character was appended,
                // we've found our target!
                if (k == m) {
                    return c; 
                }
            }
        }

        return '.';
    }
};