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

	// set<int> s;
	// s.insert(1); s.insert(2); s.insert(4);
	// cout<<*s.lower_bound(3)<<endl;
	// cout<<(s.upper_bound(3) == s.end())<<endl;
	// cout<<(s.upper_bound(5) == s.end())<<endl;
	// cout<<*s.upper_bound(5)<<endl;


	test(t){
		int n; cin>>n;
		vi b; tkii(b,n);
		vb vis(2*n+1);
		rep(i,n) vis[b[i]] = true;

		set<int> notb;
		rep1(i,2*n) if(!vis[i]) notb.insert(i);

		bool ok = true;
		vi a(2*n);
		rep(i,n){
			a[2*i] = b[i];
			if(notb.lower_bound(b[i]) == notb.end()){
				ok = false;
				break;
			}
			else{
				a[2*i+1] = *notb.lower_bound(b[i]);
				notb.erase(*notb.lower_bound(b[i]));
			}
		}

		if(ok) prvi(a);
		else cout<<-1<<endl;	
	}
}