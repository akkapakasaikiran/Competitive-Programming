#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>; using vll = vector<long long>; 
using vvi = vector<vector<int> >; using vb = vector<bool>;
using pii = pair<int,int>; 
#define pb push_back
#define all(v) v.begin(),v.end()
#define llmax 9223372036854775807
#define intmax 2147483647
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll mod = 1e9+7;
//////////////////////////////////////////
#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
////////////////////////////////////////////
#define tki take_input 
#define tkii take_input<int>
template <typename T> void take_input(vector<T> &a, int size){ T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); } }
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){ for(int i=0;i<v.size();i++){ cout<<v[i]<<" "; } cout<<endl; }
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
vvi c;

ll cost(int u, int c1, int v, int c2){
	if(a[v].size() == 1){
		return (ll)c[c1-1][u] + (ll)c[c2-1][v];
	} 
	else{
		int z;
		if(a[v][0] == u) z = a[v][1];
		else z = a[v][0];
		return c[c1-1][u] + cost(v,c2,z,6-c1-c2); 
	}
}

int main(){
	fastio;

	int n; cin>>n;
	a.resize(n+1); vis.resize(n+1);

	c.resize(3);
	rep(i,3){
		c[i].pb(-1);
		tkii(c[i],n);
	}

	int u,v;
	rep(i,n-1){
		cin>>u>>v;
		ae(a,u,v);
		ae(a,v,u);
	}

	bool ok = true;
	rep1(i,n) if(a[i].size() > 2) ok = false;
	if(!ok) cout<<-1<<endl;
	else{
		int u;
		rep1(i,n) if(a[i].size() == 1) u = i;
		int v = a[u][0];

		vll ans;
		ans.pb(cost(u,1,v,2));
		ans.pb(cost(u,1,v,3));
		ans.pb(cost(u,2,v,1));
		ans.pb(cost(u,2,v,3));
		ans.pb(cost(u,3,v,1));
		ans.pb(cost(u,3,v,2));

		vi f = {1,1,2,2,3,3};
		vi s = {2,3,1,3,1,2};

		ll anss = ans[0];
		int first, second;
		rep(i,6) if(ans[i] <= anss){
			anss = ans[i];
			first = f[i];
			second = s[i];
		}

		cout<<anss<<endl;
		vi colors(n+1);
		colors[u] = first;
		colors[v] = second;
		int z;

		rep(i,n-2){
			if(a[v][0] == u) z = a[v][1];
			else z = a[v][0]; 
			colors[z] = 6-colors[u]-colors[v];
			u = v;
			v = z;
		}

		rep1(i,n) cout<<colors[i]<<" ";
		cout<<endl;
	}

}