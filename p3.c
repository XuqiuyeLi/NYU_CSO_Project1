
#include <math.h>
#include "p3.h"

/*
 * Implementation file for functions
 * declared in p3.h
 *
 * Summer Li
 */ 

const short BIAS = (1 << (NUM_OF_EXP_BITS -1 )) - 1;
const short FRAC_MASK = (1 << NUM_OF_FRAC_BITS) - 1;
const short EXP_MASK = (1 << NUM_OF_EXP_BITS) - 1;

short get_E_from_bits( short bit_vector ) { 
	short e = 0;
	short exp = (bit_vector >> NUM_OF_FRAC_BITS) & EXP_MASK;

    	if(is_normalized(bit_vector)){
    		e = exp - BIAS;
    	}
    	if(is_denormalized(bit_vector)){
    		e = 1- BIAS;
    	}
    	if(exp == 7){
    		short frac = bit_vector & FRAC_MASK;
    		if(frac == 0){
    			// Positive infinity if sign is 0
    			if(get_sign_from_bits(bit_vector)==0)
    				e = INFINITY;
    			// if the sign is 1 then negative infinity
    			else 
    				e = -INFINITY;
		}
    	}
    	// if the frac != 0, then NaN
    	else
    		e = NAN;
    	}

    	return e; 
}

short get_exp_from_bits ( short bit_vector ) { 

	// get the exp parts move to the right and return value
	short exp = (bit_vector >> NUM_OF_FRAC_BITS) & EXP_MASK;  
    	return exp; 
}
    
short is_normalized(short bit_vector ) {
	short exp = (bit_vector>>NUM_OF_FRAC_BITS) & EXP_MASK;
	// if the exp not equal to 000 or 111
	if(exp != 0 && exp != 7 ){
		return 1;
	}
        else return 0; 
}

short is_denormalized(short bit_vector ) {
    	short exp = (bit_vector >> NUM_OF_FRAC_BITS) & EXP_MASK;
    	// if the exp equals to 000
	if(exp == 0){
		return 1;
	}
    	else return 0;
}
        

float get_M_from_bits ( short bit_vector ) {
	// only 00, 01, 10, 11 combinations of frac
    	short frac = bit_vector & FRAC_MASK;
    	float m = 0.0;
    	// I am not sure a good equation to calculate the mantissa...
    	if(is_normalized(bit_vector)){
    		if(frac == 0)
    			m = 1.0;
    		if(frac == 1)
    			m = 1.0 + 1/4;
    		if(frac == 2)
    			m = 1.0 + 1/2;
    		if(frac == 3)
    			m = 1.0 + 1/2 + 1/4;
    	}
    	if(is_denormalized(bit_vector)){
    		if(frac == 0)
    			m = 0.0;
    		if(frac == 1)
    			m = 0.0 + 1/4;
    		if(frac == 2)
    			m = 0.0 + 1/2;
    		if(frac == 3)
    			m = 0.0 + 1/2 + 1/4;
    	}
    	return m; 
}

short get_sign_from_bits (  short bit_vector ) { 
	// get the sign part move to the right and return value  
    	short sign = (bit_vector & 0b00100000 ) >> (NUM_OF_BITS - 1);
    	if (sign >= 0) return 1;
    	else return -1;      
}



float get_value_from_bits ( short bit_vector ) {
	float m = get_M_from_bits(bit_vector);
	short e = get_E_from_bits(bit_vector);
	float value = 0.0;
	if(get_sign_from_bits(bit_vector)==0)
		value = m * (2^e);
	
	else
		value = - m * (2^e);

	return value;
    
}
