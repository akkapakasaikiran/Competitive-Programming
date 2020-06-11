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

	test(t){
		int n,m; cin>>n>>m;
		vvi mat(n);

		vb rows(true,n);
		vb cols(true,m);

		int tmp;
		rep(i,n) rep(j,m){
				cin>>tmp;
				mat[i].pb(tmp);
		}

		rep(i,n) rep(j,m) if(mat[i][j] == 1){
			rows[i] = false;
			cols[j] = false;
		}

		int r = 0, c = 0;
		rep(i,n) if(rows[i]) r++;
		rep(i,m) if(cols[i]) c++;
		if( min(r,c) %2 == 0) cout<<"Vivek"<<endl;
		else cout<<"Ashish"<<endl;
	}
}