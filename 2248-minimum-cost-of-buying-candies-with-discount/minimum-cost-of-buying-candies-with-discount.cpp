class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int price=0;
        for(int i=0;i<n;i++){
            if((i)%3==2)continue;
            price+=cost[n-i-1];
        }
        return price;
    }
};