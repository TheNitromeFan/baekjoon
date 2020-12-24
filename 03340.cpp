#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, n;
	cin >> c >> n;
	vector<int> last(c + 1, -1);
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		last[x] = i;
	}
	vector<int> rows;
	for(int row = 1; row <= c; ++row){
		rows.push_back(row);
	}
	sort(rows.begin(), rows.end(), [&last](int row1, int row2){
		return last[row1] < last[row2];
	});
	unsigned idx = 0;
	while(idx < rows.size() && last[rows[idx]] == -1){
		++idx;
	}
	cout << rows.size() - idx << '\n';
	for(; idx < rows.size(); ++idx){
		cout << rows[idx] << ' ';
	}
	return 0;
}
