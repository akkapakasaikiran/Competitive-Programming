#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
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

	int n,m,k; cin>>n>>m>>k;

	vi moves;
	rep(i,n){
		if(i%2==0){
			rep(j,m){
				moves.pb(i+1);
				moves.pb(j+1);
			}
		}
		else{
			for(int j = m-1; j>=0; j--){
				moves.pb(i+1);
				moves.pb(j+1);
			}
		}
	}

	//prvi(moves);

	rep(i,k-1){
		cout<<2<<" ";
		cout<<moves[4*i]<<" "<<moves[4*i+1]<<" ";
		cout<<moves[4*i+2]<<" "<<moves[4*i+3]<<endl;
	}

	cout<<n*m-2*(k-1)<<" "; 
	for(int i = 4*(k-1); i < 2*n*m; i++){
		cout<<moves[i]<<" ";
	}
	cout<<endl;
}