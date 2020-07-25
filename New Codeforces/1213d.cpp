#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>; using vll = vector<long long>; 
using vvi = vector<vector<int> >; using vb = vector<bool>;
using pii = pair<int,int>; 
#define pb push_back
#define all(v) v.begin(),v.end()
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

int findcommon(int x, int y){
	while(x != y){
		if(x > y) x /= 2;
		else y /= 2;
	}
	return x;
}

int pow2(int x){
	int cnt = 0;
	while(x != 1){
		x /= 2;
		cnt++;
	}
	return cnt;
}

vi findmins(vi comm, int k){
	vi ret;
	set<pair<int,int> > s;
	rep(i,k) s.insert(make_pair(comm[i],i));
	ret.pb((*s.begin()).first);
	rep(i,comm.size()-k){
		s.erase(make_pair(comm[i],i));
		s.insert(make_pair(comm[i+k],i+k));
		ret.pb((*s.begin()).first);
	}
	return ret;
}


int main(){
	fastio;

	int n,k; cin>>n>>k;
	vi a; tkii(a,n);

	sort(all(a));

	if(k == 1) cout<<0<<endl;
	else{
		vi comm; 
		rep(i,n-1) comm.pb(findcommon(a[i],a[i+1]));

		vi mins = findmins(comm, k);
		prvi(comm);
		prvi(mins);

		int ans = 0;
		rep(i,k) ans += pow2(a[i]/comm[0]);

		int minans = ans;
		cout<<minans<<endl;

		rep(i,n-k){
			cout<<mins[i+1]<<" "<<i+1<<" ";
			if(mins[i+1] != mins[i]){
				ans = 0;
				rep1(j,k) ans += pow2(a[i+j]/mins[i+1]);
			} else{
				ans -= pow2(a[i]/mins[i+1]);
				ans += pow2(a[i+k]/mins[i+1]);
			}
			minans = min(minans, ans);
			cout<<minans<<endl;
		}

		cout<<minans<<endl;
	}

}