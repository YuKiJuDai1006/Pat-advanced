#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

int main(){
	string root1, root2;
	int n;
	cin >> root1 >> root2 >> n;

	unordered_map<string, int> vals;
	unordered_map<int, string> adds;
	unordered_map<int, string> nextAdds;
	// cin
	for(int i = 0; i < n; i++){
		string t;
		int val;
		cin >> t;
		cin >> val;
		vals[t] = val;
		adds[val] = t;
		cin >> nextAdds[val];
	}
	// len
	int len1 = 1, len2 = 1;
	vector<int> qe1;
	string r = root1;
	while(nextAdds[vals[r]] != "-1"){
		qe1.push_back(vals[r]);
		++len1;
		r = nextAdds[vals[r]];
	}
	qe1.push_back(vals[r]);

	vector<int> qe2;
	r = root2;
	while(nextAdds[vals[r]] != "-1"){
		qe2.push_back(vals[r]);
		++len2;
		r = nextAdds[vals[r]];
	}
	qe2.push_back(vals[r]);

	// reorder
	vector<int> res;
	if(len1 > len2){
		int f = 0, s = len2-1;
		while(f < len1){
			res.push_back(qe1[f++]);
			if(f < len1) res.push_back(qe1[f++]);
			if(s >= 0) res.push_back(qe2[s--]);
		}
	}
	else{
		int f = 0, s = len1-1;
		while(f < len2){
			res.push_back(qe2[f++]);
			if(f < len2) res.push_back(qe2[f++]);
			if(s >= 0) res.push_back(qe1[s--]);
		}
	}
	// cout
	int i = 0;
	for(; i < n-1; i++){
		cout << adds[res[i]] << " " << res[i] << " ";
		cout << adds[res[i+1]] << endl;
	}
	cout << adds[res[i]] << " " <<  res[i] << " ";
	cout << "-1" << endl;

}