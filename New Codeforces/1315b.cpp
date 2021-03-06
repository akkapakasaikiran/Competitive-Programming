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

void rsort(vector<int> &v){
	sort(v.begin(),v.end(),greater<int>());
}

////////////////////////////////////////

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test(t){
		int a,b,p; cin>>a>>b>>p;
		string s; cin>>s;
		int n = s.size();
		vi m; m.resize(n);

		m[n-1] = 0; 
		int res = 0;
		for(int i = n-2; i >= 0; i--){
			if(i != n-2 && s[i] == s[i+1]) m[i] = m[i+1];
			else if(s[i] == 'A') m[i] = m[i+1] + a;
			else m[i] = m[i+1] + b;
			if(m[i] > p){
				res = i+1;
				break;
			} 
		}
		if(res == 0) cout<<1<<endl;
		else cout<<res+1<<endl;
		//cout<<"here goes nothing "; prvi(m);
	}
}