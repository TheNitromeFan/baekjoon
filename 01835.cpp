#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	int pos = n - 1;
	for(int card = 1; card <= n; ++card){
		int cnt = 0;
		while(cnt < card){
			pos = (pos + 1) % n;
			if(v[pos] != 0){
				continue;
			}
			++cnt;
		}
		do{
			pos = (pos + 1) % n;
		}while(v[pos] != 0);
		v[pos] = card;
	}
	for(int idx = 0; idx < n; ++idx){
		cout << v[idx] << ' ';
	}
	return 0;
}
