#include<string>
#include<iostream>
using namespace std;

bool check(string s){
	int n = s.size();
	int res = 0;
	for(int i = 0; i < n; i++){
		res *= 10;
		res += s[i]-'0';
	}
	if(res == 0 || res == 1) return 0;
	for(int i = 2; i*i <= res; i++){
		if(res % i == 0) return 0;
	}
	return 1;
}

int main(){
	string s;
	cin >> s;
	int f = 1;
	while(s.size()){
		cout << s << " ";
		if(check(s)) cout << "Yes\n";
		else{
		 cout << "No\n";
		 f = 0;
		}
		s = s.substr(1);
	}
	if(f) cout << "All Prime!\n";
}
