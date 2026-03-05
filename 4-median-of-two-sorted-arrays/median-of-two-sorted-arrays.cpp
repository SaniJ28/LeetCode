class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count=0;
        int n1=nums1.size();
        int n2=nums2.size();
        int r1=(n1+n2)/2;
        int r2=r1-1;
        double ind1,ind2;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(count==r1) ind1 =nums1[i];
                if(count==r2) ind2 =nums1[i];
                i++;
                count++;
            }
            else{
                if(count==r1) ind1 =nums2[j];
                if(count==r2) ind2 =nums2[j];
                 j++;
                count++;
            }
            }
            while(i<n1){
                 if(count==r1) ind1 =nums1[i];
                if(count==r2) ind2 =nums1[i];
                i++;
                count++;
            }
            while(j<n2){
                if(count==r1) ind1 =nums2[j];
                if(count==r2) ind2 =nums2[j];
                j++;
                count++;
            }
            if((n1+n2)%2) return (double) ind1;
            return (double)(ind1+ind2)/2;
    }
};