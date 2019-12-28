#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> l,r;

bool lcomp(int x,int y){
	if(l[x-1]=='?') return false;
	else if(l[y-1]=='?') return true;
	return l[x-1]<l[y-1];
}
bool rcomp(int x,int y){
	/*if(r[x-1]=='?') return false;
	else if(r[y-1]=='?') return true;*/
	return r[x-1]<r[y-1];
}

template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

int main(){
	int n; cin>>n;
	vector<int> lindex,rindex;
	char tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		l.push_back(tmp);
		lindex.push_back(i+1);
	}
	for(int i=0;i<n;i++){
		cin>>tmp;
		r.push_back(tmp);
		rindex.push_back(i+1);
	}
	
	sort(lindex.begin(),lindex.end(),lcomp);
	sort(rindex.begin(),rindex.end(),rcomp);

	/*print_vector<char>(l);
	print_vector<char>(r);

	print_vector<int>(lindex);
	print_vector<int>(rindex);*/

	/*for(int i=0;i<n;i++) cout<<l[lindex[i]-1]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++) cout<<r[rindex[i]-1]<<" ";
	cout<<endl;*/

	int i=0,j=0;

	int cnt=0;
	vector< pair<int,int> > ans;

	while(i<n && j<n){
		if(l[lindex[i]-1]==r[rindex[j]-1]
			|| l[lindex[i]-1]=='?' 
			|| r[rindex[i]-1]=='?'){
			cnt++;
			ans.push_back(make_pair(lindex[i],rindex[j]));
			/*cout<<i<<" "<<j<<endl;*/
			i++; j++; 
		}
		else if(l[lindex[i]-1]<r[rindex[j]-1]){
			i++;
		}
		else {
			j++;
		}
	}

	cout<<cnt<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}

}
