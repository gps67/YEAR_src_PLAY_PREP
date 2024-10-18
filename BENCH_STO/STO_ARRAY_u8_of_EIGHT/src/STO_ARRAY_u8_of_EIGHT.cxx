
	#include "STO_ARRAY_u8_of_EIGHT.h"

//	#include "dgb.h"


 typedef STO::EIGHT_t EIGHT_t; // sort of single IDENT import

 extern
	bool bool_main_test1( int argc, char ** argv ) { // envp

		STO::ARRAY_u8_of_ITEM * PAGE = new STO::ARRAY_u8_of_ITEM();

	// AVAR // CONST_AVAR // need PERMIT to modify
	// AVAR // CONST_AVAR // need PROFILE to modify and save

		EIGHT_t _one; // 1	// ie support one_is_1
		EIGHT_t _two; // 0	// ie support large model "_two"
		EIGHT_t _M1; // -1	// M1 is -1
		EIGHT_t _M2; // -2	// M2 is -2

		// [M4 [M3 [M2 [M1 [Z0 [1  [2  [3  [0
		// [M4 [M3 [M2 [M1 [Z0 [1  [2  [3  -- // N_lim
		// [i3 [M3 [i2 [M1 [Z0 [1  [i2 [3  -- [4==u2==i3_NEXT==i3_N
		// i3_IDX; [M4[00 [00[u2 // i3_to_u2 // u2_from_i3

		delete PAGE;
		return FAIL("TODO");

	}

// ==== // END_PRE_START // START_MAIN //

 namespace STO {

	// SPEED says INLINE - particularly when it ASM_GETTER
	// FLEXI says CALLED - linker gets here, poss via VTBL
	//
	EIGHT_t & ARRAY_u8_of_EIGHT :: operator[]( size_t idx ) {
		return * ARRAY[idx];
	}

	ARRAY_u8_of_EIGHT:: ARRAY_u8_of_EIGHT() : N(0) {
	// ARRAY_u8_of_EIGHT() : N(0), ARRAY(NULL) 
	 	ARRAY = (PAGE_u8_of_EIGHT_t *) MMAP_alloc( sizeof(*ARRAY) ); // I always MEMSET_ZERO
		// sometime I HOPE ZERO and attempt to avoid DOUBLE_MEMSET //
		// the debugged version is MEMSET_ZERO // GUARANTEED //
	//	if(!ARRAY) return FAIL_FAILED(); // use NULL properly 
	//	if(!ARRAY) return FAIL_throw(); // retain NULL properly 
	//	if(!ARRAY)        FAIL_throw(); // retain NULL properly 
	//	if(!ARRAY) throw THROW_dgb_fail("NULL from MALLOC"); // GEN this as default
		if(!ARRAY)       THROW_dgb_fail("NULL from MALLOC"); // GEN this as default
		// errno and errm is already correctly pre_set
		// we just need to walk back the THROW or FAIL up the stack
		 u8_idx = 0 ;
	 }
 }; // STO
