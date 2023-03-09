#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct node{
	string str;
	int left, right;
}tree[30];


void postOrder(int idx){
	if(idx == -1) return;
	if(tree[idx].left != -1 || tree[idx].right != -1){
		if(tree[idx].left == -1){
			cout << "(" << tree[idx].str;
			postOrder(tree[idx].right);
			cout << ")";
		}
		else{
			cout << "(";
			postOrder(tree[idx].left);
			postOrder(tree[idx].right);
			cout << tree[idx].str << ")";
		}
		
	}
	if(tree[idx].left == -1 && tree[idx].right == -1){
		cout << "(" << tree[idx].str << ")";
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> list(n+1);
	for(int i = 0; i < n; i++){
		cin >> tree[i+1].str;
		cin >> tree[i+1].left;
		cin >> tree[i+1].right;
		if(tree[i+1].left != -1)
			list[tree[i+1].left] = 1;
		if(tree[i+1].right != -1)
			list[tree[i+1].right] = 1;
	}
	// find root
	int i = 1;
	for(; i < n+1; i++){
		if(list[i] == 0) break;
	}
	// postOrder
	postOrder(i);
	cout << endl;
}