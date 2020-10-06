// time complexity of Bellman-Ford is O(VE) (that basically will go n^3 as edges are n*(n-1)/2 for complete graph)

// CODE : (gr[E][3] - edge matrix (u,v,weight)
void Bellman_ford(vector<vector<int>>& gr, int N, int src)
{
   vector<int> dis(N,INT_MAX);
   dis[src-1] = 0;// src is source (not zero indexed)
   if(gr.size()==1 && gr[0][0] != K-1) return -1;
   for(int i = 1;i<=N-1;i++){
       for(int j = 0; j<gr.size();j++){
           int u = gr[j][0], v = gr[j][1];
           if(dis[u]!= INT_MAX && dis[u]+ gr[i][2] < dis[v])
               dis[v] = gr[i][2] + dis[u];
       }
   }
   print(dis);
}
