#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
	node(int x){
		val = x;
	}
};
node* dfs(vector<int>& list, int l, int r){
	if(l > r) return nullptr;
	if(l == r) return new node(list[l]);
	int min = INT_MAX;
	int idx;
	for(int i = l; i <= r; i++){
		if(list[i] < min){
			idx = i;
			min = list[i];
		}
	}
	node* ret = new node(min);
	ret->left = dfs(list, l, idx-1);
	ret->right = dfs(list, idx+1, r);
	return ret;
}	

int main(){
	int n;
	cin >> n;
	vector<int> list(n);
	for(int i = 0; i < n; i++) cin >> list[i];
	node* root = dfs(list, 0, n-1);
	
	queue<node*> qe;
	cout << root->val;
	if(root->left)	qe.push(root->left);
	if(root->right)	qe.push(root->right);
	while(!qe.empty()){
		cout << " " << qe.front()->val;
		if(qe.front()->left)	qe.push(qe.front()->left);
		if(qe.front()->right)	qe.push(qe.front()->right);
		qe.pop();
	}
	cout << endl;
}
