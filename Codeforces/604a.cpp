#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

char not_this(char x){
	if(x=='a') return 'b';
	else if(x=='b') return 'c';
	else return 'a';
}

char not_this_or_this(char x,char y){
	if(x==y) return not_this(x);
	else{
		if(x=='a' && y=='b' || y=='a' && x=='b') return 'c';
		else if((x=='c' && y=='b' || y=='c' && x=='b')) return 'a';
		else return 'b';
	}
}

int main(){
	int q; cin>>q;
	while(q--){
		string s; cin>>s;
		char prev,cur,next;
		bool ok = true;
		for(int i=1;i<s.size();i++){
			prev = s[i-1];
			cur = s[i];
			if(i!=s.size()-1) next = s[i+1];
			else next = '?';
			
			if(prev==cur && cur!='?'){
				ok = false;
				break;
			}
			else if (cur=='?'){
				if(next == '?') s[i]=not_this(prev);
				else s[i]=not_this_or_this(prev,next);
			}
		}

		if(!ok) cout<<-1<<endl;
		else cout<<s<<endl;
	}
}