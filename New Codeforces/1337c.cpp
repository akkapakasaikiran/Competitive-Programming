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

void rsort(vector<int> &v){
	sort(v.begin(),v.end(),greater<int>());
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
vi depth;
vb industry;
vi numchil;

bool comp(int i, int j){
	return depth[i]-numchil[i] < depth[j]-numchil[j];
}

void dfs(int u, int par){
	for(int v : a[u]){
		if(v != par){
			if(!industry[v]) depth[v] = depth[u] + 1;
			else depth[v] = depth[u];
			dfs(v,u);
			numchil[u] += 1+numchil[v];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,k; cin>>n>>k;
	a.resize(n+1); depth.resize(n+1);
	industry.resize(n+1); numchil.resize(n+1);

	int u,v;
	rep(i,n-1){
		cin>>u>>v;
		ae(a,u,v); ae(a,v,u);
	}

	dfs(1,0);

	vi indices; rep1(i,n) indices.pb(i);
	sort(indices.begin(),indices.end(),comp);

	rep(i,k) industry[indices[n-1-i]] = true; 

	depth.clear(); depth.resize(n+1);
	dfs(1,0);

	ll h = 0;
	rep1(i,n) if(industry[i]) h += depth[i]+1;
	cout<<h<<endl;
}