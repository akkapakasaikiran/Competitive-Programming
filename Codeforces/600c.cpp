#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,m; cin>>n>>m;
	vector<int> a;
	int tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		a.push_back(tmp);
	}

	sort(a.begin(),a.end());
	/*for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;*/

	for(int k=1;k<=n;k++){
		int ans=0;
		int day=1;
		vector<int>::iterator it = a.begin()+k-1;

		while(it>=a.begin()+m){
			for(int i=0;i<m;i++){
				ans+=day*(*it);
/*				cout<<day<<"-"<<day*(*it)<<" ";
*/				it--;
			}
			day++;
		}
/*		cout<<"---"<<day<<"---";
*/		while(it>=a.begin()){
			ans+=day*(*it);
/*			cout<<day<<"-"<<day*(*it)<<" ";
*/			it--;
		}
		cout<<ans<<" ";
	}
	cout<<endl;
}
