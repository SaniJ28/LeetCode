// Link- https://leetcode.com/problems/finding-3-digit-even-numbers/?envType=daily-question&envId=2025-05-12
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_set<int> nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j || j==k || i==k) continue;
                    int num=digits[i]*100+ digits[j]*10+ digits[k];
                    if(num>99 && num<1000 && num%2==0) nums.insert(num);
                }
            }
        }
        vector<int> res;
        for(int num :nums){
            res.push_back(num);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
