#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> lunch(m);
	for(int i = 0; i < m; ++i){
		cin >> lunch[i];
	}
	sort(lunch.begin(), lunch.end());
	int cnt = 0;
	while(cnt < m && n >= lunch[cnt]){
		n -= lunch[cnt];
		++cnt;
	}
	cout << cnt;
	return 0;
}
