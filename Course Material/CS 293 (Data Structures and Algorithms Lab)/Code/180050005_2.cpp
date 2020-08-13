#include<iostream>
using namespace std;

int main(){

    string s; cin>>s;
    int req; cin>>req;
    long long multi=1;

    int len=s.size();
    int lcount[26]={0};

    for(int i=0;i<len;i++){
        lcount[s[i]-'a']++;
        multi=(i+1)*multi/lcount[s[i]-'a'];
    }

    long long sum=0;
    string suffix=s;
    for(int i=0;i<s.size();i++){
        int posn=s[i]-'a';

        for(int z=0;z<posn;z++){
            sum+=multi*lcount[z]/suffix.size();
        }

        multi=multi*lcount[posn]/suffix.size();
        lcount[posn]--;
        suffix=suffix.substr(1,suffix.size());

    }
    cout<<sum<<" ";

    //part 2
    sum=0;
    string str="";
    for(int i=0;i<len;i++){
        lcount[s[i]-'a']++;
        multi=(i+1)*multi/lcount[s[i]-'a'];
    }

    int temp_size=len;

    for(int i=0;i<len;i++){

        int z;
        for(z=0;z<26;z++){
            sum+=multi*lcount[z]/temp_size;
            if(sum>req){
                str+=char('a'+z);
                sum-=multi*lcount[z]/temp_size;
                //cout<<sum<<endl;
                break;
            }
        }

        multi=multi*lcount[z]/temp_size;
        lcount[z]--;
        temp_size--;
    }

    cout<<str<<endl;
}
