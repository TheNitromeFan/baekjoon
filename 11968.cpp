#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<bool> v(2 * n + 1);
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		v[x] = true;
	}
	int cards = 0;
	int points = 0;
	for(int x = 2 * n; x >= 1; --x){
		if(v[x]){
			if(cards > 0){
				++points;
				--cards;
			}
		}else{
			++cards;
		}
	}
	cout << points << '\n';
	return 0;
}
