#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(string &s, int i, int j){
	char tmp=s[i];
	s[i]=s[j];
	s[j]=tmp;
}

int main(){
	int t; cin>>t;
	while(t--){
		string s,c; cin>>s>>c;
		if(s<c) cout<<s<<endl;
		else if(s>c){
			int big_val=c[0];
			int big_ind=0;
			int i = 0;
			for(;i<c.size();i++){
				if(s[i]>c[i]) break;
				if(c[i]>big_val){
					big_val = c[i];
					big_ind = i;
				}
			}
			if(i==c.size()){ //c is prefix of s
				for(;i<s.size();i++) if(s[i]<big_val) break;
				if(i==s.size()) cout<<"---"<<endl;
				else{
					swap(s,big_ind,i);
					cout<<s<<endl;
				}
			}
			else{

				int j=1;
				for(;j<i;j++){
					if(s[j]<s[j-1]) break;
				}
				if(j<i){
					//cout<<"yo "<<j<<" "<<i<<" ";
					swap(s,j,j-1);
					cout<<s<<endl;
				}
				else{			
					int ind = i;	
					int last_same_ind = i;
					for(;i<s.size();i++){
						if(s[i]<c[ind]){
							swap(s,ind,i);
							cout<<s<<endl;
							break;
						}
						if(s[i]==c[ind]) last_same_ind = i;
					}
					if(i==s.size()){
						if(last_same_ind==ind) cout<<"---"<<endl;
						else{
							swap(s,ind,last_same_ind);
							if(s<c) cout<<s<<endl;
							else cout<<"---"<<endl;
						}
					}
				}
			}
		}
		else{ // s==c
			int i=1;
			for(;i<s.size();i++){
				if(s[i]<s[i-1]) break;
			}
			if(i==s.size()) cout<<"---"<<endl;
			else{
				swap(s,i,i-1);
				cout<<s<<endl;
			}
		}
	}
}