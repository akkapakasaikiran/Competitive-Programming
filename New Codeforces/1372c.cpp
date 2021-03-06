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

		int cnt = 0;
		vb inpos(n);
		rep(i,n) if(a[i] == i+1){
			inpos[i] = true;
			cnt++;
		}

		if(cnt == n) cout<<0<<endl;
		else if(cnt == 0) cout<<1<<endl;
		else{
			int state = 0;
			bool ok = true;
			rep(i,n){
				if(!inpos[i]){
					if(state == 0) state = 1;
					else if(state == 2) ok = false;
				}
				else{
					if(state == 1) state = 2;
				}
			}
			if(ok) cout<<1<<endl;
			else cout<<2<<endl;
		}
	}
}