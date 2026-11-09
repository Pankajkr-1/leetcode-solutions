class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        // for(int i=0;i<nums.size();i+=2){
        //     sum+=nums[i];
        // }
        // return sum;
        int i=0;
        int j=1;
        while(j<nums.size()){
            sum+=min(nums[i],nums[j]);
            i+=2;
            j+=2;
        }
        return sum;
    }
};