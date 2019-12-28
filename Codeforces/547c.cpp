#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_vector(vector<int> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

int main(){
	int n; cin>>n;
	vector<int> q; // -2 1
	int tmp;
	for(int i=0;i<n-1;i++){
		cin>>tmp;
		q.push_back(tmp);
	}

	vector<int> p;
	p.push_back(0); // 0 -2 -1
	for(int i=0;i<n-1;i++){
		p.push_back(p[i]+q[i]);
	}

	vector<int> pcpy=p;
	sort(p.begin(),p.end());

	/*print_vector(p);
	print_vector(pcpy);*/

	bool ok=true;
	int diff=p[0]-1;
	for(int i=0;i<n;i++){
		if (p[i]-i-1 != diff){
			ok = false;
			break;
		}
	}

	if(ok){
		for(int i=0;i<n;i++) cout<<pcpy[i]-diff<<" ";
		cout<<endl;
	}
	else cout<<-1<<endl;
}