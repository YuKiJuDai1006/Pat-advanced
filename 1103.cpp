#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> list, res;
vector<vector<int>> ans;
int maxn = -1;



void dfs(int n, int idx, int kn, vector<int>& com){
	if(n == 0 && kn == 0){
		int sum = 0;
		for(int i : com) sum += i;
		if(sum > maxn){
			maxn = sum;
			res = com;
		}
		return;
	}
	if(n < 0 || idx == list.size() || kn < 0) return;

	dfs(n, idx+1, kn, com);
	com.push_back(idx);
	dfs(n-list[idx], idx, kn-1, com);
	dfs(n-list[idx], idx+1, kn-1, com);
	com.pop_back();
}

int main(){
	int n, k, p;
	scanf("%d %d %d", &n, &k, &p);
	int i = 0;
	while(pow(i, p) <= n){
		list.push_back(pow(i,p));
		++i;
	}
	vector<int> com;
	dfs(n, 1, k, com);
	if(!res.empty()){
		printf("%d = ", n);
		for(int i = k-1; i >= 0; i--){
			if(i != 0){
				printf("%d^%d + ", res[i], p);
			}
			else printf("%d^%d\n", res[i], p);
		}
	}
	else printf("Impossible");

}