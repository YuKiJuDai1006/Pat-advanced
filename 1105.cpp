#include<iostream>
#include<vector>
#include<cmath>  // sqrt
#include<algorithm>  // sort
using namespace std;

bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n;
	cin >> n;

	int y = (int)sqrt(n);
	int x;
	for(; y >= 1; y--){
		if(n % y == 0){
			x = n/y;
			break;
		}
	}
	vector<vector<int>> m(x, vector<int>(y));

	vector<int> list(n);
	for(int i = 0; i < n; i++)
		cin >> list[i];


	sort(list.begin(), list.end(), cmp);

	int l = -1, r = y-1, up = 0, down = x-1;
	int i = 0, j = 0;
	for(int k = 0; k < n; k++){
		if(k == n-1){
			m[i][j] = list[k];
			break;
		}
		if(i == up && j < r){
			if(j == r-1) l++;
			m[i][j++] = list[k];
			continue;
		}
		if(j == r && i < down){
			if(i == down-1) up++;
			m[i++][j] = list[k];
			continue;
		}
		if(i == down && j > l){
			if(j == l+1) r--;
			m[i][j--] = list[k];
			continue;
		}
		if(j == l && i > up){
			if(i == up+1) down--;
			m[i--][j] = list[k];
			continue;
		}
	}

	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cout << m[i][j];
			if(j != y-1) cout << " "; 
		}
		cout << endl;
	}
}