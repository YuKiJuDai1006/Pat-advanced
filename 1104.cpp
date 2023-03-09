#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	long long res = 0;
	int t = n;
	double num;
	for(int i = 0; i < n; i++){
		cin >> num;
		res += (long long) (num*1000) * (t--) * (i+1);
	}
	printf("%.2f\n", res/1000.0);
}