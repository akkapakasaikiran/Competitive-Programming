#include <bits/stdc++.h>
using namespace std;
using ll = long long; using vi = vector<int>;
using vvi = vector<vector<int> >; using vb = vector<bool>;
#define pb push_back
#define llmax 9223372036854775807
#define intmax 2147483647
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

ll summ(int inp){
	ll tmp = inp;
	return (tmp*(tmp+1))/2;
}

int main(){
	fastio;

	int n,x; cin>>n>>x;
	vi a; tkii(a,n);
	a.insert(a.begin(),a.begin(),a.end());

	int sd = 0,ed = 0,spos = 1,epos,bsd,bed,bspos,bepos;
	ll maxsum = 0, cursum = 0;
	ll prefsum = (ll) a[0];

	while(prefsum < x && ed < n-1){
		cursum += summ(a[ed]);
		ed++;
		prefsum += a[ed];
	} 
	epos = a[ed] - (prefsum - x);
	cursum += summ(epos); 

	while(ed < 2*n){

		if(a[sd]-spos+1 <= a[ed]-epos){
			//cout<<"CASE 1"<<endl;
			cursum += summ(epos+a[sd]-spos+1);
			//cout<<"+="<<summ(epos+a[sd]-spos+1)<<endl;
			cursum -= summ(epos);
			//cout<<"-="<<summ(epos)<<endl;
			cursum -= summ(a[sd]);
			//cout<<"-="<<summ(a[sd])<<endl;
			cursum += summ(spos-1);
			//cout<<"+="<<summ(spos-1)<<endl;
			epos += a[sd]-spos+1;
			sd++;
			spos = 1;

			if(cursum > maxsum){
				bsd = sd; bed = ed;
				bspos = spos; bepos = epos;
				maxsum = cursum;
			}
		}
		else{
			cursum += summ(a[ed]);
			//cout<<"+="<<summ(a[ed])<<endl;
			cursum -= summ(epos);
			//cout<<"-="<<summ(epos)<<endl;
			cursum -= summ(spos+a[ed]-epos-1);
			//cout<<"-="<<summ(spos+a[ed]-epos-1)<<endl;
			cursum += summ(spos-1);
			//cout<<"+="<<summ(spos-1)<<endl;
			spos += a[ed]-epos;
			epos = a[ed];

			if(cursum > maxsum){
				bsd = sd; bed = ed;
				bspos = spos; bepos = epos;
				maxsum = cursum;
			}

			cursum++;
			cursum -= spos; 

			ed++;
			epos = 1;
			if(spos == a[sd]){
				sd++;
				spos = 1;
			}
			else spos++;

		}
	}

	cout<<maxsum<<endl;

}