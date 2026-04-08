#include<bits/stdc++.h>
using namespace std;
int minimumCost(int n, vector<vector<int>>& edges, vector<int>& teleports, int source, int destination) {
   vector<vector<int>> adj(n);
   vector<int> vis(n, 0);
	 for(auto it : edges){
		   adj[it[0]].push_back(it[1]);
		   adj[it[1]].push_back(it[0]);
   }
   for(int i=0; i<teleports.size(); i++){
	   for(int j=i+1; j<teleports.size(); j++){
		   adj[teleports[i]].push_back(teleports[j]);
		   adj[teleports[j]].push_back(teleports[i]);
	   }
   }
   unordered_set<int> st;
   for(int i=0; i<teleports.size(); i++) st.insert(teleports[i]);
   queue<pair<int, int>> q;
   q.push({source, 0});
   vis[source] = 1;
   while(!q.empty()){ 
	   int node = q.front().first;
	   int d = q.front().second;
	   if(node == destination) return d;
	   q.pop();
	   for(auto it : adj[node]){
		   if(!vis[it]){
			   vis[it] = 1;
                if((st.find(it) != st.end()) && (st.find(node) != st.end())){
                    q.push({it, d});
                }
			   else q.push({it, d+1});
			 }
		}
	}
	return -1;
}
int main(){
    int n = 8;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7}};
    vector<int> teleports =  {1, 4, 6};
    int source = 0;
    int destination = 7;
    cout << minimumCost(n, edges, teleports, source, destination) << endl;
    return 0;
}