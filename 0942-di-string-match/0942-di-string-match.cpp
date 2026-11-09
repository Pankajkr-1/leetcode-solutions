class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        int low=0;
        int high=n;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                ans.push_back(low);
                low++;
            }
            if(s[i]=='D'){
                ans.push_back(high);
                high--;
            }
        }
        ans.push_back(low);
        return ans;
    }
};