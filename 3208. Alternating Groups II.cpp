// Link- https://leetcode.com/problems/alternating-groups-ii/description/?envType=daily-question&envId=2025-03-09

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i=0;
        int m=k-1;
        while(m--){
            colors.push_back(colors[i]);
            i++;
        }
        int count=0;
        int right=1;
        int n=colors.size();
        int left=0;
        while(right<n){
            if(colors[right]==colors[right-1]){
             left=right;
             right++;
            continue;
        }
        right++;
        if(right-left<k) continue;
        count++;
        left++;
        }
        return count;
    }
};
