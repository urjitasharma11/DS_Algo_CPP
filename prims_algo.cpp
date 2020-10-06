//TC : O(E log V)
//Prim’s algorithm is also known as DJP Algorithm.  (duo Dijkstra and prim)
 
void primMST(vector<vector<pair<int,int>>> adj, int V)
{
   priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int src = 0; //it can be anything
   vector<int> dis(V, INF);
   // To store par array which in turn store MST
   vector<int> par(V, -1);
   vector<bool> vis(V, 0);
   pq.push({0, src});
   dis[src] = 0;
   while (!pq.empty())
   {
       int u = pq.top().second;
       pq.pop();
       vis[u] = 1; // Include vertex in MST
       for (auto x : adj[u])
       {
           int v = x.first;
           int weight = x.second;
           if (vis[v] == 0 && dis[v] > weight)
           {
               dis[v] = weight;
               pq.push({dis[v], v});
               par[v] = u;
           }
       }
   }
   for (int i = 1; i < V; ++i)
       printf("%d - %d\n", par[i], i);
}
