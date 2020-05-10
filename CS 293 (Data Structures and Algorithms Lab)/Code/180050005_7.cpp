#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

char inf='z'+1;
vector<string> v;
vector<string> cp;
vector<int> ind; 

string min_cyclic_string(string s) {
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2) {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    return s.substr(ans, n / 2);
}

vector<string> duval(string const& s) {
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] >= s[j]) {
            if (s[k] > s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k) {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}

bool compare(int x,int y) { return cp[x] < cp[y]; }


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin>>n;
	string x;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}

	for(int i=0;i<n;i++){
		cp.push_back(min_cyclic_string(v[i]));
	}
	
	for(int i=0;i<n;i++) ind.push_back(i);

	sort(ind.begin(),ind.end(),compare);

	//sort(cp.begin(),cp.end());
	int distinct=1;
	for(int i=0;i<n-1;i++){
		if(cp[ind[i]]!=cp[ind[i+1]]) distinct++;
	}
	cout<<distinct<<endl;

	vector<string> lyn1=duval(v[0]);
	vector<string> lyn2=duval(v[1]);

	int size1=lyn1.size();
	int size2=lyn2.size();
	string ans="";
	int i=0,j=0;
	while(i!=size1 && j!=size2){
		if(lyn1[i]+inf < lyn2[j]+inf){
			ans+=lyn1[i]; i++;
		} 
		else{
			ans+=lyn2[j]; j++;
		}
	}
	if(i==size1){
		while(j!=size2){
			ans+=lyn2[j]; j++;
		}
	}
	else{
		while(i!=size1){
			ans+=lyn1[i]; i++;
		}
	}
	cout<<ans<<endl;

}