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

vvi a;
vb vis;

vi prep, p, happy;

void dfs1(int u){
	vis[u] = true;
	prep[u] = p[u];
	for(int v : a[u]) if(!vis[v]){
		dfs1(v);
		prep[u] += prep[v];
	}
}


bool dfs2(int u){
	vis[u] = true;
	int h = 0;
	bool ok = true;
	for(int v : a[u]) if(!vis[v]){
		if(!dfs2(v)) ok = false;
		else h += happy[v];
	}
	
	//cout<<u<<" "<<(happy[u] >= h)<<endl;
	if(!ok) return ok;
	else return (happy[u] >= h);
}

int main(){
	fastio;

	test(t){
		int n,m; cin>>n>>m;
		a.clear(); vis.clear();
		a.resize(n+1); vis.resize(n+1);

		p = {-1}; tkii(p,n);
		vi h = {-1}; tkii(h,n);

		int u,v;
		rep(i,n-1){
			cin>>u>>v;
			a[u].pb(v);
			a[v].pb(u);
		}

		prep.clear(); prep.resize(n+1);
		dfs1(1);

		//prvi(prep);
		happy.clear(); happy.resize(n+1);

		bool ok = true;
		rep1(i,n){
			if(abs(h[i])%2 != prep[i]%2 || h[i] > prep[i] || h[i] < -prep[i]){
				ok = false;
				break;
			}
			else happy[i] = prep[i] - (prep[i]-h[i])/2;
		}
		if(!ok) cout<<"No"<<endl;
		else{

			//prvi(happy);

			vis.clear(); vis.resize(n+1);
			ok = dfs2(1);
			if(ok) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;

		}

	}
}