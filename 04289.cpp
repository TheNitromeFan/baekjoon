#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct player{
	int wins;
	int losses;
} players[101];

int main(){
	while(true){
		int n, k;
		cin >> n;
		if(n == 0){
			break;
		}
		for(int i = 1; i <= n; ++i){
			players[i].wins = 0;
			players[i].losses = 0;
		}
		cin >> k;
		int games = k * n * (n - 1) / 2;
		for(int game = 0; game < games; ++game){
			int p1, p2;
			string m1, m2;
			cin >> p1 >> m1 >> p2 >> m2;
			if((m1 == "rock" && m2 == "scissors") || (m1 == "paper" && m2 == "rock") || (m1 == "scissors" && m2 == "paper")){
				++players[p1].wins;
				++players[p2].losses;
			}else if((m2 == "rock" && m1 == "scissors") || (m2 == "paper" && m1 == "rock") || (m2 == "scissors" && m1 == "paper")){
				++players[p2].wins;
				++players[p1].losses;
			}
		}
		for(int i = 1; i <= n; ++i){
			int total = players[i].wins + players[i].losses;
			if(total == 0){
				cout << '-';
			}else{
				cout << fixed << setprecision(3) << static_cast<double>(players[i].wins) / total;
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
