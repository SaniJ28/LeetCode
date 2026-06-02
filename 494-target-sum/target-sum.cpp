class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(diff>sum||(sum-diff)%2==1) return 0;
        int s1=(sum-diff)/2;
        
        vector<int> prev(s1+1,0), cur(s1+1,0);
        if(arr[0]==0) prev[0]=2;
        else prev[0]=1;
        if(arr[0]!=0 && arr[0]<=s1) prev[arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int s=0;s<=s1;s++){
                int notTake=prev[s];
                int take=0;
                if(s>=arr[i]) take=prev[s-arr[i]];
                cur[s]=take+notTake;
            }
            prev=cur;
        }
        return prev[s1];
    }
};