#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	vector<vector<string>> tab(26);
	for(int i = 0; i < 26; i++){
		vector<string> letter(7);
		for(int j = 0; j < 7; j++){
			cin >> letter[j];
		}
		tab[i] = letter;
	}
	getchar();

	string target;
	char ch = getchar();
	while(ch != '\n') target.push_back(ch);

	string com;
	vector<string> coms;

	int i = 0;
	while(i < target.size()){
		int t = target[i]-'A';
		while(i < target.size() && t >= 0 && t < 26){
			com.push_back(target[i++]);
			if(i == target.size()) break;
			t = target[i]-'A';
		}
		coms.push_back(com);
		com.clear();
		i++;
	}

	for(int i = 0; i < coms.size(); i++){
		for(int k = 0; k < 7; k++){
			for(int j = 0; j < coms[i].size(); j++){
				int t = coms[i][j]-'A';
				cout << tab[t][k];
				if(j != coms[i].size()-1)
					cout << " ";
			}
			cout << endl;
		}
		if(i != coms.size()-1)
			cout << endl;
	}
	
	
}