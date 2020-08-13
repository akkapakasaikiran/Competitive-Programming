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
	map<int,int> cnt;
	vi a; tkii(a,n);
	rep(i,n){
		if(cnt.find(a[i]) == cnt.end()) cnt[a[i]] = 1;
		else cnt[a[i]]++;
	}

	multiset<int, greater<int> > cnts;
	for(pair<int,int> p : cnt) cnts.insert(p.second);
	
	int q; cin>>q;
	while(q--){
		char c; cin>>c; int x; cin>>x;
		if(c == '-'){
			cnts.erase(cnts.find(cnt[x]));
			cnt[x]--;
			cnts.insert(cnt[x]);
		}
		else{
			if(cnt.find(x) == cnt.end()){
				cnt[x] = 1;
				cnts.insert(cnt[x]);
			}
			else{
				cnts.erase(cnts.find(cnt[x]));
				cnt[x]++;
				cnts.insert(cnt[x]);
			}
		}
			
		// cout<<"cnts: ";
		// for(int x : cnts) cout<<x<<" ";
		// cout<<endl;

		if(cnts.size() == 1){
			if(*cnts.begin() >= 8) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else if(cnts.size() == 2){
			auto f = cnts.begin();
			auto s = cnts.begin(); s++;
			if(*f >= 8 || (*f >= 4 && *s >= 4) || (*f >= 6 && *s >= 2))
				cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else{
			auto f = cnts.begin();
			auto s = cnts.begin(); s++;
			auto t = cnts.begin(); t++; t++;
			if(*f >= 8 || (*f >= 4 && *s >= 4) || (*f >= 4 && *s >= 2 && *t >= 2) || (*f >= 6 && *s >= 2))
				cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		} 
	} 
}