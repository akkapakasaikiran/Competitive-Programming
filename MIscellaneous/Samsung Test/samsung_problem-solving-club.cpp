/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include<vector>
#include<set>

using namespace std;

// #define ae add_edge
// void add_edge(vector<vi> &a, int u, int v){
// 	a[u].pb(v);
// }

#define prg print_graph
void print_graph(vector<set<int>> &a){
	for(int i= 0; i < a.size(); i++){
		cout<<i<<" : "; for(int x : a[i]){ cout<<x<<" "; } cout<<endl;
	} 
}

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 int n,m; cin>>n>>m;
		 vector<set<int>> a(n+1);
		 int u,v;
		 for(int i = 0; i< m; i++){
		     cin>>u>>v;
		     a[u].insert(v);
		 }
		 
		 prg(a);

		 int cnt = 0;
		 for(int u = 1; u <= n; u++){
		     bool ok = false;
		     for(int v : a[u]) if(a[v].find(u) != a[v].end()) ok = true;
		     if(!ok) cnt++;
		 }
		 
		 Answer = cnt;
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}