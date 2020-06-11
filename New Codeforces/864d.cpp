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

	int n; cin>>n;
	vi a; tkii(a,n);

	vvi posns; posns.resize(n+1);
	rep(i,n) posns[a[i]].pb(i);

	vi missing;
	rep1(i,n) if(posns[i].size() == 0) missing.pb(i);

	if(missing.empty()){
		cout<<0<<endl;
		prvi(a);
	}
	else{
		vi freeposns;
		rep1(i,n) if(posns[i].size() > 1){
			rep(j,posns[i].size()) freeposns.pb(posns[i][j]);
		}

		vi seen(n+1);
		vi used(n+1);
		sort(all(freeposns));

		int ind = 0;
		for(int x : freeposns){
			seen[a[x]]++;
			if(ind == missing.size()) break;
			else if(seen[a[x]] == posns[a[x]].size() || a[x] < missing[ind]){
				if(used[a[x]] < seen[a[x]]-1){
					used[a[x]]++;
					a[x] = missing[ind];
					ind++;
				}
			}
			else{
				used[a[x]]++;
				a[x] = missing[ind];
				ind++;
			}
		}

		cout<<missing.size()<<endl;
		prvi(a);

	}


}