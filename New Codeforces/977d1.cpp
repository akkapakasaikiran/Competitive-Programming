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

pair<int,int> factorize(ll n){
	int two = 0, three = 0;
	while(n%2 == 0){
		two++;
		n /= 2;
	}
	while(n%3 == 0){
		three++;
		n /= 3;
	}
	return make_pair(two,three);
}

bool comp(ll n1, ll n2){
	pair<int,int> p1 = factorize(n1);
	pair<int,int> p2 = factorize(n2);
	return p1.first-p1.second < p2.first-p2.second;
}

int main(){
	fastio;

	int n; cin>>n;
	vll a; tki<ll>(a,n);

	sort(all(a), comp);
	prv<ll>(a);

}