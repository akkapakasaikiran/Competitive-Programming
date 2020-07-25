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
		string s; cin>>s;
		map<char,int> cnt;
		for(char c : s){
			if(cnt.find(c) == cnt.end()) cnt[c] = 1;
			else cnt[c]++;
		}

		int maxcnt = 0;
		char most;
		for(pair<char,int> p : cnt) if(p.second > maxcnt){
			most = p.first;
			maxcnt = p.second;
		}

		char ans;
		if(most == 'R') ans = 'P';
		else if(most == 'P') ans = 'S';
		else ans = 'R';

		rep(i,s.size()) cout<<ans;
		cout<<endl; 
	}
}