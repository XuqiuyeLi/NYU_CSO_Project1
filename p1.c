
#include "p1.h"

/*
 * Implementation file for functions
 * declared in p1.h
 * 
 * Summer Li 
 * Check if the triangle is valid
 */ 


int is_valid_triangle ( int n ) {

	// Assume that taken Integer n is 32 bits
	unsigned a = n &  0x000003FF; 
    	unsigned b = (n & 0x000ffc00) >>10;
    	unsigned c = (n & 0x3ff00000) >>20; 


    	// The triangle is valid if the sum of two sides bigger than the largest side
    	if (a>=b && a>=c && a < (b+c)){
    		return 1;
    	} 
    	if (b>=a && b>=c && b < (a+c)){
    		return 1;
   	}
    	if (c>=a && c>=b && c < (a+b)){
    		return 1;
    	}

   	else 
   		return 0;

}
