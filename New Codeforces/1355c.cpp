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

	int a,b,c,d; cin>>a>>b>>c>>d;

	ll ans = 0;
	for(int x = a; x <= b; x++){
		int ym = c+1-x;
		int yt = d+1-x;
		if(ym < b){
			if(yt > c){
				ans += (c-ym+1)*(c-ym+2)/2;
				ans -= (b-ym)*(b-ym+1)/2;
			}
			else if(yt >= b){
				ans += (yt-ym+1)*(yt-ym+2)/2;
				ans -= (b-ym)*(b-ym+1)/2;
				ans += (d-c+1)*(c-yt);
			}
			else{
				ans += (d-c+1)*(c-b+1);
			}
		}
		else{
			if(yt > c){
				if(ym > c) ans += 0;
				else ans += (c-ym+1)*(c-ym+2)/2;
			}
			else{
				ans += (yt-ym+1)*(yt-ym+2)/2;
				ans += (d-c+1)*(c-yt);
			}
		}
	}

	cout<<ans<<endl;
}