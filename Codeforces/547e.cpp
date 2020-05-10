#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int n,tmp;
	long long sum=0,steps=0,h,max_fall=0;
	bool inf=false;
	cin>>h>>n;
	vector<int> d;
	for(int i=0;i<n;i++){
		cin>>tmp;
		sum+=tmp;
		if(sum<max_fall) max_fall = sum;
		d.push_back(tmp);
	}

	if(sum>=0 && h+max_fall > 0) inf = true;

	else if(h+max_fall>0){
		steps=ceil((h+max_fall)/-sum);
/*		cout<<sum<<" "<<max_fall<<" "<<steps<<endl;*/
	}

	long long cnt=n*steps;
	h+=steps*sum;
	while(!inf){
		h+=d[cnt%n];
		cnt++;
		if(h<=0) break;
	}
	if(inf) cout<<-1<<endl;
	else cout<<cnt<<endl;
}