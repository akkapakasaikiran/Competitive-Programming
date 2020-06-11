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

	int m,s; cin>>m>>s;
	if(s == 0){
		if(m == 1) cout<<0<<" "<<0<<endl;
		else cout<<-1<<" "<<-1<<endl;
	}
	else{
		int nines = (s-1)/9, rem = (s-1)%9;
		string minans;
		if(nines <= m-2){
			minans.pb('1');
			rep(i,m-nines-2) minans.pb('0');
			minans.pb(to_string(rem)[0]);
			rep(i,nines) minans.pb('9');
		}
		else if(nines == m-1 && rem == 0){
			minans.pb('1');
			rep(i,nines) minans.pb('9');
		}
		else{
			nines = s/9; rem = s%9;
			if(nines == m-1 && rem != 0){
				minans.pb(to_string(rem)[0]);
				rep(i,nines) minans.pb('9');
			}
			else if(nines == m && rem == 0) rep(i,nines) minans.pb('9');
			else minans ="-1";
		}
		cout<<minans<<" ";


		nines = s/9; rem = s%9;
		string maxans;
		if(nines < m){
			rep(i,nines) maxans.pb('9');
			maxans.pb(to_string(rem)[0]);
			rep(i,m-nines-1) maxans.pb('0');
		}
		else if (nines == m && rem == 0){
			rep(i,m) maxans.pb('9');
		}
		else maxans = "-1";

		cout<<maxans<<endl;
	}
}