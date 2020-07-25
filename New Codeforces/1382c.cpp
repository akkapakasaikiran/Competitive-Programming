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

int main(){
	fastio;

	test(t){
		int n; cin>>n;
		string aa,bb; cin>>aa>>bb;
		vi a,b;
		rep(i,n){
			if(aa[i] == '0') a.pb(0);
			else a.pb(1);
		}
		rep(i,n){
			if(bb[i] == '0') b.pb(0);
			else b.pb(1);
		}

		vi order(n);
		if(n%2 == 0){
			rep(i,n){
				if(i%2 == 0) order[i] = n/2 + i/2 ;
				else order[i] = n/2 - i/2 - 1;
			}
		}
		else{
			rep(i,n){
				if(i%2 == 0) order[i] = n/2 - i/2 ;
				else order[i] = n/2 + i/2 + 1; 
			}
		}
		// prvi(order);

		vi lens;
		for(int j = n-1; j >= 0; j--){
			if((n-j)%2 == 1){
				if(b[j] == a[order[j]]) lens.pb(1);
				lens.pb(j+1);
			}
			else{
				if(b[j] == 1 - a[order[j]]) lens.pb(1);
				lens.pb(j+1);
			}
		}

		cout<<lens.size()<<" ";
		prvi(lens);
	}
}