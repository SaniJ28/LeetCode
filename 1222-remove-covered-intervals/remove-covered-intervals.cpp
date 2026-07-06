class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count=0;
        int n=intervals.size();
sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];  
            return a[0] < b[0];
        });  
                int l=-1;
        for(int i=0;i<n;i++){
            if(intervals[i][1]<=l){
                count++;
            }
            else l=intervals[i][1];
        }
        return n-count;
    }
};