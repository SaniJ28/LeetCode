class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n=groups.size();
        int flag=-1;
        for(int i=0;i<n;i++){
            if(flag!=groups[i]){
                flag=groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
