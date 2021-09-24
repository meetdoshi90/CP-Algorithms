//The algorithm works in O(n+m) time, where n is number of vertices and m is the number of edges.
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> adj, vector<int>& visited, int cur){
	cout << cur << " ";
	visited[cur] = 1;
	for(int i=0; i<visited.size(); i++){
		if(!visited[i] && adj[cur][i]==1)
			dfs(adj,visited,i);
	}
	return;
}
int main(){
	int n;
	cout << "Enter number of nodes" << endl;
	cin >> n;
	vector<vector<int>> adj(n,vector<int>(n));
	cout << "Enter adj matrix" << endl;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> adj[i][j];
	cout << "Enter root node" << endl;
	vector<int> visited(n);
	cin >> n;
	dfs(adj,visited,n);
	return 0;
}

