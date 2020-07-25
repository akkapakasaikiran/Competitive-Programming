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
		vi cnt(26);	
		string s; cin>>s;
		for(char c : s) cnt[c-'a']++;

		bool ok = true;
		int l = -1,r = -1;
		rep(i,26){
			if(cnt[i] == 1){
				if(l == -1) l = i;
				r = i;	
			}
			else if(cnt[i] > 1) ok = false;
		}
		
		rep(i,26) if(i >= l && i <= r && cnt[i] != 1) ok = false;

		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}


}