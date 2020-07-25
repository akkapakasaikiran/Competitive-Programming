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

	int n,m; cin>>n>>m;
	set<string> ss;

	string s;
	rep(i,n){
		cin>>s; ss.insert(s);
	}

	set<string> s2; 

	int cnt = 0;
	for(set<string>::iterator it = ss.begin(); it != ss.end(); it++){
		string s = *it;
		reverse(all(s));
		if(ss.find(s) != it && && ss.find(s) != ss.end() && s2.find(*it) == s2.end()){
			cnt++;
			s2.insert(s);
		}
	}

	if(cnt == n/2){
		cout<<n*m<<endl;
		for(string s : s2) cout<<s;
		cout<<endl;	
	}

}
