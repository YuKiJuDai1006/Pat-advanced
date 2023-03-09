#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

int main(){
	string root;
	int n, k;
	cin >> root >> n >> k;

	unordered_map<int, string> next(n);
	unordered_map<string, int> tab(n);
	for(int i = 0; i < n; i++){
		string s;
		int val;
		cin >> s;
		cin >> val;
		tab[s] = val;
		cin >> next[val];
	}
	vector<int> preOrder(n);
	preOrder[0] = tab[root];
	for(int i = 1; i < n; i++){
		preOrder[i] = tab[next[preOrder[i-1]]];
	}

	// invert
	vector<int> ans;
	int t = n % k;
	for(int i = n-t; i >=0; i-=k){
		if(i == n-t){
			for(int j = i; j < n; j++)
				ans.push_back(preOrder[j]);
		}
		else{
			for(int j = i; j < i+k; j++)
				ans.push_back(preOrder[j]);
		}
	}
	unordered_map<int, string> tab2(n);
	for(auto& it : tab){
		tab2[it.second] = it.first;
	}
	int i = 0;
	for(; i < n-1; i++){
		cout << tab2[ans[i]] << " ";
		cout << ans[i] << " ";
		cout << tab2[ans[i+1]] << endl;
	}
	cout << tab2[ans[i]] << " ";
	cout << ans[i] << " " << "-1";


}