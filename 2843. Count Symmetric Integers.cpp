// Link- https://leetcode.com/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(low ; low<=high;low++){
            if(low<100 && low%11==0) count++;
            else if(low>1000 && low<10000){
                int left = low / 1000 + (low % 1000) / 100;
                int right = (low % 100) / 10 + low % 10;
                if (left == right) {
                    count++;
            }
        }
        }
        return count;
    }
};
