#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int s;
		cin >> s;
		vector<int> blue, red;
		for(int i = 0; i < s; ++i){
			string rope;
			cin >> rope;
			int len = 0;
			for(unsigned j = 0; j + 1 < rope.length(); ++j){
				len *= 10;
				len += rope[j] - '0';
			}
			if(rope[rope.length() - 1] == 'B'){
				blue.push_back(len);
			}else{
				red.push_back(len);
			}
		}
		sort(blue.begin(), blue.end(), greater<int>());
  		sort(red.begin(), red.end(), greater<int>());
		unsigned iter = min(blue.size(), red.size());
		int knot = 0;
		for(unsigned j = 0; j < iter; ++j){
			knot += blue[j] + red[j] - 2;
		}
		cout << "Case #" << a0 << ": " << knot << "\n";
	}
	return 0;
}
