#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define pb push_back
#define llmax 9223372036854775807
#define intmax 2147483647
#define endl "\n"
const ll mod = 1e9+7;
//////////////////////////////////////////
#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
////////////////////////////////////////////
#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	T tmp; for(int i=0;i<size;i++){ cin>>tmp; a.push_back(tmp); }
}
#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}
////////////////////////////////////////

int r0, g0;

ll ans(int t, int r, int g){
	ll ret = 0;
	if(r < 0 || g < 0) ret = 0;
	else if(t == 1){
		if(r >= 1) ret += 1;
		if(g >= 1) ret += 1;
	}
	else ret = (ans(t-1,r-t,g) + ans(t-1,r,g-t)) % mod;

	//cout<<t<<" "<<r<<" "<<g<<" "<<ret<<"\n";
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int r,g; cin>>r>>g;
	r0 = r; g0 = g;

	int h = 1;
	while(h*(h+1) <= 2*(r+g)) h++;
	h--;

	cout<<ans(h,r0,g0)<<endl;

}