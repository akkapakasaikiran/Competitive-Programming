#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define st string
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vii vector<int>::iterator
#define si set<int>
#define pb push_back

//////////////////////////////////////////

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

////////////////////////////////////////////

#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); }
}

#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
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

////////////////////////////////////////

vvi a;
vb vis;
vi subtreesize;

int ans;
void dfs(int u){
	vis[u]=true;
	subtreesize[u] = 1;
	for(int v : a[u]){
		if(!vis[v]){
			dfs(v);
			if(subtreesize[v]%2 == 0) ans++;
			subtreesize[u] += subtreesize[v];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;	
	a.resize(n+1); vis.resize(n+1); subtreesize.resize(n+1);

	int u,v;
	rep(i,n-1){
		cin>>u>>v;
		ae(a,u,v);
		ae(a,v,u);
	}

	ans = 0;
	dfs(1);
	if(n%2==1) cout<<-1<<endl;
	else cout<<ans<<endl;

}