#include<iostream>

using namespace std;

int check(int k){
	if(k == 8) return 2;
	// itself
	int flag = 1;
	for(int i = 2; i*i <= k; i++){
		if(k % i == 0){
			flag = 0;
			break;
		}
	}
	if(flag == 0) return -1;

	// low
	if(k > 8){
		int t = k-6;
		flag = 1;
		for(int i = 2; i*i <= t; i++){
			if(t % i == 0){
				flag = 0;
				break;
			}
		}
		if(flag == 1) return t;
	}

	// high
	int t = k+6;
		flag = 1;
		for(int i = 2; i*i <= t; i++){
			if(t % i == 0){
				flag = 0;
				break;
			}
		}
	if(flag == 1) return t;
	return -1;
}

int main(){
	int k;
	cin >> k;
	if(k == 1){
		cout << "No\n" << "5" << endl;
		return 0;
	}

	int ret = check(k);
	if(ret != -1){
		cout << "Yes\n" << ret << endl;
	}
	else{
		int flag = 1;
		int res;
		while(flag){
			res = check(++k);
			if(res != -1) flag = 0;
		}
		cout << "No\n" << k << endl;
	}
}