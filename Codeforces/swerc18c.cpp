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
}

#define prg print_graph
void print_graph(vector<vi> &a){
	rep(i,a.size()){ cout<<i<<" : "; prvi(a[i]); }
}

/////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int w,h; cin>>w>>h;
	int ans = w-1;
	int n; cin>>n;
	int x,y;

	vector<pii> points;
	rep(i,n){
		cin>>x>>y; points.pb(mp(x,y));
	}
	
	vi minext,maxext;
	rep(i,n) minext.pb(-1);
	rep(i,n) maxext.pb(-1);

	rep(i,n){
		x = points[i].fi;
		y = points[i].se;
		if(minext[x] == -1){ minext[x] = y; maxext[x] = y; }
		else {
			minext[x]=min(minext[x],y);
			maxext[x]=max(maxext[x],y);
		} 
	}

	vi ext;
	rep(i,n) if(maxext[i]!=-1) ext.pb(maxext[i]);
	rep(i,n) if(minext[i]!=-1) ext.pb(minext[i]);
	sort(all(ext));
	int med = ext[ext.size()/2];
	
	rep(i,n){
		if(minext[i]!=-1){
			if(maxext[i] >= med && minext[i] <= med)
				ans+=2*(maxext[i]-minext[i]);
			else ans+=2*max(abs(med-minext[i]),abs(med-maxext[i]));
		}
	}

	cout<<ans<<endl;
	
}