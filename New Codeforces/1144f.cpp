/* Author: Akkapaka Saikiran (@saikidon911) */
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>; using vll = vector<long long>; 
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define all(v) v.begin(),v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//////////////////////////////////////////
#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
////////////////////////////////////////////
#define tki take_input 
#define tkii take_input<int>
template <typename T> void take_input(vector<T> &a,int sz){
	T t;rep(i,sz){cin>>t;a.pb(t);}}
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){
	rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl;}
/////////////////////////////////////////
#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
}

#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

vvi a; 
vb vis;
vi color;

void dfs(int u){
	vis[u] = true;
	for(int v : a[u]) if(!vis[v]){
		color[v] = 1-color[u];
		dfs(v);
	}
}

bool check(vector<pair<int,int> > edges){
	for(pair<int,int> p : edges) if(color[p.first] == color[p.second]) return false;
	return true; 
}

int main(){
	fastio;

	int n,m; cin>>n>>m;
	a.resize(n+1); vis.resize(n+1); color.resize(n+1);
	vector<pair<int,int> > edges;

	int u,v; 
	rep(i,m){
		cin>>u>>v;
		edges.pb(make_pair(u,v));
		ae(a,u,v);
		ae(a,v,u);
	}

	color[1] = 0;
	dfs(1);

	if(!check(edges)) cout<<"No"<<endl;
	else{
		cout<<"YES"<<endl;
		for(pair<int,int> p : edges) cout<<color[p.first];
		cout<<endl;
	} 

}