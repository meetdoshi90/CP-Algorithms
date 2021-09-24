//Total asymptotic running time of this algorithm is O(n+m)
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> adj, vector<int>& visited, int v){
	cout << v << " ";
	visited[v] = 1;
	for(int i=0; i<visited.size(); i++){
		if(!visited[i] && adj[v][i])
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
	cout << "Connected components are" << endl;
	vector<int> visited(n);
	for(int i=0; i<visited.size(); i++){
		if(!visited[i]){
			dfs(adj,visited,i);
			cout << endl;
		}
	}
	return 0;
}

