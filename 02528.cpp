#include <iostream>
#define MAX 3001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, len;
	cin >> n >> len;
	int start[MAX], end[MAX], dir[MAX];
	for(int i = 1; i <= n; ++i){
		int l;
		cin >> l >> dir[i];
		if(dir[i] == 0){
			start[i] = 0;
			end[i] = l;
		}else{
			end[i] = len;
			start[i] = len - l;
		}
	}
	int floor = 1;
	int time = 0;
	while(floor < n){
		while(floor < n && !(start[floor] > end[floor + 1] || end[floor] < start[floor + 1])){
			++floor;
		}
		if(floor == n){
			break;
		}
		++time;
		for(int i = floor; i <= n; ++i){
			if(dir[i] == 0){
				++start[i];
				++end[i];
				if(end[i] == len){
					dir[i] = 1;
				}
			}else{
				--start[i];
				--end[i];
				if(start[i] == 0){
					dir[i] = 0;
				}
			}
		}
	}
	cout << time;
	return 0;
}
