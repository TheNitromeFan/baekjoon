#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

bool path(int row[MAX], int col[MAX], int psum_row[MAX], int psum_col[MAX], int ra, int ca, int rb, int cb){
	if(ra > rb){
		swap(ra, rb);
	}
	if(row[ra] % 2 == 0 && psum_row[rb] - psum_row[ra - 1] != rb - ra + 1){
		return false;
	}else if(row[ra] % 2 == 1 && psum_row[rb] - psum_row[ra - 1] != 0){
		return false;
	}
	if(ca > cb){
		swap(ca, cb);
	}
	if(col[ca] % 2 == 0 && psum_col[cb] - psum_col[ca - 1] != cb - ca + 1){
		return false;
	}else if(col[ca] % 2 == 1 && psum_col[cb] - psum_col[ca - 1] != 0){
		return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	int row[MAX], col[MAX];
	for(int i = 1; i <= n; ++i){
		cin >> row[i];
	}
	for(int i = 1; i <= n; ++i){
		cin >> col[i];
	}
	int psum_row[MAX] = {}, psum_col[MAX] = {};
	for(int i = 1; i <= n; ++i){
		psum_row[i] = psum_row[i - 1] + (row[i] % 2 == 0);
		psum_col[i] = psum_col[i - 1] + (col[i] % 2 == 0);
	}
	for(int j = 0; j < q; ++j){
		int ra, ca, rb, cb;
		cin >> ra >> ca >> rb >> cb;
		cout << (path(row, col, psum_row, psum_col, ra, ca, rb, cb) ? "YES\n" : "NO\n");
	}
	return 0;
}
