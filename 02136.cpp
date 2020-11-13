#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
	return get<1>(a) < get<1>(b);
}

int main(){
	int n, len;
	scanf("%d %d", &n, &len);
	vector<tuple<int, int, int>> ants;
	ants.resize(n);
	int last_ant = 0, fall_time = 0;
	for(int i = 0; i < n; ++i){
		int ant;
		scanf("%d", &ant);
		ants[i] = make_tuple(i + 1, abs(ant), ant / abs(ant));
		if(ant > 0 && len - ant > fall_time){
			last_ant = i + 1;
			fall_time = len - ant;
		}else if(ant < 0 && -ant > fall_time){
			last_ant = i + 1;
			fall_time = -ant;
		}
	}
	sort(ants.begin(), ants.end(), cmp);
	/*
	for(int i = 0; i < n; ++i){
		printf("%d %d %d\n", get<0>(ants[i]), get<1>(ants[i]), get<2>(ants[i]));
	}
	*/
	int index;
	for(index = 0; index < n; ++index){
		if(get<0>(ants[index]) == last_ant){
			break;
		}
	}
	// printf("%d\n", last_ant);
	if(get<2>(ants[index]) == 1){
		for(int j = index + 1; j < n; ++j){
			if(get<2>(ants[j]) == -1){
				++index;
				last_ant = get<0>(ants[index]);
			}
		}
	}else{
		for(int j = index - 1; j >= 0; --j){
			if(get<2>(ants[j]) == 1){
				--index;
				last_ant = get<0>(ants[index]);
			}
		}
	}
	printf("%d %d", last_ant, fall_time);
	return 0;
}
