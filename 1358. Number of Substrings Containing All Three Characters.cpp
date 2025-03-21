// Link- https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2025-03-11
class Solution {
public:
    bool cond(vector<int>& freq){
        return freq[0] && freq[1] && freq[2];
    }
    int numberOfSubstrings(string s) {
        int count=0;
        int n=s.length();
        int left=0,right=0;
        vector<int> frequency(3,0);
        while(right<n){
            char curr=s[right];
            frequency[curr - 'a']++;

            while(cond(frequency)){
                count+=n-right;
                char charL=s[left];
                frequency[charL-'a']--;
                left++;
            }
            right++;
        }
        return count;
    }
};
