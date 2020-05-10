#include<iostream>
#include<queue> 
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std; 


vector< set<int> > a;
vector< set<int> > ra;
vector< set<int> > dead;
vector< set<int> > rev_dead;

vector<bool> visited;
vector<bool> vis;
stack<int> s1; // stores vertices in ascending finish number order
stack<int> s2; // ditto but for second dfs
stack<int> scc;

vector<int> ma;
vector<int> smax;


int longest=0;

void addEdge(vector< set<int> > &adj, int u, int v){
	adj[u].insert(v);
} 

void addEdge2(vector< vector<int> > &adj,int u,int v){
	adj[u].push_back(v);
}

void printGraph(vector< set<int> > adj, int V){
    for (int v = 0; v < V; ++v){ 
        cout<<v<<" : "; 
        for (auto x : adj[v]) cout<<x<<" "; 
        cout<<endl; 
    } 
    cout<<endl;
}

void printGraph2(vector< vector<int> > &adj, int V){
    for (int v = 0; v < V; ++v){ 
        cout<<v<<" : "; 
        for (auto x : adj[v]) cout<<x<<" "; 
        cout<<endl; 
    } 
    cout<<endl;
}

bool inadj(vector< set<int> > &a,int u,int v){
	return a[u].find(v)!=a[u].end();
} 

void remove_from_a(vector< set<int> > &a,int u,int v){
	auto it = a[u].find(v);
	a[u].erase(it);
}
 
void dfs1(vector< set<int> > &a,int u,stack<int> &s){
	visited[u]=true;
	for(auto v : a[u]){
		if(!visited[v]) dfs1(a,v,s);
	}
	s.push(u);
}

void dfs2(vector< set<int> > &a,int u,stack<int> &s){
	visited[u]=true;
	for(auto v : a[u]){
		if(!visited[v]) dfs2(a,v,s);
	}
	s.push(u);
}

void dfs3(vector< set<int> > &a, int u,int p){
	visited[u]=true;
	ma[u]=0;
	smax[u]=0;
	for(auto c : a[u]){
		if(!visited[c]) dfs3(a,c,u);
		if(c!=p){
			int val=1+ma[c];
			if(val>smax[u]) smax[u]=val;
			if(val>ma[u]){
				smax[u]=ma[u];
				ma[u]=val;
			}	
			longest=max(longest,ma[u]);
		}
	}

}

void dfs4(vector< set<int> > &a, int u){
	vis[u]=true;
	for(auto c : a[u]){
		if(!vis[c]){
			int up;
			if(ma[c]+1 != ma[u]) up=1+ma[u];
			else up=1+smax[u];
			if(up>smax[c]) smax[c]=up;
			if(up>ma[c]){
				smax[c]=ma[c];
				ma[c]=up;
			}	
			longest=max(longest,ma[c]);
			dfs4(a,c);
		}
	}
}


int main(){

	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);	

	int n,m;
	cin>>n>>m;

	a.resize(n);
	ra.resize(n);
	dead.resize(n);
	rev_dead.resize(n);

	visited.resize(n);
	vis.resize(n);

	ma.resize(n);
	smax.resize(n);

	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		addEdge(a,u,v);
		addEdge(ra,v,u);
	}

	int ans=0;
	queue<int> q;

	for(int i=0;i<n;i++){
		if(a[i].size()<=1) q.push(i);
	}

	while(!q.empty()){
		u=q.front();
		q.pop();

		if(!a[u].empty()){
			int v=*(a[u].begin());
			if(inadj(ra,u,v)){
				remove_from_a(a,v,u);
				remove_from_a(ra,u,v);
				addEdge(dead,v,u);;
				addEdge(rev_dead,u,v);
				ans++;
				if(a[v].size()<=1) q.push(v);
			}
		}
		else{
			set<int> parents = ra[u];
			for(int x : parents){
				remove_from_a(a,x,u);
				remove_from_a(ra,u,x);
				addEdge(dead,x,u);
				addEdge(rev_dead,u,x);
				ans++;
				if(a[x].size()<=1) q.push(x);
			}
		}
	}

	for(int i=0;i<n;i++) visited[i]=false;

	for(int i=0;i<n;i++) if(!visited[i]) dfs1(dead,i,s1);

	for(int i=0;i<n;i++) visited[i]=false;

	int count=0;
	while(!s1.empty()){
		int u=s1.top();
		s1.pop();
		if(!visited[u]){
			count++;
			dfs2(rev_dead,u,s2);
		}
	}

	for(int i=0;i<n;i++) visited[i]=false;

	for(int i=0;i<n;i++) vis[i]=false;

	while(!s2.empty()){
		int u=s2.top();
		s2.pop();
		if(!visited[u]){
			dfs3(dead,u,-1);
			dfs4(dead,u);
		}
	}

	cout<<ans<<" "<<max(longest-1,0)<<endl;
	
}
