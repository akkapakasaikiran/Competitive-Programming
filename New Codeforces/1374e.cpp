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

	int n,k; cin>>n>>k;
	vi ab,a,b;
	
	int t1, a1, b1; 
	rep(i,n){
		cin>>t1>>a1>>b1;
		if(a1 == 1 && b1 == 1) ab.pb(t1);
		else if(a1 == 1) a.pb(t1);
		else if(b1 == 1) b.pb(t1);
	}

	sort(all(ab));
	sort(all(a));
	sort(all(b));

	int ans = 0;
	int i = 0, j = 0;
	while(k != 0 && !(i >= ab.size() && j >= min(a.size(), b.size()))){
		if(j >= min(b.size(), a.size()) ||
		(i < ab.size() && ab[i] < a[j] + b[j])){
			ans += ab[i];
			k--;
			i++;
		}
		else{
			ans += a[j] + b[j];
			k--;
			j++;
		}
	}

	if(k != 0) cout<<-1<<endl;
	else cout<<ans<<endl;
}