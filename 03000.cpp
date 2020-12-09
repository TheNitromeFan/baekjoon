#include <iostream>
#define MAX 111111

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int px[MAX] = {}, py[MAX] = {}, cntx[MAX] = {}, cnty[MAX] = {};
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		px[i] = x;
		py[i] = y;
		++cntx[x];
		++cnty[y];
	}
	long long cnt = 0;
	for(int i = 0; i < n; ++i){
		cnt += (long long)(cntx[px[i]] - 1) * (cnty[py[i]] - 1);
	}
	cout << cnt;
	return 0;
}
