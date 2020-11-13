#include <cstdio>
#define MAX 100

bool find(int plug[MAX], int n, int item){
	for(int i = 0; i < n; ++i){
		if(plug[i] == item){
			return true;
		}
	}
	return false;
}

int empty(int plug[MAX], int n){
	for(int i = 0; i < n; ++i){
		if(plug[i] == 0){
			return i;
		}
	}
	return -1;
}

bool never_used_again(int items[MAX], int k, int cur_idx, int item){
	for(int j = cur_idx + 1; j < k; ++j){
		if(items[j] == item){
			return false;
		}
	}
	return true;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int items[MAX];
	for(int j = 0; j < k; ++j){
		scanf("%d", &items[j]);
	}
	int plug[MAX] = {};
	int cnt = 0;
	for(int j = 0; j < k; ++j){
		int x = items[j];
		if(find(plug, n, x)){
			continue;
		}
		int idx = empty(plug, n);
		if(idx != -1){
			plug[idx] = x;
			continue;
		}
		++cnt;
		bool unplugged = false;
		for(int i = 0; i < n; ++i){
			if(never_used_again(items, k, j, plug[i])){
				plug[i] = x;
				unplugged = true;
				break;
			}
		}
		if(unplugged){
			continue;
		}
		int plug_idx = 0, next_used = -1;
		for(int i = 0; i < n; ++i){
			int item = plug[i];
			int m = j + 1;
			for(; m < k; ++m){
				if(items[m] == item){
					break;
				}
			}
			if(m > next_used){
				plug_idx = i;
				next_used = m;
			}
		}
		plug[plug_idx] = x;
	}
	printf("%d", cnt);
	return 0;
}
