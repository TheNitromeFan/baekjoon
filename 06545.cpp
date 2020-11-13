#include <cstdio>

int main(){
	while(true){
		double mw, mi, tw, ti;
		scanf("%lf %lf %lf %lf", &mw, &mi, &tw, &ti);
		if(mw == 0 && mi == 0 && tw == 0 && ti == 0){
			break;
		}
		double water = 4.19 * mw * tw;
		double ice = 2.09 * mi * (-ti);
		double water2ice = 335 * mw;
		double ice2water = 335 * mi;
		double t = 0;
		if(water > ice + ice2water){
			t = (water - ice - ice2water) / (4.19 * (mw + mi));
			mw += mi;
			mi = 0;
		}else if(ice > water + water2ice){
			t = -(ice - water - water2ice) / (2.09 * (mw + mi));
			mi += mw;
			mw = 0;
		}else{
			double energy = water - ice;
			mw += energy / 335;
			mi -= energy / 335;
		}
		printf("%.1lf g of ice and %.1lf g of water at %.1lf C\n", mi, mw, t);
	}
	return 0;
}
