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

	int n; cin>>n;
	vi a; tkii(a,n);

	vi cnt; cnt.resize(150001);

	rep(i,n) cnt[a[i]-1]++;

	int l = -1;
	int extra = 0;
	vector<pair<int,int> > extrapos;


	rep(i,150001){
		if(cnt[i] == 0){
			if(l == -1){
				if(extra >= 1){
					cnt[extrapos[0].first]--;
					cnt[i]++;
				}
				else l = i;
			}
			else{
				if(extra == 1){
					cnt[extrapos[0].first]--;
					cnt[l]++;
					l = i;
				}
				else if(extra >= 2){
					cnt[l]++;
					cnt[i]++;
					if(extrapos[0].second >= 2) cnt[extrapos[0].first] -= 2;
					else{
						cnt[extrapos[0].first]--;
						cnt[extrapos[1].first]--;
					}
					l = -1;
				}
				else{
					l = i;
				}
			}
			extrapos.clear();
			extra = 0;
		}
		else if(cnt[i] >= 2){
			extrapos.pb(make_pair(i,cnt[i]-1));
			extra += cnt[i] - 1;
		}
	}

	int ans = 0;
	rep(i,150001) if(cnt[i] >= 1) ans++;

	cout<<ans<<endl;
}