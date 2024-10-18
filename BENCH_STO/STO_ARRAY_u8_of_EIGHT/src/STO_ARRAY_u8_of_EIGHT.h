#ifndef STO_ARRAY_u8_of_EIGHT_H
#define STO_ARRAY_u8_of_EIGHT_H

#include "ints.h"
#include "dgb.h"
#include "dgb_fail.h"

extern bool bool_main_test1( int argc, char ** argv ); // forward decl

namespace STO {

	/*
		STO ARRAY_u8_of_EIGHT .h

		TEMPLATE for MULT_1248
	*/

// CPU32
// CPU64

// typedef u32 WORD_t; // CPU specific
   typedef u64 WORD_t; // MEM align EIGHT_t or FOUR_t // u32_u32 //


 struct LOCK_t {
 //	u64 LOCK_WORD; // on AMD
 //	u32 LOCK_WORD; // on AMD
	WORD_t LOCK_WORD;
 };

#define MMAP_alloc(n) malloc(n) // size_t n //

typedef i64 EIGHT_t; // compules to a single word on AMD64 // edit for CT_ARCH
typedef	EIGHT_t   PAGE_u8_of_EIGHT_t[ 256 ];	// ONE_PAGE 

 struct ARRAY_u8_of_EIGHT {

 	// introducing a new namespace //
	// local_dialect { HERE } // FILTER ARGV DIAG 

	// FULL PAGE or PARTIAL PAGE

	PAGE_u8_of_EIGHT_t * ARRAY;

	// u9 N; //
	typedef u16 u9; 	// is_wider // BEWARE when N needs 17'th bit
	typedef u9  u9_or_i10_or_wider; //
	typedef u9 u8_then_1; // u9 or i10 or wider
	typedef u8 i8_then_u8; // u9 or i10 or wider needed for N_FULL // 256-1
	typedef u8 u8_idx_t; // LIBR can force outer N_PAGES_of_256 PAGE_of_256
	// u9_N_t // 255 + 1 //
	u8_then_1 N;

	u8_idx_t
	 u8_idx; // = 0 ; // P0P2 rules // N == 0 // future _idx is old N

	 // every ARRAY has a single builtin TEMP CSR // obtain LOCK get CSR
	 // u8_idx is that CSR

	 ARRAY_u8_of_EIGHT() : N(0) {
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
  };

 struct ARRAY_u8_of_ITEM : public ARRAY_u8_of_EIGHT {
	// we have only implemented EIGHT
	// because it is useful as u32_u32 or as UDEF_UDEF
	// even in ARM32 
	// even in AMD64 // u32_u32 // adjust HILO for access to WORD_UPPER
	// mode asif MEM // ASIF CPU_WORD // ASIF choice LIST_of_CHOICE // 
	// WEIGHTED PICK_WEIGHTED //
 };

 struct x_ARRAY_u8_of_ITEM {
 };


};
#endif
