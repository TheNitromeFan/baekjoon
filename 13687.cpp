#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int t, n;
		cin >> t >> n;
		if(t == 0 && n == 0){
			break;
		}
		int points = 0;
		for(int i = 0; i < t; ++i){
			string team;
			int score;
			cin >> team >> score;
			points += score;
		}
		cout << 3 * n - points << '\n';
	}
	return 0;
}
