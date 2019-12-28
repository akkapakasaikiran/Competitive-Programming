#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
void print_vector(vector<T> v){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	cout<<endl;
}

int main(){
	int n; cin>>n;
	vector<int> a;
	int tmp;
	for(int i=0;i<n;i++){
		cin>>tmp;
		a.push_back(tmp);
	}

	vector<int> people(10e6+1);

	bool ok = true;
	int days = 0, num = 0, events=0;
	vector<int> partition;
	for(int i=0;i<n;i++){
		events++;
		if(a[i]>0){
			people[a[i]]+=1;
			num++;
		}
		else{
			people[-a[i]]+=2;
			num--;
		}
		// 1 means came
		// 2 means went without coming in
		// 3 means came and went
		// >3 means came twice
		if(people[abs(a[i])] > 3 || people[abs(a[i])] == 2){
			ok = false;
			break;
		}
		else if (num==0){
			days++;
			partition.push_back(events);
			events=0;
		}
	}

	if (!ok) cout<<-1<<endl;
	else{
		cout<<days<<endl;
		print_vector<int>(partition);
	}
}