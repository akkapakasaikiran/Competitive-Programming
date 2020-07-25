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

vi a;

int ans(int l, int r, int x){
	if(l == r-1){
		if(a[l] != x) return 1;
		else return 0;
	}
	else{
		int lc = 0, rc = 0;
		for(int i = l; i < (l+r)/2; i++) if(a[i] != x) lc++;	
		for(int i = (l+r)/2; i < r; i++) if(a[i] != x) rc++;
		int answ = min(lc + ans((l+r)/2,r,x+1), ans(l,(l+r)/2,x+1) + rc);
		return answ;
	}
}

int main(){
	fastio;

	test(t){
		a.clear();
		int n; cin>>n;
		string s; cin>>s;

		a.clear();
		rep(i,n) a.pb(s[i] - 'a');

		cout<<ans(0,n,0)<<endl;

	}
}