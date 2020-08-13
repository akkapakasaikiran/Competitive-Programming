bool func(string s){
	int n = s.size();
	bool ok = true;
	for(int i = 0; i < n/2; i++)
		if(s[i] != s[n-i-1]) ok = false;

	return ok; 
}



struct Node{
	int val;
	Node* next;
};

Node* func(Node* node, int n, int m){
	int cnt = n;
	Node* cur = node;
	Node* nxt = node->next;
	Node* prv;

	bool deletion = false;
	while(nxt != NULL){
		if(!deletion){
			cnt--;
			prv = cur;
			cur = nxt;
			nxt = cur->next;
			if(cnt == 0){
				deletion = true;
				cnt = m;
			}
		}
		else{
			cnt--;
			prv-next = nxt;
			cur = nxt;
			nxt = cur->next;
			if(cnt == 0){
				deletion = false;
				cnt = n;
			}
		}
	} 
	return 
}