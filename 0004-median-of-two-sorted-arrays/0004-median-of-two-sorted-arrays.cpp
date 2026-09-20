class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int m= nums1.size();
        int n=nums2.size();
        int l=0;
        int h=m;
        int mid=(m+n+1)/2;
        while(l<=h){
            int i=(l+h)/2 , j=mid-i;
            int l1=i ? nums1[i-1] : INT_MIN;
            int r1=i<m ? nums1[i] : INT_MAX;
            int l2=j ? nums2[j-1] : INT_MIN;
            int r2=j<n ? nums2[j] : INT_MAX;
            if(l1<=r2 && l2<=r1){
                if((m+n)%2){
                    return max(l1,l2);
                }
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            if(l1>r2){
                h=i-1;
            }
            else{
                l=i+1;
            }
        }
        return 0.0;
    }
};