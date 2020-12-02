#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int c;
	cin >> c;
	vector<int> top(n);
	for(int i = 0; i < n; ++i){
		cin >> top[i];
	}
	sort(top.begin(), top.end(), greater<int>());
	int calories = c, price = a;
	double ratio = calories / (double)price;
	for(int i = 0; i < n; ++i){
		calories += top[i];
		price += b;
		double ratio1 = calories / (double)price;
		if(ratio < ratio1){
			ratio = ratio1;
		}
	}
	cout << (int)ratio;
	return 0;
}
