/* Author: Akkapaka Saikiran (@saikidon911) */
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>; using vll = vector<long long>; 
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define all(v) v.begin(),v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//////////////////////////////////////////
#define test(t) int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
////////////////////////////////////////////
#define tki take_input 
#define tkii take_input<int>
template <typename T> void take_input(vector<T> &a,int sz){
	T t;rep(i,sz){cin>>t;a.pb(t);}}
#define prv print_vector
#define prvi print_vector<int> 
template <typename T> void print_vector(vector<T> v){
	rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl;}
/////////////////////////////////////////

int main(){
	fastio;

	int n; cin>>n;
	vi a; tkii(a,n);

	vb take(n, true);
	rep(i,n-1) if(a[i] == a[i+1]) take[i+1] = false;

	vi b;
	rep(i,n) if(take[i]) b.pb(a[i]);
	a = b;
	n = a.size();

	vi label(n);
	rep1(i,n-2){
		if(a[i] > a[i-1] && a[i] > a[i+1]) label[i] = 1; 
		else if(a[i] < a[i-1] && a[i] < a[i+1]) label[i] = -1;
	}

	if(a[0] < a[1]) label[0] = -1;
	if(a[n-1] > a[n-2]) label[n-1] = 1;

	// prvi(a);
	// prvi(label);

	int s = -1, e = n;
	for(int i = 0; i < n; i++) if(label[i] == -1 && s == -1) s = i; 
	for(int i = n-1; i >= 0; i--) if(label[i] == 1 && e == n) e = i;

	if(s == -1) cout<<1000<<endl;
	else{
		int money = 1000;
		int num = 0;
		for(int i = s; i <= e; i++){
			if(label[i] == -1){
				num = money/a[i];
				money -= num*a[i];
			}
			else if(label[i] == 1){
				money += num*a[i];
				num = 0;
			}
		}

		cout<<money<<endl;
	}
	

}	