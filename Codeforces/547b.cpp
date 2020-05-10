#include<iostream>
#include<vector>
using namespace std;

int lso(vector<int> v){
	int max=0,cur=0;
	for(int i=0;i<v.size();i++){
		if(v[i]==1) cur++;
		else cur=0; // v[i]==0
		if (cur>max) max=cur;
	}
	return max;
}

int main(){
	int n; cin>>n;
	vector<int> a;
	int tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		a.push_back(tmp);
	}

	vector<int> b = a;
	b.insert(b.begin(),b.begin(),b.end());

	/*for(int i=0;i<2*n;i++) cout<<b[i]<<" ";
	cout<<endl;*/
	cout<<lso(b)<<endl;
}