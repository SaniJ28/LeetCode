// Link-https://leetcode.com/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-03-24

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n=meetings.size();
        int lastEnd=0;
        int meet=0;
        for(int i=0;i<n;i++){
            int start=meetings[i][0];
            int end=meetings[i][1];

            if(start>lastEnd){
                meet+=end-start+1;
                lastEnd=end;
            }
            else{
                meet=meet+max(lastEnd,end)-lastEnd;
                lastEnd=max(lastEnd,end);
            }
        }
        return days-meet;
    }
};
