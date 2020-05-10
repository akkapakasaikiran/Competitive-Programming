#include <bits/stdc++.h>
#include<numeric>
using namespace std;

#define ll long long
#define st string
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vii vector<int>::iterator
#define si set<int>
#define pb push_back

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

void rsort(vector<int> &v){
	sort(v.begin(),v.end(),greater<int>());
}

////////////////////////////////////////

ll gcd(ll a ,ll b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test(t){
		ll a,b,q; cin>>a>>b>>q;
		ll zero = 0;
		ll lcm = a*b/gcd(a,b);  
		rep(i,q){
			ll l,r; cin>>l>>r;
			ll x,y;
			y = r/lcm;
			if(l%lcm==0){
				x = l/lcm;
				ll tmp = (y-x)*max(a,b) + min(b,r%lcm+1);
				cout<<r-l+1	-tmp<<" ";
			}
			else{
				x = (l/lcm)+1;
				ll tmp = max(zero,max(a,b)-l%lcm) + (y-x)*max(a,b) + min(max(a,b),r%lcm+1);
				cout<<r-l+1-tmp<<" ";
				//cout<<tmp;
			}
		}
		cout<<endl;
	}
}