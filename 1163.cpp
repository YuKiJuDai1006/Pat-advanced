#include<iostream>
#include<vector>
#define maxn 20000

using namespace std;

int main(){
	int n, e;
	cin >> n >> e;
	vector<vector<int>> g(n, vector<int>(n, maxn));
	for(int i = 0; i < e; i++){
		int a, b, t;
		cin >> a >> b;
		cin >> t;
		g[a-1][b-1] = t;
		g[b-1][a-1] = t;
	}	
	int k;
	cin >> k;
	vector<vector<int>> judge(k, vector<int>(n));
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			int t;
			cin >> t;
			judge[i][j] = t-1;
		}
	}

	for(int i = 0; i < k; i++){
		int flag = 1;
		vector<int> dist(n, maxn);
		vector<bool> visit(n);
		dist[judge[i][0]] = 0;
		for(int w = 0; w < n; w++){
			int dis = 2*maxn;
			int idx;
			for(int j = 0; j < n; j++){
				if(!visit[j] && dist[j] < dis){
					dis = dist[j];
					idx = j;
				}
			}

			vector<bool> count(n);
			for(int j = 0; j < n; j++){
				if(!visit[j] && dist[j] == dis)
					count[j] = 1;
			}
			if(!count[judge[i][w]]){
				flag = 0;
				break;
			}


			visit[judge[i][w]] = 1;
			for(int j = 0; j < n; j++){
				dist[j] = min(dist[j], g[idx][j] + dist[idx]);
			}
		}

		if(flag == 0) cout << "No" << endl;
		else cout << "Yes" << endl;
	}

}