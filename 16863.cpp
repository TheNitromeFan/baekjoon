#include <cstdio>
#include <vector>
#include <tuple>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<tuple<char, int, int>> v(n);
	for(int i = 0; i < n; ++i){
		char c;
		int p, h, m;
		scanf(" %c %d %d:%d", &c, &p, &h, &m);
		v[i] = make_tuple(c, p, 60 * h + m);
	}
	v.push_back(make_tuple('H', 0, 60 * 32));
	int score = 0;
	int time = 0;
	int lead_home = 0, lead_away = 0;
	for(tuple<char, int, int> tup : v){
		int p = get<1>(tup);
		int t = get<2>(tup);
		if(score > 0){
			lead_home += t - time;
		}else if(score < 0){
			lead_away += t - time;
		}
		if(get<0>(tup) == 'A'){
			p *= -1;
		}
		score += p;
		time = t;
	}
	printf("%c %d:%02d %d:%02d", (score > 0 ? 'H' : 'A'), lead_home / 60, lead_home % 60, lead_away / 60, lead_away % 60);
	return 0;
}
