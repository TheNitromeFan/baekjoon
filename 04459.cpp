#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	vector<string> rules(q + 1);
	string line;
	getline(cin, line);
	for(int i = 1; i <= q; ++i){
		getline(cin, line);
		rules[i] = line;
	}
	int r;
	cin >> r;
	for(int j = 0; j < r; ++j){
		int num;
		cin >> num;
		if(num >= 1 && num <= q){
			cout << "Rule " << num << ": " << rules[num] << "\n";
		}else{
			cout << "Rule " << num << ": " << "No such rule\n";
		}
	}
	return 0;
}
