#include<iostream>
#include<vector>
#include<list>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#define ll long long
#define st string
#define vi vector<int>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vii vector<int>::iterator
#define pb push_back
#define all(v) v.begin(),v.end()

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define forv(v) for(auto x : v)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))

void swap(int &x, int &y){
	int tmp = x; x = y; y= tmp;
}

////////////////////////////////////////////

#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	T tmp;
	for(int i=0;i<size;i++){
		cin>>tmp;
		a.push_back(tmp);
	}
}

#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

int vmax(vi v){ //positivity assumed
	int ans = 0;
	rep(i,v.size()) if(v[i]>ans) ans = v[i];
	return ans;
}

////////////////////////////////////////

#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
}
#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

/////////////////////////////////////////

vvi adj;
vb vis;
vi ans;
vi roots;
vi c;

void dfs(int u){
	vis[u]=true;
	ans[u]=c[u];
	for(int  v : adj[u]){
		if(!vis[v]) dfs(v);
		if(ans[v]<ans[u]) ans[u]=ans[v];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,m; cin>>n>>m;
	c.pb(-1); tkii(c,n);
	adj.resize(n+1);
	vis.resize(n+1);
	ans.resize(n+1);

	int u,v;
	rep(i,m){
		cin>>u>>v; ae(adj,u,v); ae(adj,v,u);
	}

	//prg(adj);

	rep1(i,n){
		if(!vis[i]){
			roots.pb(i); dfs(i);
		}
	}
	ll out=0;
	for(int x : roots) out+=ans[x];
	cout<<out<<endl; 
}