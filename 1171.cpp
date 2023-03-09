#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int n, m;
int myMax(vector<int>& cache, int minmax){
	int idx = -1;
	int now = INT_MAX;
	for(int i = 0; i < m; i++){
		if(cache[i] >= minmax && cache[i] < now){
			now = cache[i];
			idx = i;
		}
	}
	return idx;
}

int main(){
	cin >> n >> m;
	vector<int> list(n);
    int t;
	for(int i = 0; i < n; i++) cin >> list[i];

	vector<int> cache(m);
	

	int minmax = INT_MAX;
	int pos = -1;
	for(int i = 0; i < m; i++){
		cache[i] = list[i];
		if(list[i] < minmax){
			minmax = list[i];
			pos = i; 
		}
	}

	vector<vector<int>> coms;
	vector<int> com;

	com.push_back(minmax);
	int idx = m;
	cache[pos] = list[idx++];

	int count = m;
	while(count){
		while(count && myMax(cache, minmax) != -1){
			int pos = myMax(cache, minmax);
			minmax = cache[pos];
			com.push_back(cache[pos]);
			if(idx < n) cache[pos] = list[idx++];
			else{
				cache[pos] = -1;
				count--;
			}
		}
		coms.push_back(com);
		com.clear();
		minmax = 0;
	}


	//输出
	for(int i = 0; i < coms.size(); i++){
		for(int j = 0; j < coms[i].size(); j++){
			cout << coms[i][j];
			if(j != coms[i].size()-1) cout << " ";
		}
		cout << endl;
	}
}