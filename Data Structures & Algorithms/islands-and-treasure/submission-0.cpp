class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& v) {

        int INF = 2147483647;

        int n = v.size();
        int m = v[0].size();


        queue<pair<int,int>> q;


        // Put all gates in queue
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(v[i][j] == 0){

                    q.push({i,j});

                }
            }
        }


        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};



        while(!q.empty()){

            auto [r,c] = q.front();
            q.pop();


            for(int d=0;d<4;d++){

                int nr = r + dx[d];
                int nc = c + dy[d];


                if(nr>=0 && nr<n &&
                   nc>=0 && nc<m &&
                   v[nr][nc] == INF)
                {

                    v[nr][nc] = v[r][c] + 1;

                    q.push({nr,nc});
                }
            }
        }
    }
};