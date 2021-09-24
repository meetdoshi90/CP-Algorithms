//The algorithm works in O(n+m) time, where n is number of vertices and m is the number of edges.
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> adj, vector<int> visited, queue<int> Q, int cur){
	Q.push(cur);
	visited[cur] = 1;
	while(!Q.empty()){
		int v = Q.front();
		cout << v << " ";
		Q.pop();
		for(int i=0; i<visited.size(); i++){
			if(!visited[i] && adj[v][i]==1){
				visited[i] = 1;
				Q.push(i);
			}
		}
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
	queue<int> Q;
	cout << "Enter root node" << endl;
	vector<int> visited(n);
	cin >> n;
	bfs(adj,visited,Q,n);
	return 0;
}

