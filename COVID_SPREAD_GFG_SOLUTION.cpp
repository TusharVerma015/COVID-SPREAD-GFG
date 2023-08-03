class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        int N = hospital.size();
        int M = hospital[0].size();
        vector<vector<int>>vis(N,vector<int>(M,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i = 0 ; i<N;i++){
            for(int j = 0 ; j<M ; j++){
                if(hospital[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int tm = INT_MIN;
        while(!q.empty()){
            auto it = q.front();
            tm = max(tm,it.first);
            int r = it.second.first;
            int c = it.second.second;
            q.pop();
            for(int i = 0 ;i<4;i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr>=0 && nr<N && nc>=0 && nc<M && !vis[nr][nc] && hospital[nr][nc]==1){
                    q.push({tm+1,{nr,nc}});
                    vis[nr][nc] = 1;
                }
            }
            
            
        }
        for(int i = 0 ; i<N ; i++){
            for(int j = 0 ; j<M ;j++){
                if(hospital[i][j]==1 && vis[i][j]==0) return -1;
            }
        }
        return tm;
    }
};
