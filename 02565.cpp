#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> lines;
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		vector<int> tmp;
		tmp.push_back(a);
		tmp.push_back(b);
		lines.push_back(tmp);
	}
	sort(lines.begin(), lines.end());
	int max_noncross[100];
	int max_nc = 0;
	for(int i = 0; i < n; ++i){
		max_noncross[i] = 1;
		for(int j = 0; j <= i; ++j){
			if(lines[j][1] < lines[i][1] && max_noncross[j] + 1 > max_noncross[i]){
				max_noncross[i] = max_noncross[j] + 1;
			}
		}
		if(max_nc < max_noncross[i]){
			max_nc = max_noncross[i];
		}
	}
	cout << n - max_nc;
	return 0;
}
