#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	int q;
	cin >> n >> q;
	unordered_set<long long> rows, cols;
	long long rows_cnt = 0, cols_cnt = 0;
	long long rows_sum = 0, cols_sum = 0;
	for(int i = 0; i < q; ++i){
		char a;
		long long b;
		cin >> a >> b;
		long long ans = 0;
		if(a == 'R' && rows.find(b) == rows.end()){
			ans = n * b + n * (n + 1) / 2 - cols_cnt * b - cols_sum;
			rows.insert(b);
			++rows_cnt;
			rows_sum += b;
		}else if(a == 'C' && cols.find(b) == cols.end()){
			ans = n * b + n * (n + 1) / 2 - rows_cnt * b - rows_sum;
			cols.insert(b);
			++cols_cnt;
			cols_sum += b;
		}
		cout << ans << '\n';
	}
	return 0;
}
