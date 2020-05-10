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
ll llmax = 9223372036854775806;

ll sq(ll x){
	return x*x;
}

ll ans(vi rr, vi gg, vi bb){
	int i = 0, j = 0, k = 0;

	int x = rr.size(), y = gg.size(), z = bb.size();
	vi before,after;
	rep(i,y) before.pb(-2); rep(i,y) after.pb(-2);
	while(j < y){ // before[j] == -2 && 
		if(i == x || rr[i] > gg[j]){
			before[j] = i-1;
			j++;
		}
		else i++;
	}
	j = 0;
	while(j < y && k < z){ // after[j] == -2 &&  
		if(bb[k] > gg[j]){
			after[j] = k;
			j++;
		}
		else{
			k++;
		}
	}
	ll ret = llmax, cur;
	int best;
	rep(j,y){
		if(before[j]>=0 && after[j] >=0){
			cur = sq(rr[before[j]]-gg[j]) + sq(rr[before[j]]-bb[after[j]]) + sq(gg[j] - bb[after[j]]);
			if(cur < ret){ ret = cur; best = j; }
		}
	}

	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	test(t){
		int r,g,b; cin>>r>>g>>b;
		vi rr,gg,bb;
		tkii(rr,r); tkii(gg,g); tkii(bb,b);
		sort(rr.begin(),rr.end());
		sort(gg.begin(),gg.end());
		sort(bb.begin(),bb.end());		

		ll finans1 = min(ans(rr,gg,bb),ans(rr,bb,gg));
		ll finans2 = min(ans(gg,rr,bb),ans(gg,bb,rr));
		ll finans3 = min(ans(bb,gg,rr),ans(bb,rr,gg));
		ll finans4 = min(finans1,finans2);
		ll finans = min(finans4,finans3);
		cout<<finans<<endl;
	}
}