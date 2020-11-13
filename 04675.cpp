#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dictionary;

void read_dict(){
	while(true){
		string s;
		cin >> s;
		if(s == "XXXXXX"){
			break;
		}
		dictionary.push_back(s);
	}
}

vector<string> find_words(string s){
	vector<string> ans;
	sort(s.begin(), s.end());
	for(string word : dictionary){
		string consider = word;
		sort(word.begin(), word.end());
		if(s == word){
			ans.push_back(consider);
		}
	}
	return ans;
}

int main(){
	read_dict();
	while(true){
		string s;
		cin >> s;
		if(s == "XXXXXX"){
			break;
		}
		vector<string> ans = find_words(s);
		sort(ans.begin(), ans.end());
		if(ans.empty()){
			cout << "NOT A VALID WORD\n";
		}else{
			for(string a : ans){
				cout << a << '\n';
			}
		}
		cout << "******\n";
	}
	return 0;
}
