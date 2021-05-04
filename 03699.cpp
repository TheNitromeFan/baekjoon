#include <iostream>
#include <utility>
#include <cstdlib>
#include <algorithm>
#define MAX 5000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int h, len;
		cin >> h >> len;
		pair<int, int> car[MAX];
		int cars = 0;
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < len; ++j){
				int x;
				cin >> x;
				if(x > 0){
					car[x] = make_pair(i, j);
				}
				if(x > cars){
					cars = x;
				}
			}
		}
		int belt[MAX] = {};
		int time = 0;
		for(int x = 1; x <= cars; ++x){
			int i = car[x].first, j = car[x].second;
			time += i * 10;
			time += min(abs(j - belt[i]), len - abs(j - belt[i])) * 5;
			belt[i] = j;
			time += i * 10;
		}
		cout << time << '\n';
	}
	return 0;
}
