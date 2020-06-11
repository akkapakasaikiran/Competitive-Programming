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
 
double h,c,t; 
 
double formula(int n){
	return (n*(h+c)+h)/(2*n+1);
}
 
int main(){
	fastio;
 
	test(tt){
		cin>>h>>c>>t;
 
		rep(i,40){
			cout<<i<<" ";
			if(i%2==0) cout<<(h+c)/2<<endl;
			else cout<<formula(i/2)<<endl;
		}	

		if(t <= (h+c)/2) cout<<2<<endl;
		else if(t == h) cout<<1<<endl;
		else{
			int l = -1, r = 1;
			while(l == -1){
				if(formula(r) > t) r *= 2;
				else l = (r/2);
			}
			while(r-l > 1){
				if(formula((l+r)/2) > t) l = (l+r)/2;
				else r = (l+r)/2;
			}
			if(abs(t - formula(l)) <= abs(t - formula(r))){
				cout<<2*l+1<<endl;
			}
			else cout<<2*r+1<<endl;
		}
	}
}