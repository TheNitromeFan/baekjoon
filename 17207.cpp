#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s[5] = {"Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki"};
	int a[5][5], v[5] = {};
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			int x;
			cin >> x;
			v[i] += x;
		}
	}
	int minWork = 1000000000, idx = -1;
	for(int i = 0; i < 5; ++i){
		int work = 0;
		for(int j = 0; j < 5; ++j){
			work += a[i][j] * v[j];
		}
		// cout << work << '\n';
		if(minWork >= work){
			minWork = work;
			idx = i;
		}
	}
	cout << s[idx];
	return 0;
}
