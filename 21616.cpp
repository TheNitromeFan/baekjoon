#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n, k;
	cin >> m >> n >> k;
	vector<bool> rows(m + 1), cols(n + 1);
	int gold_rows = 0, gold_cols = 0;
	for(int i = 0; i < k; ++i){
		char rc;
		int q;
		cin >> rc >> q;
		if(rc == 'R'){
			if(rows[q]){
				rows[q] = false;
				--gold_rows;
			}else{
				rows[q] = true;
				++gold_rows;
			}
		}else{
			if(cols[q]){
				cols[q] = false;
				--gold_cols;
			}else{
				cols[q] = true;
				++gold_cols;
			}
		}
	}
	cout << gold_rows * n + m * gold_cols - 2 * gold_rows * gold_cols;
	return 0;
}
