class Solution {
public:
    string getHappyString(int n, int k) {
        string currentString = "";
        string result = "";
        int indexInSortedList = 0;

        // Generate happy strings and track the k-th string
        generateHappyStrings(n, k, currentString, indexInSortedList, result);
        return result;
    }

private:
    void generateHappyStrings(int n, int k, string &currentString,
                              int &indexInSortedList, string &result) {
        // If the current string has reached the desired length
        if (currentString.size() == n) {
            indexInSortedList++;  // Increment the count of generated strings

            // If this is the k-th string, store it in the result
            if (indexInSortedList == k) result = currentString;
            return;
        }

        // Try adding each character ('a', 'b', 'c') to the current string
        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            // Skip if the current character is the same as the last one
            if (currentString.size() > 0 && currentString.back() == currentChar)
                continue;

            currentString += currentChar;

            // Recursively generate the next character
            generateHappyStrings(n, k, currentString, indexInSortedList,
                                 result);

            // If the result is found, stop further processing
            if (result != "") return;

            // Backtrack by removing the last character
            currentString.pop_back();
        }
    }
};