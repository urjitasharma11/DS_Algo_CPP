//Its TC is E^2 ( but E log E when implemented using Fibonacci heap ) 
//CODE : (gr[E][3] - edge matrix (u,v,weight)
int fillVis(vector<bool>& vis, vector<int>& dis){
       int min = INT_MAX, minI = -1;
       for(int i =0;i<dis.size();i++){
           if(dis[i]< min && vis[i] ==0 )
               min = dis[i], minI =i;
       }
       return minI;
   }
int Djikstra(vector<vector<int>>& gr, int N, int K, int dest)
{
       vector<int> dis(N,INT_MAX);
       vector<bool> vis(N,0);
       dis[K-1] = 0;// K is source (not zero indexed)
       if(gr.size()==1 && gr[0][0] != K-1) return -1;
       for(int j =0;j<N;j++){
           int u = fillVis(vis,dis);
//finding the next minimun distant edge
           vis[u] = 1;
           for(int i =0;i<gr.size();i++){
               if(gr[i][0]==u){
                   int v = gr[i][1];
                   if(vis[v]==0 && dis[u]!=INT_MAX){
                       if(dis[u]+ gr[i][2] < dis[v])
                           dis[v] = gr[i][2] + dis[u];
                   }
               }
           }
       }
       ans = dis[dest-1];
       return ans;
   }
