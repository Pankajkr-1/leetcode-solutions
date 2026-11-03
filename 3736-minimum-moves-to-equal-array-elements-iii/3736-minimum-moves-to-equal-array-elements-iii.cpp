class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max=*max_element(nums.begin(),nums.end());
        int count=0;
        for(int x:nums){
            count+=max-x;
        }
        return count;
    }
};