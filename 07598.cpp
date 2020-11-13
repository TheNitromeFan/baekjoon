#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string flight;
		int seats;
		cin >> flight >> seats;
		if(flight == "#" && seats == 0){
			break;
		}
		while(true){
			string action;
			int amount;
			cin >> action >> amount;
			if(action == "X" && amount == 0){
				break;
			}
			if(action == "B" && seats + amount <= 68){
				seats += amount;
			}else if(action == "C" && amount <= seats){
				seats -= amount;
			}
		}
		cout << flight << ' ' << seats << '\n';
	}
	return 0;
}
