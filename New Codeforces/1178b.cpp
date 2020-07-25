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

	string s; cin>>s;
	int n = s.size();

	s = 'o' + s + 'o';

	string t;
	rep1(i,n) if(!(s[i] == 'v' && s[i-1] == 'o' && s[i+1] == 'o')){
		t.pb(s[i]);
	}

	int back = t.size()-1;
	while(t[back] == 'o') back--;
	int front = 0;
	while(t[front] == 'o') front++;

	string a;
	rep(i,t.size()) if(i >= front && i <= back) a.pb(t[i]);

	n = a.size();
	vi vs, os;

	int curcnt = 0;
	char prev = 'v';
	rep(i,n){
		if(a[i] == prev) curcnt++;
		else{
			if(a[i] == 'o') vs.pb(curcnt-1);
			else os.pb(curcnt);
			curcnt = 1;
			prev = a[i];
		}
	}
	vs.pb(curcnt-1);

	vi presum = {vs[0]};
	rep1(i,vs.size()-1) presum.pb(presum.back()+vs[i]);

	ll ans = 0;
	rep(i,os.size()) ans += 1ll*presum[i]*os[i]*(presum.back()-presum[i]);

	cout<<ans<<endl;

}