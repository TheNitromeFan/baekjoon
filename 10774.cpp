#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int j, a;
	cin >> j >> a;
	vector<char> sizes(j + 1);
	for(int i = 1; i <= j; ++i){
		cin >> sizes[i];
	}
	vector<bool> taken(j + 1);
	int cnt = 0;
	for(int k = 0; k < a; ++k){
		char size;
		int number;
		cin >> size >> number;
		if(!taken[number] && (size >= sizes[number])){
			++cnt;
			taken[number] = true;
		}
	}
	cout << cnt;
	return 0;
}
