class Solution {
public:
    int maximumProduct(vector<int>& A) {
        int n = A.size();
        
        for (int i = 0; i < 2; i++) {                   // Extract 2 minimums
            int k = i;
            for (int j = i + 1; j < n; j++)
                if (A[j] < A[k]) k = j;                 // Find min index
            swap(A[i], A[k]);                           // Place min at front
        }

        for (int i = n - 1; i >= max(0, n - 3); i--) {  // Extract 3 maximums
            int k = i;
            for (int j = 0; j < i; j++)
                if (A[j] > A[k]) k = j;                 // Find max index
            swap(A[i], A[k]);                           // Place max at back
        }

        return max(
            A.back() * A[n - 2] * A[n - 3],
            A.back() * A.front() * A[1]
        );
    }
};