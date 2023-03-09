#include<iostream>
#include<vector>
using namespace std;

int res = 100001;
int nums = 0;

struct node{
	int count = 0;
	vector<int> next;
}tree[100001];

void dfs(int root, int lev){
	if(tree[root].count == 0){
		if(lev == res) ++nums;
		if(lev < res){
			res = lev;
			nums = 1;
		}
		return;
	}
	for(int i = 0; i < tree[root].count; i++){
		dfs(tree[root].next[i], lev+1);
	}
}

int main(){
	int n; 
	double p, r;
	cin >> n >> p >> r;

	bool child[n] = {0};
	for(int i = 0; i < n; i++){
		int ns;
		cin >> ns;
		tree[i].count = ns;
		for(int j = 0; j < ns; j++){
			int t;
			cin >> t;
			child[t] = 1;
			tree[i].next.push_back(t);
		}
	}
	int root = -1;
	for(int i = 0; i < n; i++){
		if(child[i] == 0){
			root = i;
			break;
		}
	}
	
	dfs(root, 0);

	double ans = p;
	while(res > 0){
		ans *= (1+r/100);
		--res;
	}
	printf("%.4f %d\n", ans, nums);
}