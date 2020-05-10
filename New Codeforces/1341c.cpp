#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define st string
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vii vector<int>::iterator
#define mit map<int,si>::iterator
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
		int n; cin>>n;
		vi p; tkii(p,n);
		vector<list<int> > lst; lst.resize(n); // represents r
		
		map<int,si> cnt;
		si tmpset1; cnt[1] = tmpset1;
		rep(i,n) cnt[1].insert(i);
		vi cntarr; cntarr.resize(n);
		rep(i,n) cntarr[i] = 1;

		rep(i,n){
			list<int> tmp; tmp.pb(i); 
			lst.pb(tmp);
		}
		
		set<int> vacant; 
		rep(i,n) vacant.insert(i);

		vi pos; pos.resize(n); // inverse of p
		rep(i,n) pos[p[i]-1] = i;
	
		//cnt[2] = tmpset1; cnt[2].insert(10);
		/*for(mit i = cnt.begin();i!=cnt.end();i++){
			cout<<i->first<<" : ";
			for(int x : i->second) cout<<x<<" ";
			cout<<endl;
		}*/

		bool ok = true;	
		int cur,nxt;
		rep(i,n){
			cur = pos[i]; 
			//cout<<"cur"<<cur<<endl;

			map<int,si>::iterator ending = cnt.end();
			ending--;
			if((ending->second).find(cur)==(ending->second).end()){
				/*cout<<cntarr[cur]<<endl;
				cout<<ending->first<<endl;
				for(int x : ending->second) cout<<x<<" "<<endl;*/
				ok = false;
				break;
			}

			si::iterator iter = vacant.find(cur);
			if(next(iter,1) == vacant.end()){
				//cout<<"LAst of vacant"<<endl;
				cnt[cntarr[cur]].erase(cur);
				if(cnt[cntarr[cur]].empty()) cnt.erase(cntarr[cur]);
				lst[cur].clear();
				vacant.erase(cur);
			}
			else{
				nxt = *next(iter,1);
				lst[nxt].insert(lst[nxt].end(),lst[cur].begin(),lst[cur].end()); // should be O(1)
				lst[cur].clear();
				vacant.erase(cur);
				cntarr[nxt] += cntarr[cur];
				cnt[cntarr[cur]].erase(cur);
				si tmpset; tmpset.insert(nxt);
				cnt[cntarr[nxt]] = tmpset;
				cntarr[cur] = 0;
			}

			/*cout<<"map"<<endl;
			for(mit i = cnt.begin();i!=cnt.end();i++){
				cout<<i->first<<" : ";
				for(int x : i->second) cout<<x<<" ";
				cout<<endl;
			}*/	
		}

		if(ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}