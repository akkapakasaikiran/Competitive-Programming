#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>; using vll = vector<long long>; 
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

	int n; cin>>n;
	vi a; tkii(a,n);

	set<int> there;
	rep(i,n) there.insert(a[i]);
	if(there.size() == n) cout<<0<<endl;
	else{
		int pre;
		int minlen = n-1;
		rep(i,n){
			there.clear();
			rep(j,i) there.insert(a[j]);
			if(there.size() < i) continue;
			else{
				for(int k = n-1; k > i; k--){
					if(there.find(a[k]) != there.end()) break;
					else there.insert(a[k]);
				}
				int sz = there.size();
				if(minlen > n-sz){
					minlen = n-sz;
				}	
			}
			
		}
		cout<<minlen<<endl;
	}
		
}