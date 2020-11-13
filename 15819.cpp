#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, i;
	cin >> n >> i;
	vector<string> names(n, "");
	for(int j = 0; j < n; ++j){
		cin >> names[j];
	}
	sort(names.begin(), names.end());
	cout << names[i - 1];
	return 0;
}
