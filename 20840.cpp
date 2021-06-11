#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a_sets = 0, b_sets = 0;
	int a = 0, b = 0;
	int round = 1;
	for(char c : s){
		if(c == 'A'){
			++a;
			if(a - b >= 2 && (a >= 25 || (round == 3 && a >= 15))){
				++a_sets;
				++round;
				a = 0;
				b = 0;
				if(a_sets == 2){
					break;
				}
			}
		}else{
			++b;
			if(b - a >= 2 && (b >= 25 || (round == 3 && b >= 15))){
				++b_sets;
				++round;
				a = 0;
				b = 0;
				if(b_sets == 2){
					break;
				}
			}
		}
	}
	cout << a_sets << ' ' << b_sets;
	return 0;
}
