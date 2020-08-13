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

const ll mod = 1e9+7;

ll binmodexp(ll a, ll b){
	if(b == 0) return 1;
	else if(b%2 == 0) return binmodexp((a*a)%mod, b/2);
	else return (a * binmodexp((a*a)%mod, b/2))%mod;
}

int main(){
	fastio;

	ll x,n; cin>>x>>n;
	ll tmp = x;

	set<int> primes;

	for(int i = 2; i*i < x; i++){
		while(tmp%i == 0){
			primes.insert(i);
			tmp /= i;
		}
	}

	for(int p : primes) cout<<p<<" ";
	cout<<endl;

	ll ans = 0;
	for(int p : primes){
		ll poww = 1;
		ll cnt = 0;
		while(poww < LLONG_MAX/p && n/(poww*p) != 0){
			poww *= p;
			cnt = (cnt + n/poww)%mod;
		}
		ans += binmodexp(p, cnt);
	}
	cout<<ans<<endl;

}