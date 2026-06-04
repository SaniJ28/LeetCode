class Solution {
public:
    int peak_wavy(int n){
        vector<int>arr;
        while(n!=0){
            arr.push_back(n%10);
            n/=10;
        }
        int s=arr.size();
        int count=0;
        for(int i=1;i<s-1;i++){
            if((arr[i]>arr[i-1] && arr[i]>arr[i+1])||(arr[i]<arr[i-1] && arr[i]<arr[i+1]))count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++)ans+=peak_wavy(i);
        return ans;
    }
};