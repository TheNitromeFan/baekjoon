#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int hole = 0;
	while(true){
		++hole;
		int p, s;
		cin >> p >> s;
		if(p == 0 && s == 0){
			break;
		}
		cout << "Hole #" << hole << "\n";
		if(s == 1){
			cout << "Hole-in-one";
		}else if(p - s == 3){
			cout << "Double eagle";
		}else if(p - s == 2){
			cout << "Eagle";
		}else if(p - s == 1){
			cout << "Birdie";
		}else if(p - s == 0){
			cout << "Par";
		}else if(p - s == -1){
			cout << "Bogey";
		}else{
			cout << "Double Bogey";
		}
		cout << ".\n\n";
	}
	return 0;
}
