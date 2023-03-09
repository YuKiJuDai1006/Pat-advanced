#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
#include<unordered_set>

using namespace std;

int main(){
	int n1, n2;
	cin >> n1;
	vector<string> l1(n1);
	for(int i = 0; i < n1; i++) cin >> l1[i];

	cin >> n2;
	vector<string> l2(n2);
	int res2 = INT_MAX;
	string ret2;
	unordered_set<string> tab;
	for(int i = 0; i < n2; i++){
		cin >> l2[i];
		tab.insert(l2[i]);
		int old = 0;
		for(int j = 6; j <= 13; j++){
			old = old*10 + (l2[i][j] - '0');
		}
		if(old < res2){
			ret2 = l2[i];
			res2 = old;
		}
	
	}

	int count = 0;
	int res = INT_MAX;
	string ret;
	for(int i = 0; i < n1; i++){
		if(tab.count(l1[i])){
			++count;
			int old = 0;
			for(int j = 6; j <= 13; j++){
				old = old*10 + (l1[i][j] - '0');
			}
			if(old < res){
				ret = l1[i];
				res = old;
			}
		}
	}
	if(count){
		cout << count << endl << ret << endl;
	}
	else{
		cout << ret2 << endl;
	}
}