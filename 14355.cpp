#include <iostream>
#include <algorithm>

using namespace std;

bool simulate(string match){
	if(match.length() == 1){
		return true;
	}
	string new_match = "";
	for(unsigned idx = 0; idx < match.length(); idx += 2){
		if(match[idx] == match[idx + 1]){
			return false;
		}else if((match[idx] == 'P' && match[idx + 1] == 'R')
		|| (match[idx] == 'R' && match[idx + 1] == 'S')
		|| (match[idx] == 'S' && match[idx + 1] == 'P')){
			new_match += match[idx];
		}else{
			new_match += match[idx + 1];
		}
	}
	return simulate(new_match);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n, r, p, s;
		cin >> n >> r >> p >> s;
		string match = string(p, 'P') + string(r, 'R') + string(s, 'S');
		cout << "Case #" << a0 << ": ";
		bool found = false;
		do{
			if(simulate(match)){
				found = true;
				break;
			}
		}while(next_permutation(match.begin(), match.end()));
		if(found){
			cout << match;
		}else{
			cout << "IMPOSSIBLE";
		}
		cout << "\n";
	}
	return 0;
}
