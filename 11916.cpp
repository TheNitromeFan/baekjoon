#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	bool bases[4] = {};
	int ball_count = 0;
	int points = 0;
	for(int i = 0; i < n; ++i){
		int pitch;
		cin >> pitch;
		if(pitch == 1){
			++ball_count;
			if(ball_count == 4){
				if(bases[1]){
					if(bases[2]){
						if(bases[3]){
							++points;
						}
						bases[3] = true;
					}
					bases[2] = true;
				}
				bases[1] = true;
				ball_count = 0;
			}
		}else if(pitch == 2){
			if(bases[1]){
				if(bases[2]){
					if(bases[3]){
						++points;
					}
					bases[3] = true;
				}
				bases[2] = true;
			}
			bases[1] = true;
			ball_count = 0;
		}else if(pitch == 3){
			if(bases[3]){
				++points;
				bases[3] = false;
			}
			if(bases[2]){
				bases[3] = true;
				bases[2] = false;
			}
			if(bases[1]){
				bases[2] = true;
				bases[1] = false;
			}
			++ball_count;
			if(ball_count == 4){
				bases[1] = true;
				ball_count = 0;
			}
		}
	}
	cout << points;
	return 0;
}
