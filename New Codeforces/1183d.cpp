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
		vi a; tkii(a,n);

		map<int,ll> cnt;
		for(int x : a){
			if(cnt.find(x) == cnt.end()) cnt[x] = 1;
			else cnt[x]++;
		}

		vector<int> cnts;
		for(pair<int,int> p : cnt) cnts.pb(p.second);

		sort(all(cnts));
		prvi(cnts);
		cnt.clear();
		for(int x : cnts){
			if(cnt.find(x) == cnt.end()) cnt[x] = 1;
			else cnt[x]++;
		}
		
		ll ans = 0;
		set<int, greater<int>> free;
		rep1(i,n) free.insert(i);
		for(int x : free) cout<<x<<" ";
		cout<<endl;

		for(pair<int,int> p : cnt){
			int times = 0;
			set<int>::iterator it = free.find(p.first);
			for(set<int>::iterator it = free.find(p.first);
			it != free.end(); it++){
				ans += *it;
				free.erase(*it);
				times++;
				for(int x : free) cout<<x<<" ";
				cout<<endl;
				if(times == p.second) break;
			}
		}
		cout<<ans<<endl;

	}
}