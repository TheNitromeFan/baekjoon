#include <cstdio>
#include <cstdlib>
#include <algorithm>

struct ball{
	int color;
	int size;
	int index;
};

struct {
	bool operator()(const ball &a, const ball &b){
		return a.size < b.size;
	}
} compare;

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	ball *balls = (ball *)malloc(n * sizeof(ball));
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &balls[i].color, &balls[i].size);
		balls[i].index = i;
	}
	sort(balls, balls+n, compare);
	int running_sum = 0;
	int color_sum[200001] = {}, score[200000] = {};
	int j = 0;
	for(int i = 0; i < n; ++i){
		while(balls[j].size < balls[i].size){
			running_sum += balls[j].size;
			color_sum[balls[j].color] += balls[j].size;
			++j;
		}
		score[balls[i].index] = running_sum - color_sum[balls[i].color];
	}
	for(int i = 0; i < n; ++i){
		printf("%d\n", score[i]);
	}
	free(balls);
	return 0;
}
