#include <cstdio>
#include <algorithm>
#define MAX (100000000 + 1)

bool select(int item[5000], int n, int c){
	std::sort(item, item + n);
	static bool p[MAX] = {};
	p[0] = true;
	for(int i = 0; i < n; ++i){
		p[item[i]] = true;
	}
	if(p[c]){
		return true;
	}
	for(int i = 0; i < n; ++i){
		if(item[i] > c){
			break;
		}else if(item[i] != c - item[i] && p[c - item[i]]){
			return true;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(item[i] + item[j] > c){
				break;
			}else if(item[i] != c - item[i] - item[j]
			&& item[j] != c - item[i] - item[j]
			&& p[c - item[i] - item[j]]){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	int stuff[5000];
	for(int i = 0; i < n; ++i){
		scanf("%d", &stuff[i]);
	}
	printf("%d", select(stuff, n, c));
	return 0;
}
