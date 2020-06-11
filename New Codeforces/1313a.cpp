#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define llmax 9223372036854775807
#define intmax 2147483647
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

void arrange(int &a, int &b, int &c){
	int x,y,z;
	if(a >= b && a >= c){
		x = a;
		if(b >= c){ y = b; z = c; }
		else{ y = c; z = b; }
	}
	else if(b >= c && b >= a){
		x = b;
		if(a >= c){ y = a; z = c; }
		else{ y = c; z = a; }
	} 
	else{
		x = c;
		if(a >= b){ y = a; z = b; }
		else{ y = b; z = a; }
	}
	a = x; b = y; c = z;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	test(t){
		int a,b,c;
		cin>>a>>b>>c;
		int ans = 0;
		if(a >=1){ a--; ans++; }
		if(b >=1){ b--; ans++; }
		if(c >=1){ c--; ans++; }
		arrange(a,b,c);
		if(a >=1 && b >=1 ){ a--; b--; ans++; }
		if(a >=1 && c >=1 ){ a--; c--; ans++; }
		if(c >=1 && b >=1 ){ c--; b--; ans++; }

		if(a >=1 && b >=1 && c>=1){ c--; a--; b--; ans++; }
		cout<<ans<<endl;


	}
}