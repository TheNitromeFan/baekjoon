#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<string> dict;
	while(true){
		string word;
		getline(cin, word);
		if(word == "##"){
			break;
		}
		dict.push_back(word);
	}
	while(true){
		string line;
		getline(cin, line);
		if(line == "#"){
			break;
		}
		for(unsigned idx = 0; idx + 3 < line.length(); ++idx){
			if(!(line[idx] >= 'a' && line[idx] <= 'z' && line[idx + 1] >= 'a' && line[idx + 1] <= 'z'
			&& line[idx + 2] >= 'a' && line[idx + 2] <= 'z' && line[idx + 3] >= 'a' && line[idx + 3] <= 'z')){
				continue;
			}
			for(string word : dict){
				if(line[idx] == word[0] && line[idx + 3] == word[1]){
					line[idx + 1] = '*';
					line[idx + 2] = '*';
					break;
				}
			}
		}
		cout << line << '\n';
	}
	return 0;
}
