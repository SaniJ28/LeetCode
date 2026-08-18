class Solution {

public:
    int funct(vector<vector<int>>& jobs, int index,int freeTime, vector<vector<int>>& dp){
        if(index==jobs.size())return 0;
        if(dp[index][freeTime]!=-1)return dp[index][freeTime];
        int notTake=0+funct(jobs,index+1,freeTime,dp);
        int take=0;
        if(jobs[index][0]>=freeTime){
            take=jobs[index][2]+funct(jobs,index+1,jobs[index][1],dp);
        }
        return dp[index][freeTime]=max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= profit.size();
        int maxi=0;
        vector<vector<int>>jobs(n,vector<int>(3));
        for(int i=0;i<n;i++){
            maxi=max(maxi,endTime[i]);
            jobs[i][0]=startTime[i];
            jobs[i][1]=endTime[i];
            jobs[i][2]=profit[i];
        }
        sort(jobs.begin(),jobs.end());
        vector<int>dp(n+1,0);
        vector<int>sortedStart;
        for(int i=0;i<n;i++){
            sortedStart.push_back(jobs[i][0]);
        }
        for(int i=n-1;i>=0;i--){
            int notTake=dp[i+1];
            int nextInd=lower_bound(sortedStart.begin(),sortedStart.end(),jobs[i][1]) -sortedStart.begin();
            int take=jobs[i][2]+dp[nextInd];
            dp[i]=max(take,notTake);
        }
        return dp[0];
    }
};