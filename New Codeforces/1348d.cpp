#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define pb push_back
#define llmax 9223372036854775807
#define intmax 2147483647
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
const ll mod = 1e9+7;
/////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	test(t){
		int n; cin>>n;
		vi a; a.resize(100);
		a[0] = 1; n--;
		int i = 1;
		int prev = 1;
		while(n !=0){
			prev = a[i-1]; // invariant : n >= prev 
			if(n >= 4*prev) a[i] = prev*2;
			else if(n <= 2*prev) a[i] = n;
			else a[i] = n/2;
			n -= a[i];
			i++;
		}
		cout<<i-1<<endl;
		vi diff;
		rep(j,i-1) diff.pb(a[j+1]-a[j]);
		prvi(diff);

	}
}