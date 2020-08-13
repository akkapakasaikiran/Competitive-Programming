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


map<int,int> cnt;

ll count(ll x, ll n){
	if(cnt.find(x) == cnt.end()){
		if(x > n) cnt[x] = 0;
		else if(x%2 == 0) cnt[x] = 1 + count(x+1,n) + count(2*x,n);
		else cnt[x] = 1 + count(2*x, n); 
	}
	return cnt[x];
}

ll binsearch(ll l, ll r, ll k, ll n){
	if(r-l == 2){
		if(count(r,n) >= k) return r;
		else if(count(l,n) >= k) return l;
		else return -1;
	}
	else{
		ll m = (l+r)/2;
		if(m%2 != l%2) m--;	
		if(count(m,n) >= k) return binsearch(m,r,k,n);
		else binsearch(l,m,k,n);
	}
}


int main(){
	fastio;

	ll n,k; cin>>n>>k;

	cnt.empty();

	if(n == 1) cout<<1<<endl;
	else if(n == 2 || n == 3) cout<<n+1-k<<endl;
	else if(n%2 == 0){
		ll l = 1, r = n-1, m;
		while(r-l > 2){
			m = (l+r)/2;
			if(m%2 != l%2) m--;	
			if(count(m,n) >= k) l = m;
			else r = m;
		}

		if(count(r,n) >= k) return r;
		else if(count(l,n) >= k) return l;
		else return -1;

		cout<<max(binsearch(1,n-1,k,n), binsearch(2,n,k,n))<<endl;
	else cout<<max(binsearch(1,n,k,n), binsearch(2,n-1,k,n))<<endl;

	//cout<<count(10,10)<<endl;


}