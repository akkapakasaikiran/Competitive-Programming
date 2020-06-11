#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
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
vi label;
vvi labeltonode;

int main(){
	fastio;

	int n,m; cin>>n>>m;
	a.resize(n);
	labeltonode.resize(n+1);

	int u,v;
	rep(i,m){
		cin>>u>>v;
		ae(a,u-1,v-1);
		ae(a,v-1,u-1);
	}

	tkii(label,n);


	bool ok = true;
	rep(i,n){
		int cur = label[i];
		labeltonode[cur].pb(i);
		set<int> tmp;
		for(int x : a[i]) tmp.insert(label[x]);

		rep1(j,cur-1) if(tmp.find(j) == tmp.end()) ok = false;
		if(tmp.find(cur) != tmp.end()) ok = false;
	}

	if(!ok) cout<<-1<<endl;
	else{
		rep1(i,n) for(int x : labeltonode[i]) cout<<x+1<<" ";
		cout<<endl;
	}
	
}