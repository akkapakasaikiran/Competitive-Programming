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

	string s1, s2; cin>>s1>>s2;
	int s = 60*stoi(s1.substr(0,2)) + stoi(s1.substr(3,2));
	int e = 60*stoi(s2.substr(0,2)) + stoi(s2.substr(3,2));
	int m = (s+e)/2;
	int h = m/60;
	int mi = m%60;
	string hh,mmi;
	if(h < 10) hh = "0"+to_string(h);
	else hh = to_string(h);
	if(mi < 10) mmi = "0"+to_string(mi); 
	else mmi = to_string(mi);

	cout<<hh<<":"<<mmi<<endl;

}