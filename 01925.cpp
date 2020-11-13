#include <iostream>
#include <algorithm>

using namespace std;

struct point{
	int x;
	int y;
} p[3];

int main(){
	for(int i = 0; i < 3; ++i){
		cin >> p[i].x >> p[i].y;
	}
	if((p[2].x - p[1].x) * (p[1].y - p[0].y) == (p[2].y - p[1].y) * (p[1].x - p[0].x)){
		cout << 'X';
		return 0;
	}
	int sides_squared[3];
	sides_squared[0] = (p[1].x - p[0].x) * (p[1].x - p[0].x) + (p[1].y - p[0].y) * (p[1].y - p[0].y);
	sides_squared[1] = (p[2].x - p[1].x) * (p[2].x - p[1].x) + (p[2].y - p[1].y) * (p[2].y - p[1].y);
	sides_squared[2] = (p[0].x - p[2].x) * (p[0].x - p[2].x) + (p[0].y - p[2].y) * (p[0].y - p[2].y);
	sort(sides_squared, sides_squared + 3);
	if(sides_squared[0] == sides_squared[1] && sides_squared[1] == sides_squared[2]){
		cout << "JungTriangle";
	}else if(sides_squared[1] == sides_squared[2]){
		cout << "Yeahkak2Triangle";
	}else if(sides_squared[0] == sides_squared[1]){
		if(sides_squared[0] + sides_squared[1] < sides_squared[2]){
			cout << "Dunkak2Triangle";
		}else if(sides_squared[0] + sides_squared[1] == sides_squared[2]){
			cout << "Jikkak2Triangle";
		}else{
			cout << "Yeahkak2Triangle";
		}
	}else if(sides_squared[0] + sides_squared[1] < sides_squared[2]){
		cout << "DunkakTriangle";
	}else if(sides_squared[0] + sides_squared[1] == sides_squared[2]){
		cout << "JikkakTriangle";
	}else{
		cout << "YeahkakTriangle";
	}
	return 0;
}
