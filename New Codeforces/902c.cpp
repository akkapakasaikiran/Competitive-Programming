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
template <typename T> void take_input(vector<T> &a, int size){ T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); } }
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){ for(int i=0;i<v.size();i++){ cout<<v[i]<<" "; } cout<<endl; }
/////////////////////////////////////////

int main(){
	fastio;

	int h; cin>>h;
	vi a; tkii(a,h+1);

	bool unique = true;
	rep(i,h) if(a[i] > 1 && a[i+1] > 1) unique = false;

	if(unique) cout<<"perfect"<<endl;
	else{
		cout<<"ambiguous"<<endl;
		vi p; p.pb(0);
		int prev = 1;
		rep1(i,h){
			rep(j,a[i]) p.pb(prev);
			prev += a[i-1]; 
		}
		prvi(p);

		p.clear(); p.pb(0);
		prev = 1;
		rep1(i,h){
			if(a[i] > 1 && a[i-1] > 1){
				p.pb(prev);
				rep(j,a[i]-1) p.pb(prev+1);
			}
			else rep(j,a[i]) p.pb(prev);

			prev += a[i-1]; 
		}
		prvi(p);
	}
}