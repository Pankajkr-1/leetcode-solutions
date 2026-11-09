class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        bool odd=false;
        int ans=0;
        for(auto it:mp){
            if(it.second%2==0){
                ans+=it.second;
            }
            else{
                ans+=it.second-1;
                odd=true;
            }
        }
        if(odd) ans++;
        return ans;
    }
};