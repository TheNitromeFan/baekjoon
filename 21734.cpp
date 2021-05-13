#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	for(char c : s){
		int d = (int)c;
		int reps = 0;
		while(d > 0){
			reps += d % 10;
			d /= 10;
		}
		for(int i = 0; i < reps; ++i){
			cout << c;
		}
		cout << '\n';
	}
	return 0;
}
