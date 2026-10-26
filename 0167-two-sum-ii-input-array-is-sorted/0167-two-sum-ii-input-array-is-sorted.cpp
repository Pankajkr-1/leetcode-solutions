class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int st=0;
        int end=n-1;
        while(st<end){
            int sum=numbers[st]+numbers[end];
            if(sum==target){
                return {st+1 ,end+1};
            }
            else if(sum<target) {
                st++;
            }
            else{
                end--;
            }
        }
        return {};
    }
};