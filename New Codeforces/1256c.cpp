#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define llmax 9223372036854775807
#define intmax 2147483647
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll mod = 1e9+7;
#define all(v) v.begin(),v.end()
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

	int n,m,d; cin>>n>>m>>d;
	vi c; tkii(c,m);

	int s = 0;
	rep(i,m) s += c[i];

	if(d == 1){
		if(s < n) cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			rep(i,m){
				rep(j,c[i]) cout<<i+1<<" ";
			}
			cout<<endl;
		}
	}
	else{
		int empty = n-s;
		int full = empty/(d-1);
		int half = empty%(d-1);

		if(half == 0){
			if(full > (m+1)) cout<<"NO"<<endl;
			else{
				cout<<"YES"<<endl;
				rep(i,m){
					if(full != 0){
						rep(j,d-1) cout<<0<<" ";
						full--;
					}
					rep(j,c[i]) cout<<i+1<<" ";
				}
				if(full == 1) rep(j,d-1) cout<<0<<" ";
				cout<<endl;
			}
		}
		else{
			if(full > m) cout<<"NO"<<endl;
			else{
				cout<<"YES"<<endl;
				rep(j,half) cout<<0<<" ";
				rep(j,c[0]) cout<<1<<" ";
				rep1(i,m-1){
					if(full != 0){
						rep(j,d-1) cout<<0<<" ";
						full--;
					}
					rep(j,c[i]) cout<<i+1<<" ";			
				}
				if(full == 1) rep(j,d-1) cout<<0<<" ";
				cout<<endl;
			}
		}
	}
	
}