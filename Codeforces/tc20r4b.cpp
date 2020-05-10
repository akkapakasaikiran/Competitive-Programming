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
#define vii vector<int>::iterator
#define pb push_back
#define all(v) v.begin(),v.end()

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define forv(v) for(auto x : v)
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))

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

pii power(int n, vi &two, vi &oddd){
	if(oddd[n]==0){
		int ans = 0;
		int x = n;
		while(x%2==0){
			ans++; x/=2;
		}
		two[n] = ans;
		oddd[n] = x;
	}
	return mp(two[n],oddd[n]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vi two(10e5+1); vi oddd(10e5+1);

	test(t){
		int n; cin>>n; 
		vi a; tkii(a,n);
		vi pow(10e5);
		rep(i,n){
			pii ans = power(a[i],two,oddd); 
			int po = ans.fi;
			int odd = ans.se;
			if(po > pow[odd]) pow[odd] = po;
		}
		int su = 0;
		for(int i=1,i<pow.size();i+=2){
			su+=pow[i]; 
		}
		cout<<su<<endl;
	}
}