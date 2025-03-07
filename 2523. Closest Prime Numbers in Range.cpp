// Link-https://leetcode.com/problems/closest-prime-numbers-in-range/?envType=daily-question&envId=2025-03-07

class Solution {
public:
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) { // Only check 6k ± 1 numbers
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

    vector<int> closestPrimes(int left, int right) {
        int n1=-1,n2=-1;
        int dist=INT_MAX;
        vector<int> ans(2);
        for(int i=left;i<=right;i++){
            if(isPrime(i) && n1==-1){
                n1=i;
            }
            else if(isPrime(i)){
                n2=i;
                int gap=n2-n1;
                // if(gap==2) return {n1,n2};
                if(gap<dist){
                    ans[0]=n1;
                    ans[1]=n2;
                    dist=gap;
                }
                n1=n2;
            }
        }
        if(ans[0]==ans[1]) return{-1,-1};
        return ans;;
    }
};
