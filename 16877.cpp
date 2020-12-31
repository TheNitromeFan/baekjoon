#include <iostream>
#define MAX 3000001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int fibs[34] = {};
	fibs[1] = 1;
	for(int j = 2; j < 34; ++j){
		fibs[j] = fibs[j - 1] + fibs[j - 2];
	}
	int grundyArr[MAX] = {};
	grundyArr[1] = 1;
	grundyArr[2] = 2;
	grundyArr[3] = 3;
	for(int i = 4; i < MAX; ++i){
		bool check[16] = {};
		for(int j = 2; j < 34; ++j){
			if(fibs[j] <= i){
				check[grundyArr[i - fibs[j]]] = true;
				continue;
			}
			for(int k = 0; k < 16; ++k){
				if(!check[k]){
					grundyArr[i] = k;
					break;
				}
			}
		}
	}
	int res = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		res ^= grundyArr[x];
	}
	cout << (res == 0 ? "cubelover" : "koosaga");
	return 0;
}
