#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
	int n, r;
	cin >> n >> r;
	unordered_map<int, vector<int>> tab(n+1);
	for(int i = 0; i < r; i++){
		int l, r;
		cin >> l >> r;
		tab[l].push_back(r);
		tab[r].push_back(l);
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		vector<int> now;
		vector<int> count(n+1);
		int nums;
		cin >> nums;
		for(int j = 0; j < nums; j++){
			int t;
			cin >> t;
			now.push_back(t);
			for(int w = 0; w < tab[t].size(); w++)
				++count[tab[t][w]];
		}
		int flag = 1;
		for(int j = 0; j < now.size(); j++){
			if(count[now[j]] != nums-1){
				flag = 0;
				cout << "Area " << i+1 << " needs help.\n";
				break;
			}
			else count[now[j]] = 0;
		}
		if(flag){
			int flagg = 1;
			for(int j = 0; j < n+1; j++){
				if(count[j] == nums){
					flagg = 0;
					cout <<  "Area " << i+1 << " may invite more people, ";
					cout << "such as " << j << ".\n";
					break;
				}
			}
			if(flagg) cout << "Area " << i+1 << " is OK.\n";
		}

	}
}