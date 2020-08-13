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
		int n,k; cin>>n>>k;
		int l1,r1, l2,r2; cin>>l1>>r1>>l2>>r2;

		if(l1 > l2){
			int tmp = l1; l1 = l2; l2 = tmp;
			tmp = r1; r1 = r2; r2 = tmp;
		}

		ll steps, val;
		if(r1 <= l2){ // no intersection
			int d = l2 - r1;
			int ls = r1 - l1, rs = r2 - l2;
			val = d + ls + rs;
			steps = val + d;
			if(k < n*val) cout<<(k/val)*steps + min((k%val)+d, 2*(k%val))<<endl;
			else cout<<n*val + 2*(k - n*val)<<endl;
		}
		else{
			int ls, inter, rs;
			if(r2 > r1){ ls = l2 - l1; rs = r2 - r1; inter = r1 - l2; }
			else{ ls = l2 - l1; rs = r1 - r2; inter = r2 - l2; }
			val = ls + rs + inter;
			steps = ls + rs;

			if(k - n*inter <= n*(val - inter)) cout<<max(0,k - n*inter)<<endl; 
			else cout<<k - n*inter + 2*(k - n*val)<<endl;
		}


	}
}