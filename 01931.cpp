#include <cstdio>
#include <algorithm>

struct time{
	int start;
	int end;
};

struct {
	bool operator()(const time &a, const time &b){
		return a.end < b.end || (a.end == b.end && a.start < b.start);
	}
} compare;

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	time conferences[100000];
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &conferences[i].start, &conferences[i].end);
	}
	sort(conferences, conferences+n, compare);
	int current = 0;
	int answer = 0;
	for(int i = 0; i < n; ++i){
		if(current <= conferences[i].start){
			current = conferences[i].end;
			++answer;
		}
	}
	printf("%d", answer);
	return 0;
}
