#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n; cin>>n;
	int perm[n];
	//int perm[8] ={7,2,6,0,1,4,3,5};
	for(int i=0;i<n;i++) cin>>perm[i];
	int weight[n];
	for(int i=0;i<n;i++) cin>>weight[i];
	int dist[n-1];
	//int dist[7]={1, 2, 1, 3, 2, 1, 2};
	for(int i=0;i<n-1;i++) cin>>dist[i];
	int ind[n];
	for(int i=0;i<n;i++) ind[perm[i]]=i;

	int cdist[n];
	cdist[0]=0;
	for(int i=0;i<n-1;i++){
		cdist[i+1]=cdist[i]+dist[i];
	}
	int D[n];
	int cost=0;
	for(int i=0;i<n;i++){
		D[perm[i]]=abs(cdist[i]-cdist[perm[i]]);
		cost+=weight[perm[i]]*D[perm[i]];
	}
	cout<<cost<<endl;

	/*
	vector<int> right;
	for(int i=0;i<n;i++){
		if(perm[i]>i) right.push_back(perm[i]);
	}
	for(auto it=right.begin();it!=right.end();it++){
		 cout<<*it<<" ";	
	}
	cout<<endl;

	for(int i=right.size()-1;i>=0;i--){
		vector<int> cycle;
		int x=right[i];
		cycle.push_back(x);
		int fx=perm[x];
		cycle.push_back(fx);
		while(fx > ind[perm[i]]){
			x=fx;
			fx=perm[x];
			cycle.push_back(fx);
		}
		//for(int i=0;i<cycle.size();i++) cout<<cycle[i]<<" ";
		//cout<<endl;
		for(int j=1;)


		cycle.clear();
	}
	*/
}

