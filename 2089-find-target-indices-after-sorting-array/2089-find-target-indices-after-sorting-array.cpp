class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // int n=nums.size();
        // vector<int>ans;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     if(nums[i]==target){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
        // optimal way :-without using sorting method
        int diff=0;
        int same=0;
        for(int x:nums){
            if(x<target){
                diff++;
            }
            else if(x==target){
                same++;
            }
        }
        vector<int>ans;
        for(int i=0;i<same;i++){
            ans.push_back(diff+i);
        }
        return ans;
    }
};