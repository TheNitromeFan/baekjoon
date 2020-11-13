#include <cstdio>
#include <deque>
#include <utility>
#define MAX 1000000000

using namespace std;

int main(){
	unsigned n, m;
	scanf("%u %u", &n, &m);
	deque<pair<int, unsigned>> d;
	for(unsigned i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		if(!d.empty() && d.front().second + m <= i){
			d.pop_front();
		}
		while(!d.empty() && d.back().first > x){
			d.pop_back();
		}
		d.push_back(make_pair(x, i));
		printf("%d ", d.front().first);
	}
	return 0;
}
