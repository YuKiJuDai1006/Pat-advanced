#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
	int n, r, k;
	cin >> n >> r >> k;

	vector<vector<int>> tab(r);
	for(int i = 0; i < r; i++){
		vector<int> com(2);
		cin >> com[0] >> com[1];
		tab[i] = com;
	}
	int p;
	cin >> p;
	for(int i = 0; i < p; i++){
		vector<int> temp(n);
		unordered_set<int> myset;
		for(int j = 0; j < n; j++){
			cin >> temp[j];
			myset.insert(temp[j]);
		}
		if(myset.size() > k){
			cout << "Error: Too many species.\n";
		}
		else if((int)myset.size() < k){
			cout << "Error: Too few species.\n";
		}
		else{
			int flag = 1;
			for(int i = 0; i < n; i++){
				vector<int> compare;
				for(int k = 0; k < r; k++){
					if(tab[k][0] == i+1) compare.push_back(tab[k][1]-1);
					if(tab[k][1] == i+1) compare.push_back(tab[k][0]-1);
				}	
				for(int k = 0; k < (int)compare.size(); k++){
					if(temp[i] == temp[compare[k]]){
						flag = 0;
						break;
					}
				}
			}
			if(flag == 0) cout << "No\n";
			if(flag == 1) cout << "Yes\n";
		}
	}
}