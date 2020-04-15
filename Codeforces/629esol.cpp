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
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vii vector<int>::iterator
#define si set<int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

//////////////////////////////////////////

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

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
	rep(i,v.size()) ans=max(ans,v[i]);
	return ans;
}

#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
}

#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

////////////////////////////////////////

int T=0;
vvi a;
vi depth;
vi parent;
vi tin;
vi tout;

void dfs(int u, int par = -1) {
	tin[u] = T++;
	for (auto v : a[u]){
		if (v == par) continue;
		else{
			parent[v]=u;
			depth[v]=1+depth[u];
			dfs(v,u);
		}
	}
	tout[u] = T++;
}

bool ancestor(int u, int v){
	return tin[u]<tin[v] && tout[u]>tout[v];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,m; cin>>n>>m;
	a.resize(n+1); depth.resize(n+1); parent.resize(n+1);
	int u,v;
	rep(i,n-1){
		cin>>u>>v;
		ae(a,u,v);
		ae(a,v,u);
	}	
	cout<<"dfs not done"<<endl;
	dfs(1);
	cout<<"dfs done"<<endl;
	prvi(parent);

	rep(i,m){
		int k,u; si vset;
		cin>>k;
		rep(j,k){ 
			cin>>u;
			vset.insert(u);
		}


		int deepest=1;
		int maxdepth=0;
		for(int u : vset){
			if(depth[u] > maxdepth){
				maxdepth = depth[u];
				deepest = u;
			}
		}

		v = deepest;
		for(int v)


	}
	
}