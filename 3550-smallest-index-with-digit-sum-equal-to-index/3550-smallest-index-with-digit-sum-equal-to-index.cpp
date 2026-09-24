class Solution {
private:
    int sumOfDig(int n){
        int sum=0;
        while(n>0){
            int dig=n%10;
            sum+=dig;
            n/=10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(sumOfDig(nums[i])==i){
                int index=i;
                return min(ans,index);
            }
        }
        return -1;
    }
};