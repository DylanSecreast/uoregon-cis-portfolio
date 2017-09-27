#include "Power.h"



int Power::raisingTo(int base, int exponent){
	if (exponent == 0){
		return 1;
	}
	else if (exponent == 1){
		return base;
	}

	if (exponent % 2 == 0){		// if exponent is even
		return raisingTo((base * base), (exponent / 2));
	}
	else{	// if exponent is odd
		return (base * raisingTo((base * base), (exponent / 2)));		
	}
}