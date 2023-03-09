	#include<iostream>
	#include<vector>
	#include<cmath>
	using namespace std;

	int sum(long long int i){
		long long int res = 0;
		while(i != 0){
			res += i%10;
			i /= 10;
		}
		return res;
	}

	void mylist(vector<long long int>& list, int k, int m){
		long long int end = pow(10, k);
		long long int begin = pow(10, k-1);
		for(long long int i = begin; i < end; i++){
			if(sum(i) == m) list.push_back(i);
		}
	}


	bool check(int m, int n){
		if(m <= 2 || n <= 2) return 0;
		int i = min(m, n);
		for(; i > 2; i--){
			if(m % i == 0 && n % i == 0) break;
		}
		if(i == 2) return 0;
		bool flag = 1;
		for(int j = 2; j*j <= i; j++){
			if(i%j == 0){
				flag = 0;
				break;
			}
		}
		return flag;
	}

	int main(){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cout << "Case " << i+1 << endl;
			int k, m;
			cin >> k >> m;
			vector<long long int> list;
			mylist(list, k, m);
			bool flag = 0;
			for(int j = 0; j < list.size(); j++){
				int n = sum(list[j]+1);
				if(check(m, n)){
					flag = 1;
					cout << n << " " << list[j] << endl;
				}
			}
			if(!flag) cout << "No Solution" << endl;

		}
	}