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

bool match(string s){
	string m = "abacaba";
	rep(i,7) if(s[i] != '?' && s[i] != m[i]) return false;
	return true;
}

int main(){
	fastio;

	test(t){
		int n; cin>>n;
		string s; cin>>s;
		int cnt = 0;
		rep(i,n-6) if(s.substr(i,7) == "abacaba") cnt++;
		if(cnt == 1){
			rep(i,n) if(s[i] == '?') s[i] = 'd';
			cout<<"Yes"<<endl<<s<<endl;
		}
		else if(cnt > 1) cout<<"No"<<endl;
		else{
			rep(i,n-6) if(match(s.substr(i,7)) && cnt == 0){
				cnt++;
				string m = "abacaba";
				rep(j,7) if(s[i+j] == '?') s[i+j] = m[j];
				rep(i,n) if(s[i] == '?') s[i] = 'd';
				cout<<"Yes"<<endl<<s<<endl;
			}
			if(cnt == 0) cout<<"No"<<endl;
		}
	}
}