#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::sort;
using std::endl;

int main(){
	vector<int> v;
	int num;
	for(int i = 0; i < 3; ++i){
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < 3; ++i){
		cout << v[i] << ' ';
	}
	cout << endl;
	return 0;
}
