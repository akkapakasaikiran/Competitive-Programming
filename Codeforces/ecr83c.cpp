#include<iostream>
#include<vector>
#include<list>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<algorithm>
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
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

//////////////////////////////////////////

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

////////////////////////////////////////////

#define tki take_input
#define tkii take_input<int>
template <typename T>
void take_input(vector<T> &a, int size){
	T tmp;
	for(int i=0;i<size;i++){
		cin>>tmp;
		a.push_back(tmp);
	}
}

#define prv print_vector
#define prvi print_vector<int>
template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

int vmax(vi v){ //positivity assumed
	int ans = 0;
	rep(i,v.size()) ans=max(ans,v[i]);
	return ans;
}

////////////////////////////////////////

bool has0and1(vi v){
	bool ok = true;
	rep(i,v.size()) if(v[i]!=0 && v[i]!=1) ok = false;
	return ok;
}

vi expand(ll num, int base){
	vi out;
	rep(j,60) out.pb(0);

	ll powofbase = 1; int pow = 0;
	while(powofbase <1e17){
		powofbase *= base;
		pow++;
	}

	for(int i=pow;i>=0;i--){
		//cout<<i<<" "<<num<<" "<<powofbase<<" "<<(num>=powofbase)<<endl;
		while(num>=powofbase){
			num -= powofbase;
			out[60-i-1]+=1;
		}
		powofbase /= base;
	}
	return out;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test(t){
		int n,k; cin>>n>>k;
		vll a; tki<ll>(a,n);
		bool intersect = false;
		vi occ; rep(j,60) occ.pb(0);
		rep(i,n){
			//prvi(occ);
			vi cur = expand(a[i],k); 
			if(!has0and1(cur)) intersect = true;
			rep(z,60){
				if(cur[z]==1 && occ[z]==1) intersect = true;
				else if(cur[z]==1) occ[z]=1;
			}
		}
		if(intersect) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	
}