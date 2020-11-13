#include <cstdio>

using namespace std;

struct point{
	int x;
	int y;
} p[100000];

bool is_linear(int x1, int y1, int x2, int y2, int x3, int y3){
	return (long long)(y2 - y1) * (x3 - x2) == (long long)(y3 - y2) * (x2 - x1);
}

int main(){
	int n;
	scanf("%d", &n);
	if(n <= 4){
		printf("success");
		return 0;
	}
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	int i1 = 0, i2 = 0, i3 = 0;
	bool one_line_found = false;
	for(i1 = 0; i1 < 5; ++i1){
		for(i2 = i1+1; i2 < 5; ++i2){
			for(i3 = i2+1; i3 < 5; ++i3){
				if(is_linear(p[i1].x, p[i1].y, p[i2].x, p[i2].y, p[i3].x, p[i3].y)){
					one_line_found = true;
					break;
				}
			}
			if(one_line_found){
				break;
			}
		}
		if(one_line_found){
			break;
		}
	}
	if(!one_line_found){
		printf("failure");
		return 0;
	}
	int i4, i5;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(is_linear(p[i1].x, p[i1].y, p[i2].x, p[i2].y, p[i].x, p[i].y)){
			continue;
		}else if(cnt == 0){
			i4 = i;
			++cnt;
			continue;
		}else if(cnt == 1){
			i5 = i;
			++cnt;
			continue;
		}else if(!is_linear(p[i4].x, p[i4].y, p[i5].x, p[i5].y, p[i].x, p[i].y)){
			printf("failure");
			return 0;
		}
	}
	printf("success");
	return 0;
}
