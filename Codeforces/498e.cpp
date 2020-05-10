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
vi dfsnum;
vi dfsfinnum;
vi subtreesize;
vi preorder;

int s,e;

void dfs(int u){
	vis[u] = true;
	dfsnum[u] = s++;
	preorder.pb(u);
	subtreesize[u] = 1;
	for(int v : a[u]){
		if(!vis[v]){
			dfs(v);
			subtreesize[u] += subtreesize[v];
		}
	}
	dfsfinnum[u] = e++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,q; cin>>n>>q;
	a.resize(n); vis.resize(n); dfsnum.resize(n); dfsfinnum.resize(n); subtreesize.resize(n);

	vi par; tkii(par,n-1);
	rep(i,n-1) ae(a,par[i]-1,i+1);
	
	rep(i,n) sort(a[i].begin(),a[i].end());

	s=1; e = 1;
	dfs(0);

	rep(i,q){
		int u,k; cin>>u>>k;
		if(k > subtreesize[u-1]) cout<<-1<<endl;
		else cout<<preorder[dfsnum[u-1]+k-2]+1<<endl;
	}
}