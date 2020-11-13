#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	vector<int> w, k;
	for(int i = 0; i < 10; ++i){
		int s;
		cin >> s;
		w.push_back(s);
	}
	for(int i = 0; i < 10; ++i){
		int s;
		cin >> s;
		k.push_back(s);
	}
	sort(w.begin(), w.end(), greater<int>());
	sort(k.begin(), k.end(), greater<int>());
	cout << w[0] + w[1] + w[2] << ' ' << k[0] + k[1] + k[2];
	return 0;
}
