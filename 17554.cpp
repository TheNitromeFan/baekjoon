#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<bool> lights(n + 1);
	int k;
	cin >> k;
	int off = 0, max_off = 0;
	for(int a0 = 0; a0 < k; ++a0){
		int i;
		cin >> i;
		for(int j = i; j <= n; j += i){
			if(lights[j]){
				lights[j] = false;
				--off;
			}else{
				lights[j] = true;
				++off;
			}
		}
		if(max_off < off){
			max_off = off;
		}
	}
	cout << max_off;
	return 0;
}
