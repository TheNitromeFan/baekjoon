#include <iostream>
#include <algorithm>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	int cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if(cmp > 0){
		return 1;
	}else if(cmp < 0){
		return -1;
	}else{
		return 0;
	}
}

int intersect_1d(int a, int b, int c, int d){
	if(a > b){
		swap(a, b);
	}
	if(c > d){
		swap(c, d);
	}
	if(b < c || d < a){
		return 0;
	}else if(b == c || d == a){
		return 1;
	}else{
		return 2;
	}
}

int intersect(int xmin, int ymin, int xmax, int ymax, int x1, int y1, int x2, int y2){
	int cmp1 = ccw(xmin, ymin, xmin, ymax, x1, y1);
	int cmp2 = ccw(xmin, ymin, xmin, ymax, x2, y2);
	int cmp3 = ccw(xmin, ymax, xmax, ymax, x1, y1);
	int cmp4 = ccw(xmin, ymax, xmax, ymax, x2, y2);
	int cmp5 = ccw(xmax, ymax, xmax, ymin, x1, y1);
	int cmp6 = ccw(xmax, ymax, xmax, ymin, x2, y2);
	int cmp7 = ccw(xmax, ymin, xmin, ymin, x1, y1);
	int cmp8 = ccw(xmax, ymin, xmin, ymin, x2, y2);
	int cmp9 = ccw(x1, y1, x2, y2, xmin, ymin);
	int cmp10 = ccw(x1, y1, x2, y2, xmin, ymax);
	int cmp11 = ccw(x1, y1, x2, y2, xmax, ymax);
	int cmp12 = ccw(x1, y1, x2, y2, xmax, ymin);
	if((cmp1 == 0 && cmp2 == 0) || (cmp5 == 0 && cmp6 == 0)){
		int tmp = intersect_1d(ymin, ymax, y1, y2);
		if(tmp == 2){
			return 4;
		}else if(tmp == 1){
			return 1;
		}else{
			return 0;
		}
	}else if((cmp3 == 0 && cmp4 == 0) || (cmp7 == 0 && cmp8 == 0)){
		int tmp = intersect_1d(xmin, xmax, x1, x2);
		if(tmp == 2){
			return 4;
		}else if(tmp == 1){
			return 1;
		}else{
			return 0;
		}
	}else if(cmp1 * cmp2 <= 0 && cmp9 * cmp10 <= 0 && cmp5 * cmp6 <= 0 && cmp11 * cmp12 <= 0){
		return 2;
	}else if(cmp3 * cmp4 <= 0 && cmp10 * cmp11 <= 0 && cmp7 * cmp8 <= 0 && cmp12 * cmp9 <= 0){
		return 2;
	}else if(cmp1 * cmp2 <= 0 && cmp9 * cmp10 <= 0 && cmp3 * cmp4 <= 0 && cmp10 * cmp11 <= 0){
		if(cmp10 == 0){
			return 1;
		}else{
			return 2;
		}
	}else if(cmp3 * cmp4 <= 0 && cmp10 * cmp11 <= 0 && cmp5 * cmp6 <= 0 && cmp11 * cmp12 <= 0){
		if(cmp11 == 0){
			return 1;
		}else{
			return 2;
		}
	}else if(cmp5 * cmp6 <= 0 && cmp11 * cmp12 <= 0 && cmp7 * cmp8 <= 0 && cmp12 * cmp9 <= 0){
		if(cmp12 == 0){
			return 1;
		}else{
			return 2;
		}
	}else if(cmp7 * cmp8 <= 0 && cmp12 * cmp9 <= 0 && cmp1 * cmp2 <= 0 && cmp9 * cmp10 <= 0){
		if(cmp9 == 0){
			return 1;
		}else{
			return 2;
		}
	}else if(cmp1 * cmp2 <= 0 && cmp9 * cmp10 <= 0){
		return 1;
	}else if(cmp3 * cmp4 <= 0 && cmp10 * cmp11 <= 0){
		return 1;
	}else if(cmp5 * cmp6 <= 0 && cmp11 * cmp12 <= 0){
		return 1;
	}else if(cmp7 * cmp8 <= 0 && cmp12 * cmp9 <= 0){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int xmin, ymin, xmax, ymax, x1, y1, x2, y2;
		cin >> xmin >> ymin >> xmax >> ymax >> x1 >> y1 >> x2 >> y2;
		cout << intersect(xmin, ymin, xmax, ymax, x1, y1, x2, y2) << '\n';
	}
	return 0;
}
