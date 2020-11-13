#include <iostream>
#include <string>

using namespace std;

bool valid(string plate){
	for(unsigned i = 0; i < 8; ++i){
		if(i == 4 && !(plate[i] >= 'A' && plate[i] <= 'Z')){
			return false;
		}else if(i != 4 && !(plate[i] >= '1' && plate[i] <= '9')){
			return false;
		}
	}
	return plate[0] == plate[1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string plate;
		cin >> plate;
		if(valid(plate)){
			cout << plate << '\n';
		}
	}
	return 0;
}
