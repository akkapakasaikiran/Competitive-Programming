/* Author: Akkapaka Saikiran (@saikidon911) */
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
template <typename T> void take_input(vector<T> &a,int sz){
	T t;rep(i,sz){cin>>t;a.pb(t);}}
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){
	rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl;}
/////////////////////////////////////////

int main(){
	fastio;

	test(t){
		ll n, l, r; cin>>n>>l>>r;

		ll i = 1;
		while(i*(i-1)+1 < l) i++;
		ll init = i;
		
		vll mainvec;
		while(i*(i-1)+1 < r){
			vll vec;
			if(i == 1) vec.pb(1);
			else if(i == 2) vec = {2,1};
			else{
				for(int j = 2; j < i; j++){
					vec.pb(i); vec.pb(j);
				}
				vec.pb(i); vec.pb(1);
			}
			for(ll x : vec) mainvec.pb(x);
			i++;
		}
		vll vec;
		if(i == 1) vec.pb(1);
		else if(i == 2) vec = {2,1};
		else{
			for(int j = 2; j < i; j++){
				vec.pb(i); vec.pb(j);
			}
			vec.pb(i); vec.pb(1);
		}
		for(ll x : vec) mainvec.pb(x);

		for(ll i = max(0ll,l-(2+(init-2)*(init-1))); i <= max(r-l,r-(2+(init-2)*(init-1))); i++)
			cout<<mainvec[i]<<" ";
		cout<<endl;
		


	}
}