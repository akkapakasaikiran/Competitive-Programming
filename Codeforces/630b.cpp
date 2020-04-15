#include <bits/stdc++.h>
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

////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int primes[11] = {2,3,5,7,11,13,17,19,23,29,31};
	si primes_needed;

	test(t){
		int n; cin>>n;
		vi a; tkii(a,n);
		vi color; color.resize(n);
		int max_ind = -1;
		rep(i,n){
			rep(j,11){
				if(a[i]%primes[j]==0){
					color[i] = j+1; 
					max_ind = max(max_ind,j);
					break;
				}
			}
		}

		cout<<max_ind+1<<endl;
		prvi(color);
	}
}