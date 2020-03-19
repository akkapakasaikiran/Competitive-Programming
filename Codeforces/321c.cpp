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

////////////////////////////////////////

#define ae add_edge
void add_edge(vector<vi> &a, int u, int v){
	a[u].pb(v);
	a[v].pb(u);
}

#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

////////////////////////////////////////

int n,m; 
vvi adj;
vb cat;
vi cnt;
int ans = 0;

void dfs(int u){
	if(adj[u].size()==1 && u!=1) ans++; 
	else {
		for(int v : adj[u]){
			if(cnt[v]==-1){
				if(cat[v]) cnt[v]=cnt[u]+1;
				else cnt[v]=0;
				if(cnt[v]<=m) dfs(v); 
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;	
	adj.resize(n+1);
	cnt.resize(n+1,-1);
	cat.resize(n+1);

	vi a; tkii(a,n);
	rep(i,n){
		if(a[i]==1) cat[i+1]=true;
		else cat[i+1]=false;
	}

	int x,y;
	rep(i,n-1){
		cin>>x>>y;
		ae(adj,x,y);
	}

	if(cat[1]) cnt[1]=1;
	else cnt[1]=0;
	dfs(1);

	cout<<ans<<endl;
}