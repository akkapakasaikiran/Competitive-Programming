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

void swap(string &s, int i, int j){
	char tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

int main(){
	fastio;

	int n; cin>>n;
	string s; cin>>s;

	int cnt = 0;
	rep(i,n){
		if(s[i] == '(') cnt++;
		else cnt--;
	}
	if(cnt != 0) cout<<0<<endl<<1<<" "<<1<<endl;
	else{
		int ans = 0;
		int l, r;
		rep(i,n) rep(j,n) if(i != j){
			swap(s,i,j);
			vi pre(n+1);
			rep(i,n){
				if(s[i] == '(') pre[i+1] = pre[i] + 1;
				else pre[i+1] = pre[i] - 1;
			}
			int mini = 0;
			rep1(i,n) mini = min(mini, pre[i]);
			int minicnt = 0;
			rep1(i,n) if(pre[i] == mini) minicnt++;
			if(minicnt > ans){
				ans = minicnt;
				l = i + 1; r = j + 1;
			}
			swap(s,j,i);
		}
		cout<<ans<<endl;
		cout<<l<<" "<<r<<endl;	
	}

	

}