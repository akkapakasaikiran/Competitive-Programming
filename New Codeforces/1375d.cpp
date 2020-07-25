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

int mex(vi a){
	set<int> aset;
	rep(i,a.size()) aset.insert(a[i]);
	int ret;
	rep(i,a.size()+1) if(aset.find(i) == aset.end()){
		ret = i;
		break;
	}
	return ret;
}

int unfixed(vi a){
	rep(i,a.size()) if(a[i] != i) return i;
}

int main(){
	fastio;

	test(t){
		int n; cin>>n;
		vi a; tkii(a,n);

		vi fixed;
		rep(i,n) fixed.pb(i);

		vi indices;
		while(a != fixed){
			if(mex(a) == n){
				indices.pb(unfixed(a));
				a[indices.back()] = n;
			}
			indices.pb(mex(a));
			a[indices.back()] = indices.back();
		}

		cout<<indices.size()<<endl;
		for(int i : indices) cout<<i+1<<" ";
		cout<<endl;

	}
}