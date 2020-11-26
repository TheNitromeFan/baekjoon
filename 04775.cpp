#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<string> dict;
	for(int i = 0; i < n; ++i){
		string word;
		cin >> word;
		dict.insert(word);
	}
	int m;
	cin >> m;
	for(int x = 1; x <= m; ++x){
		vector<string> incorrect;
		string word;
		while(true){
			cin >> word;
			if(word == "-1"){
				break;
			}
			if(dict.find(word) == dict.end()){
				incorrect.push_back(word);
			}
		}
		if(!incorrect.empty()){
			cout <<"Email " << x << " is not spelled correctly.\n";
			for(string word : incorrect){
				cout << word << "\n";
			}
		}else{
			cout << "Email " << x << " is spelled correctly.\n";
		}
	}
	cout << "End of Output";
	return 0;
}
