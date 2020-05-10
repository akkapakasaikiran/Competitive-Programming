#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vb vector<bool>
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
////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test(t){
		int n; cin>>n;
		vi a; tkii(a,n);

		bool allsame = a[0]==a[n-1];
		rep(i,n-1) if(a[i]!=a[i+1]) allsame = false;
		if(allsame){
			cout<<1<<endl;
			rep(i,n) cout<<1<<" ";
			cout<<endl;
		}
		else if(n%2==0){
			cout<<2<<endl;
			rep(i,n) cout<<1+i%2<<" ";
			cout<<endl;
		}	 
		else{
			int index = -1;
			if(a[0]==a[n-1]) index = n-1;
			rep(i,n-1) if(a[i]==a[i+1]) index = i;
			if(index != -1){
				cout<<2<<endl;
				int col = 1;
				rep(i,n){
					cout<<col<<" ";
					if(index != i) col = 3 - col;
				} 
				cout<<endl;
			}
			else{
				cout<<3<<endl;
				rep(i,n-1) cout<<1+i%2<<" ";
				cout<<3<<endl;
			} 
		}
	}
}