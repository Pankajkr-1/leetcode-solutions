class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    long long total= grid[i][j];
                    grid[i][j]=0;
                    stack<pair<int , int>>st;
                    st.push({i,j});
                    while(!st.empty()){
                        auto[x,y]=st.top();
                        st.pop();
                        for(auto& d:dirs){
                            int nx=x+d[0];
                            int ny=y+d[1];
                            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]>0){
                                total+=grid[nx][ny];
                                grid[nx][ny]=0;
                                st.push({nx,ny});
                            }
                        }
                    }
                    if(total%k==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};