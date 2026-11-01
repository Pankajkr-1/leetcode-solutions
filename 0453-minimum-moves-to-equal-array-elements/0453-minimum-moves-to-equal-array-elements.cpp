class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int minCount=0;
        int ele=*min_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            minCount+=nums[i]-ele;
        }
        return minCount;
    }
};