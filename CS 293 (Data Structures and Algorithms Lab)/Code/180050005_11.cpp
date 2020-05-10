#include<iostream>
#include<unordered_map>
#include<list>
#include<cmath>
using namespace std;

const int N = 10000;
unordered_map<string,list<string>::iterator> maps[N];
list<string> lists[N];

int main(){
	int n,m; cin>>n>>m;

	long long ans=0;
	
	int parent[n];
	int capacity[n];
	int sizes[n]; for(int i=0;i<n;i++) sizes[i]=0;

	parent[0]=-1;
	for(int i=1;i<n;i++) cin>>parent[i];

	capacity[0]=m;
	for(int i=1;i<n;i++) cin>>capacity[i];

	for(int i=0;i<m;i++){
		string query; int node;
		cin>>query>>node;
		int count=0;
		while(maps[node].count(query)==0){ // not found 
			if(sizes[node]==capacity[node]){
				maps[node].erase(lists[node].front());
				lists[node].pop_front();
				sizes[node]--;
			}
			lists[node].push_back(query);
			auto it=lists[node].end(); it--; // dubious, does end exist
			maps[node][query]=it;
			sizes[node]++;
			ans+=1+log2(capacity[node]);
			node=parent[node];
			if(node==-1) break;
		}
		if(node!=-1){ // found at node => erase
			lists[node].erase(maps[node][query]);
			lists[node].push_back(query);
			auto it=lists[node].end(); it--; // dubious, does end exist
			maps[node][query]=it;
			ans+=1+log2(capacity[node]);
		}
	}
	cout<<ans<<endl;
}