#ifndef STO_ARRAY_u8_of_EIGHT_H
#define STO_ARRAY_u8_of_EIGHT_H

#include "ints.h"
#include "dgb.h"
#include "dgb_fail.h"

extern bool bool_main_test1( int argc, char ** argv ); // forward decl

namespace STO {

	/*
		STO ARRAY_u8_of_EIGHT .h

		STO is itself GROW_able

		It uses HEAPS of size u7_u15_u31_u63 INT_PLUS
		It uses HEAPS of size i8_i16_i32_i64 INT_MINUS
		It uses HEAPS of size i4_i12_i24_i48 INT_BITFIELDS //
		// _PLUS_or_MINUS

		STO uses L_M_z_N_R 	// A_LOT :-)
		STO uses HEAP_ITEM SPEC_INST CALL_SPEC as API
		STO uses HEAP LISTS TABLES HASH INDEX_IDX INDEX_STR
		HEAP uses ... i8_i8 i4_i12 i8_i24
		HEAP uses ...

			i32_i32		i32_i32_WORD_PAIR

			i8_i8		OPCODE
			i4_i12		i4_HEAP i12_ITEM
			i8_i24		i8_HEAP i24_ITEM
		
			There are only a few MAIN tables,
			CODE_POINT of DECL
			which fits in easily with i4_i12
			Alloc an item whenever you need one,
			and the total is in the hundreds,
			just outside BYTE, but below 4K
			(and expandable to u128 but mostly u64 or u32)

			i128
			-GROW-STEP-
			u64
			i64
			u63
			-GROW-STEP-
				i48
			-GROW-STEP-
			u32
			i32
			u31
			-GROW-STEP-
				i24
			-GROW-STEP-
			u16
			i16
			u15
			-GROW-STEP-
				i12
			-GROW-STEP-
			u8
			i8
			u7



		TEMPLATE for MULT_1248

		TODO: M_z_N for L_R as P0P2 as V0V2


	*/

// CPU32
// CPU64

// typedef u32 WORD_t; // CPU specific
   typedef u64 WORD_t; // MEM align EIGHT_t or FOUR_t // u32_u32 //
  
// GROW // u7_u15_u23_u31 _u63
// GROW // i8_i16_i24_i32 _i64
// GROW // u8_u16_u24_u32 _u64
// GROW // i4_i12 // u3 u11 // i4_MINUS
// GROW // i8_i24 // u7 u23 // i8_MINUS

// L_R //
// M_N //
// _Z_ // 
// ALLOC_MINUS
// ALLOC_PLUS

	// u9 N; //
   typedef u16 u9; 	// is_wider // BEWARE when N needs 17'th bit
   typedef u9  u9_or_i10_or_wider; //
   typedef u9 u8_then_1; // u9 or i10 or wider
   typedef u8 i8_then_u8; // u9 or i10 or wider needed for N_FULL // 256-1
   typedef u8 u8_idx_t; // LIBR can force outer N_PAGES_of_256 PAGE_of_256


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

	// u9_N_t // 255 + 1 //
	u8_then_1 N;

	u8_idx_t
	 u8_idx; // = 0 ; // P0P2 rules // N == 0 // future _idx is old N

	 // every ARRAY has a single builtin TEMP CSR // obtain LOCK get CSR
	 // u8_idx is that CSR

	 ARRAY_u8_of_EIGHT();

	EIGHT_t & operator[]( size_t idx );
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
