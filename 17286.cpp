#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

double dist(pair<int, int> a, pair<int, int> b){
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main(){
	pair<int, int> cat;
	scanf("%d %d", &cat.first, &cat.second);
	vector<pair<int, int>> people;
	people.resize(3);
	for(int i = 0; i < 3; ++i){
		scanf("%d %d", &people[i].first, &people[i].second);
	}
	sort(people.begin(), people.end());
	double min_dist = 10000;
	do{
		double cmp = dist(cat, people[0]) + dist(people[0], people[1]) + dist(people[1], people[2]);
		if(cmp < min_dist){
			min_dist = cmp;
		}
	}while(next_permutation(people.begin(), people.end()));
	printf("%d", static_cast<int>(min_dist));
	return 0;
}
