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

ll binmodexp(ll a, ll b, ll m){
	if(b == 0) return 1;
	else if(b%2 == 0) return binmodexp((a*a)%m,b/2,m);
	else return (a*binmodexp((a*a)%m,b/2,m))%m;
}

const int mod = 998244353;


int main(){
	fastio;

	int n; cin>>n;
	vvi a(n);
	int k;
	rep(i,n){
		cin>>k; tkii(a[i],k);
	}

	map<int, int> cnt;
	rep(i,n) for(int v : a[i]){
		if(cnt.find(v) == cnt.end()) cnt[v] = 1;
		else cnt[v]++;
	}

	ll num = 0;
	for(pair<int,int> p : cnt) num += p.second*p.second;

	ll sumk = 0;
	rep(i,n) sumk += a[i].size();
	ll denom = sumk * n;

	//cout<<num<<" "<<denom<<endl;

	ll inv = binmodexp(denom, mod-2, mod);
	cout<<inv<<endl;

	cout<<binmodexp(3,5,7)<<endl;

	//cout<<(num%mod*inv)%mod<<endl;


	
}