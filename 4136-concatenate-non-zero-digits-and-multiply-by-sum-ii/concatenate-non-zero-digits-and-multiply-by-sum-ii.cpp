class Solution {
public:
    int mod = 1e9 + 7;
    
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        // Prefix arrays (1-indexed to handle l=0 easily)
        vector<long long> pow10(n + 1, 1);
        vector<long long> pref_sum(n + 1, 0);
        vector<int> count(n + 1, 0);
        vector<long long> pref_val(n + 1, 0);

        // Precompute prefixes in O(N)
        for (int i = 0; i < n; i++) {
            pow10[i + 1] = (pow10[i] * 10) % mod;
            
            if (s[i] != '0') {
                int d = s[i] - '0';
                count[i + 1] = count[i] + 1;
                pref_sum[i + 1] = (pref_sum[i] + d) % mod;
                pref_val[i + 1] = (pref_val[i] * 10 + d) % mod;
            } else {
                count[i + 1] = count[i];
                pref_sum[i + 1] = pref_sum[i];
                pref_val[i + 1] = pref_val[i];
            }
        }

        int q = queries.size();
        vector<int> ans(q);
        
        // Process each query in O(1)
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            // 1. Calculate the sum of digits in the range
            long long current_sum = (pref_sum[r + 1] - pref_sum[l] + mod) % mod;
            
            // 2. Determine how many non-zero digits exist in the range
            int k = count[r + 1] - count[l];
            
            // 3. Extract the sub-value using modular arithmetic
            // x = (pref_val[R] - pref_val[L-1] * 10^k) % mod
            long long sub_val = (pref_val[r + 1] - (pref_val[l] * pow10[k]) % mod + mod) % mod;
            
            // 4. Multiply and store the answer
            ans[i] = (current_sum * sub_val) % mod;
        }

        return ans;
    }
};