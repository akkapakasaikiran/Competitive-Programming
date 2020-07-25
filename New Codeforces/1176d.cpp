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



void seive(int n){
	
}

int main(){
	fastio;

	int n; cin>>n;
	vi b; tkii(b,2*n);
	multiset<int> bset;
	rep(i,2*n) bset.insert(b[i]);

	vb isprime(2750131+1, true);
	isprime[0] = isprime[1] = false;
	for(int i = 2; i <= 2750131; i++)
		if(isprime[i] && (ll)i*i <= 2750131)
			for(int j = i*i; j <= 2750131; j += i) isprime[j] = false;

	vi primes = {-1};
	rep1(i,2750131) if(isprime[i]) primes.pb(i);

	vi a;

	rep(i,2*n){
		if(b[i] != -1 && isprime[b[i]]){
			if(bset.find(primes[b[i]]) != bset.end()){
				a.pb(b[i]);
				bset.erase(bset.find(b[i]));
				bset.erase(bset.find(primes[b[i]]));
				cout<<b[i]<<" "<<primes[b[i]]<<" "<<lower_bound(all(b),b[i]) - b.begin()<<endl;
				b[lower_bound(all(b),b[i]) - b.begin()] = -1; b[i] = -1; 
			}
		}
	}

	prvi(b);
	prvi(a);
	for(int x : bset) cout<<x<<" ";
	cout<<endl;

}