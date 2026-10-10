class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long k=(long long)k1+k2;
        vector<long long>freq(100002,0);
        long long ans=0;
        int mx=0;
        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            freq[d]++;
            ans+=d;
            mx=max(mx,d);
        }
        if(ans<=k) return 0;
        long long cnt=0;
        for(int d=mx ;d>=1;d--){
            cnt+=freq[d];
            freq[d]=0;
            if(cnt==0) continue;

            if(k>=cnt){
                k-=cnt;
                if(k==0){
                    freq[d-1]+=cnt;
                    break;
                }
            }
            else{
                freq[d]=cnt-k;
                freq[d-1]+=k;
                break;
            }
        }
        long long res=0;
        for(int d=1;d<=mx;d++){
            res+=freq[d]*(long long)d*d;
        }
        return res;
    }
};