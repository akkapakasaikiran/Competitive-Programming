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

	test(t){
		int n,p,k; cin>>n>>p>>k;
		vi a; tkii(a,n);
		sort(all(a));
		int mon = 0;
		int i;
		for(i=1;i<n;i+=2){
			mon+=a[i];
			if(mon > p) break;
		} 
		i-=2;
		int ans = i+1;

		mon = 0;
		p-=a[0];
		if(p<0){ cout<<0<<endl; continue; }
		for(i=2;i<n;i+=2){
			mon+=a[i];
			if(mon > p) break;
		}
		i-=2;
		ans = max(ans,i+1);
		cout<<ans<<endl;

	}
}