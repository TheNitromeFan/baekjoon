#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t, t0;
	cin >> n >> t >> t0;
	for(int i = 0; i < n; ++i){
		int mi;
		cin >> mi;
		vector<int> ti(mi);
		for(int j = 0; j < mi; ++j){
			cin >> ti[j];
		}
		int max_time = 0, max_index = -1;
		int problems = 0;
		int time = 0;
		while(problems < mi && time + ti[problems] <= t){
			time += ti[problems];
			if(max_time < ti[problems]){
				max_time = ti[problems];
				max_index = problems;
			}
			++problems;
		}
		if(problems < mi && max_time < ti[problems]){
			max_time = ti[problems];
			max_index = problems;
		}
		if(max_time > t0){
			ti[max_index] = t0;
		}
		problems = 0;
		time = 0;
		while(problems < mi && time + ti[problems] <= t){
			time += ti[problems];
			++problems;
		}
		cout << problems << '\n';
	}
	return 0;
}
