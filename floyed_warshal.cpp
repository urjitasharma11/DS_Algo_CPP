//Time complexity is O(N^3) (N is number of vertices)
//CODE : (gr is adjacency matrix where gr[i][j] = wt of edge from i to j)

Void floyed(vector<vector<int>>& gr, int N)
{
   vector<vector<int>> dis = gr;
   for(int k = 0;k<N;k++){
       for(int i = 0;i<N;i++){
           for(int j = 0;j<N;j++){
               if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX)
               if(dis[i][j]>dis[i][k] + dis[k][j])
               dis[i][j] = dis[i][k] + dis[k][j];
           }
       }
   }
   print(dis);
}
