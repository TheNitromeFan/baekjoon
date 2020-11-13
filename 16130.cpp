#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		string penalty;
		cin >> penalty;
		int points = 0;
		int weeks = 0;
		bool indefinite = false, permanent = false;
		for(char c : penalty){
			int newPenalty = 0;
			if(c >= '0' && c <= '9'){
				newPenalty += c - '0';
			}else{
				newPenalty += c - 'A' + 10;
			}
			if(points / 10 == (points + newPenalty) / 10){
				points += newPenalty;
				continue;
			}
			points += newPenalty;
			if(points / 10 > 4){
				permanent = true;
				break;
			}else if(points / 10 == 4){
				indefinite = true;
				break;
			}else{
				weeks += points / 10;
			}
		}
		cout << weeks;
		if(indefinite){
			cout << "(weapon)";
		}
		if(permanent){
			cout << "(09)";
		}
		cout << '\n';
	}
	return 0;
}
