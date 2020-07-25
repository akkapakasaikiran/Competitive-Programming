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

	int n; cin>>n;
	vi a; tkii(a,n);
	map<int,int> cnt;

	rep(i,n){
		if(cnt.find(a[i]) == cnt.end()) cnt[a[i]] = 1;
		else cnt[a[i]]++;
	}

	bool ok = true;
	for(pair<int,int> p : cnt) if(p.second > 2) ok = false;

	if(!ok) cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		set<int> s1, s2;
		for(pair<int,int> p : cnt){
			s1.insert(p.first);
			if(p.second == 2) s2.insert(p.first);
		}
		cout<<s1.size()<<endl;
		for(int x : s1) cout<<x<<" ";
		cout<<endl;
		cout<<s2.size()<<endl;
		for(auto it = s2.rbegin(); it != s2.rend(); it++) cout<<*it<<" ";
		cout<<endl;
	}
}