#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main(){
	int st1, st2, n, r;
	cin >> st1 >> st2 >> n >> r;
	unordered_set<int> myset;
	unordered_set<int> pool;
	vector<vector<int>> tab(n, vector<int>(r));
	vector<bool> flag(n, 1);

	myset.insert(st1);
	myset.insert(st2);
	pool.insert(st1-st2);
	pool.insert(st2-st1);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < r; j++){
			cin >> tab[i][j];
		}
	}
	int count = n;
	for(int j = 0; j < r; j++){
		for(int i = 0; i < n; i++){
			if(flag[i]){
				if(pool.count(tab[i][j]) && !myset.count(tab[i][j])){
					myset.insert(tab[i][j]);
					for(int t : myset){
						pool.insert(t - tab[i][j]);
						pool.insert(tab[i][j] - t);
					}
				}
				else{
					flag[i] = 0;
					--count;
					cout << "Round #" << j+1 << ": " << i+1 << " is out.\n";
				}
			}
		}
	}
	
	if(count){
		cout << "Winner(s):";
		for(int i = 0; i < n; i++){
			if(flag[i] == 1 && count){
				cout << " " << i+1;
				--count;
				if(count == 0) cout << endl;
			}
		}
	}
	else cout << "No winner.\n";

}