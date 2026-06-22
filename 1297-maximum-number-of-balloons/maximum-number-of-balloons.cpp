class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        for(int i=0;i<text.length();i++) mpp[text[i]]++;
        int mini=INT_MAX;
        mini=min(mini,mpp['b']);
        mini=min(mini,mpp['a']);
        mini=min(mini,mpp['n']);
        mini=min(mini,mpp['l']/2);
        mini=min(mini,mpp['o']/2);
        return mini;
    }
};