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
		int n,m; cin>>n>>m;
		vi t = {0}, l = {0}, r = {0};

		int a,b,c;
		rep(i,n){
			cin>>a>>b>>c;
			t.pb(a);
			l.pb(b);
			r.pb(c);
		}

		bool ok = true;
		int mini = m, maxi = m;
		rep1(i,n){
			mini -= t[i]-t[i-1];
			maxi += t[i]-t[i-1];
			if(!(l[i] > maxi || r[i] < mini)){
				mini = max(mini, l[i]);
				maxi = min(maxi, r[i]);
			} 
			else{
				ok = false;
				break;
			}
		}

		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}