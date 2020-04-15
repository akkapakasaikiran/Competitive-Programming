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

vector< vll > ncrmemo;

ll ncr(int n, int r){
	//cout<<"ncr called with "<<n<<" and "<<r<<endl;
	if(n==r) return 1;
	else if(r==0) return 1;
	else if(ncrmemo[n][r]==-1){
		ncrmemo[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
		return ncrmemo[n][r];
	}
	else return ncrmemo[n][r];
}

string ans(int n, int k, int b){
	//cout<<"ans called with "<<n<<" "<<k<<" "<<b<<endl;
	if(k==1){
		string ret = "";
		rep(i,n-b) ret.append("a");
		rep(j,b) ret.append("b");
		return ret;
	}
	else if(b==0){
		string ret = "";
		rep(i,n) ret.append("a");
		return ret;
	}
/*	else if(k==ncr()){
		string ret = "";
		rep(i,b) ret.append("b");
		rep(j,n-b) ret.append("a");
		return ret;
	}*/
	else if(ncr(n-1,b) >= k){
		string ret = "a";
		ret.append(ans(n-1,k,b));
		return ret;
	}
	else{
		string ret = "b";
		ret.append(ans(n-1,k-ncr(n-1,b),b-1));
		return ret;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	rep(i,1e5){
		vll tmp;
		rep(j,3){
			tmp.pb(-1);
		}
		ncrmemo.pb(tmp);
	}

	test(t){
		int n,k; cin>>n>>k;
		cout<<ans(n,k,2)<<endl;
	}
	/*rep(n,10){
		if(n<=2) continue;
		cout<<"ok"<<endl;
		int lim = ncr(n,2);
		cout<<"okk"<<endl;
		rep1(k,lim){
			cout<<n<<" "<<k<<" "<<ans(n,k,2)<<endl;
		}
	}
	cout<<ans(4,4,2)<<endl;*/
}