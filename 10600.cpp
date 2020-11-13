#include <cstdio>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int dist(int r1, int g1, int b1, int r2, int g2, int b2){
	return (r1 - r2) * (r1 - r2) + (g1 - g2) * (g1 - g2) + (b1 - b2) * (b1 - b2);
}

int main(){
	vector<tuple<string, int, int, int>> colors;
	colors.push_back(make_tuple("White", 255, 255, 255));
	colors.push_back(make_tuple("Silver", 192, 192, 192));
	colors.push_back(make_tuple("Gray", 128, 128, 128));
	colors.push_back(make_tuple("Black", 0, 0, 0));
	colors.push_back(make_tuple("Red", 255, 0, 0));
	colors.push_back(make_tuple("Maroon", 128, 0, 0));
	colors.push_back(make_tuple("Yellow", 255, 255, 0));
	colors.push_back(make_tuple("Olive", 128, 128, 0));
	colors.push_back(make_tuple("Lime", 0, 255, 0));
	colors.push_back(make_tuple("Green", 0, 128, 0));
	colors.push_back(make_tuple("Aqua", 0, 255, 255));
	colors.push_back(make_tuple("Teal", 0, 128, 128));
	colors.push_back(make_tuple("Blue", 0, 0, 255));
	colors.push_back(make_tuple("Navy", 0, 0, 128));
	colors.push_back(make_tuple("Fuchsia", 255, 0, 255));
	colors.push_back(make_tuple("Purple", 128, 0, 128));
	while(true){
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		if(r == -1 && g == -1 && b == -1){
			break;
		}
		unsigned idx = 0;
		for(unsigned i = 1; i < colors.size(); ++i){
			if(dist(r, g, b, get<1>(colors[idx]), get<2>(colors[idx]), get<3>(colors[idx]))
			> dist(r, g, b, get<1>(colors[i]), get<2>(colors[i]), get<3>(colors[i]))){
				idx = i;
			}
		}
		printf("%s\n", get<0>(colors[idx]).c_str());
	}
	return 0;
}
