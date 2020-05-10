#include<iostream>
#include<vector>
using namespace std;

struct line{
	double a,b,c;
};

struct point{
	double x,y;
};

struct node{
	line l; 
	struct node* lt;
	struct node* rt;
	int left,right;
	node(){
		this->lt=NULL;
		this->rt=NULL;
		left=0;
		right=0;
	}
};
typedef node* tree;


double infinity=1e13;
const int max_points=1e6 + 1;
int num_points[max_points];

vector<line> lines;
vector<pair<point,point> > endpoints;
vector<point> points;


bool intersect(line l1, line l2){ // if false then parallel
	return (l1.a)*(l2.b)-(l2.a)*(l1.b) != 0;
}

double value(point p,line l){
	return (l.a)*(p.x)+(l.b)*(p.y)-(l.c);
}

bool twoparts(point p1, point p2, line l){
	return value(p1,l)*value(p2,l)<0;
}

point intersection_point(line l1, line l2){
	point ans;
	double denom=(l1.a)*(l2.b)-(l2.a)*(l1.b);
	ans.x=((l1.c)*(l2.b)-(l2.c)*(l1.b))/denom;
	ans.y=((l2.c)*(l1.a)-(l1.c)*(l2.a))/denom;
	return ans;
}

tree insert(line l, point p1, point p2, tree t){
	if(t==NULL){
		t=new node();
		t->l=l;
		return t;
	}
	else
	{
		line l2=t->l;
		if(intersect(l,l2)){
			point inter=intersection_point(l,l2);
			if(value(p1,l2)>0){ // p1 right
				if(value(p2,l2)>=0){ // p2 right or p2 on line
					t->rt=insert(l,p1,p2,t->rt);
					return t;
					
				}
				else{ // p2 left p1 right
					t->lt=insert(l,inter,p2,t->lt);
					t->rt=insert(l,p1,inter,t->rt);
					return t;
				} 
			}
			else if(value(p1,l2)<0){ // p1 left
				if(value(p2,l2)<=0){ // p2 left or p2 on line
					t->lt=insert(l,p1,p2,t->lt);
					return t;
				}
				else{ // p2 right p1 left
					t->lt=insert(l,inter,p1,t->lt);
					t->rt=insert(l,p2,inter,t->rt);
					return t;
				}
			}
			else{ // p1 on line
				if(value(p2,l2)<0){ // p2 left p1 on line
					t->lt=insert(l,p1,p2,t->lt);
					return t;
				}
				else if(value(p2,l2)>0){ // p2 right p1 on line
					t->rt=insert(l,p1,p2,t->rt);
					return t;
				}
				else{ // p1 p2 both on line
					return t;
				}
			}
		}
		else{ // parallel lines
			if(value(p1,l2)<0){
				t->lt=insert(l,p1,p2,t->lt);
				return t;
			}
			else if(value(p1,l2)>0){
				t->rt=insert(l,p1,p2,t->rt);
				return t;
			}
			else{
				return t;
			}
		}
	}
}



int num_leaves(tree t){
	if(t==NULL) return 1;
	else return num_leaves(t->lt)+num_leaves(t->rt);
}

int height(tree t){
	if(t==NULL) return 0;
	else return 1+max(height(t->lt),height(t->rt));
}


void point_in_region(point p,tree t){
	if(t==NULL) return;
	if(value(p,t->l)<0){ // left
		if(t->lt==NULL) t->left++;
		else point_in_region(p,t->lt);
	}
	else if(value(p,t->l)>0){
		if(t->rt==NULL) t->right++;
		else point_in_region(p,t->rt);	
	}
}

void add_up(tree t){
	if(t->lt==NULL){
		num_points[t->left]++;
	}
	else add_up(t->lt);
	if(t->rt==NULL){
		num_points[t->right]++;
	}
	else add_up(t->rt);
}

int main(){
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++){
		line temp;
		double a,b,c;
		cin>>a>>b>>c;
		//if(a<0){ a=-a;b=-b;c=-c;}
		temp.a=a;
		temp.b=b;
		temp.c=c;
		lines.push_back(temp);
	}
	for(int i=0;i<m;i++){
		point temp;
		double x,y;
		cin>>x>>y;
		temp.x=x;
		temp.y=y;
		points.push_back(temp);
	}

	// giving endpoints
	for(int i=0;i<n;i++){
		line l=lines[i];
		if(l.b==0){ // l is vertical
			pair<point,point> p;
			point p1; point p2;
			p1.x=(l.c)/(l.a);
			p1.y=infinity;
			p2.x=(l.c)/(l.a);
			p2.y=-infinity;
			p.first=p1;
			p.second=p2;
			endpoints.push_back(p);
		}
		else{
			pair<point,point> p;
			point p1; point p2;
			p1.x=infinity;
			p1.y=((l.c)-(l.a)*infinity)/(l.b);
			p2.x=-infinity;
			p2.y=((l.c)+(l.a)*infinity)/(l.b);
			p.first=p1;
			p.second=p2;
			endpoints.push_back(p);
		}
	}

	tree tr=new node();
	tr->l=lines[0];

	for(int i=1;i<n;i++){
		tr=insert(lines[i],endpoints[i].first,endpoints[i].second,tr);
	}

	cout<<num_leaves(tr)<<" "<<height(tr)<<endl;

	//second part

	for(int i=0;i<m;i++){
		point_in_region(points[i],tr);
	}
	add_up(tr);
	for(int i=0;i<max_points;i++){
		if(num_points[i]!=0) cout<<i<<" "<<num_points[i]<<endl;
	}
}