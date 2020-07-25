/* Author: Akkapaka Saikiran (@saikidon911) */
#include <bits/stdc++.h>
using namespace std;

vector<long long> dist;

struct comp {
	bool operator() (const int &x, const int &y) const {
		return make_pair(dist[x],x) < make_pair(dist[y],y);
	}
};

int main(){

	int n,m; cin>>n>>m;
	vector<vector<pair<int,int>>> a(n+1);
	dist.resize(n+1, 1e12);

	int u,v,w;
	for(int i = 0; i < m; i++){
		cin>>u>>v>>w;
		a[u].push_back(make_pair(v,w));
		a[v].push_back(make_pair(u,w));
	}

	set<int, comp> nodes;
	vector<int> parent(n+1);


	dist[1] = 0;
	for(int i = 1; i <= n; i++) nodes.insert(i);

	while(!nodes.empty()){
		int u = *nodes.begin();
		nodes.erase(u);

		for(pair<int,int> p : a[u]){
			int v = p.first;
			int w = p.second;
			if(dist[v] > dist[u] + w){
				parent[v] = u;
				nodes.erase(v);
				dist[v] = dist[u] + w;
				nodes.insert(v);
			}
		}
	}

	if(dist[n] == 1e12) cout<<-1<<endl;
	else{
	vector<int> path = {n};
		int x = n;
		while(parent[x] != 0){
			path.push_back(parent[x]);
			x = parent[x];
		}

		for(int i = path.size()-1; i >= 0; i--) cout<<path[i]<<" ";
		cout<<endl;
	}		
}