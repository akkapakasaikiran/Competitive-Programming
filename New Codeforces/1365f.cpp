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
		int n; cin>>n;
		vi a; tkii(a,n);
		vi b; tkii(b,n);

		vi a2 = a, b2 = b;
		sort(all(a2)); 
		sort(all(b2));
		if(a2 != b2) cout<<"No"<<endl;
		else if(n%2 == 1 && a[n/2] != b[n/2]) cout<<"No"<<endl;
		else{
			vector<pair<int,int> > ap, bp;
			rep(i,n/2){
				if(a[i] < a[n-i-1]) ap.pb(make_pair(a[i], a[n-i-1]));
				else ap.pb(make_pair(a[n-i-1], a[i]));
			}
			rep(i,n/2){
				if(b[i] < b[n-i-1]) bp.pb(make_pair(b[i], b[n-i-1]));
				else bp.pb(make_pair(b[n-i-1], b[i]));
			}
			sort(all(ap));
			sort(all(bp));
			if(ap != bp) cout<<"No"<<endl;
			else cout<<"yes"<<endl;
		}
	}
}