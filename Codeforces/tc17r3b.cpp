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
#define si set<int>
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


	st s,t; cin>>s>>t;
	vi a(27);
	rep(i,s.size()){
		if(a[s[i]-96]==0 && a[t[i]-96]==0){
			a[s[i]-96]=t[i]-96;
			a[t[i]-96]=s[i]-96;
		} 
		else if(a[s[i]-96]==t[i]-96 
				&& a[t[i]-96]==s[i]-96){} 
		else{ cout<<-1<<endl; return 0; }			
	}

	st abcd = "abcdefghijklmnopqrstuvwxyz";
	int cnt = 0; 
	set<si> pairs;
	rep1(i,26){
		if(a[i]!=0 && i!=a[i]){
			si tmp; tmp.insert(i); tmp.insert(a[i]);
			pairs.insert(tmp);
		}
	}
	cout<<pairs.size()<<endl;
	for(si p : pairs){
		cout<<abcd[*p.begin()-1]<<" ";
		cout<<abcd[*(++p.begin())-1]<<endl;
	}
}