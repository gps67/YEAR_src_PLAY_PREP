#ifndef sel_pool_H
#define sel_pool_H

#include "sel_pool_stubs.h"

#include "obj_ref.h"
#include "dgb.h"
#include "fd_hold.h"
// #include "fd_selectable.h" // this replaces that // for now

#include <sys/select.h>

#include "sel_fd.h"

#define M1 -1

// select is more POSIX but is limited to N_fd < FD_SETSIZE // 1024


namespace BASE {
 namespace SEL_POOL {

	 bool FIND_highest_bit( int & hi_N, fd_set & set );
	 bool find_next_bit( int & lo, int max, fd_set & set );

	struct fds_holder { // %s_fd VAR_NAME // %d_fd OBJ_ID 
		// ALIAS += OBJ_ID "{ int idx = N ++ }" //
		// DECODE MINUS ZERO PLUS // OPTION ZERO_is_PLUS
		// DECODE PLUS array[idx] ; int idx
		// DECODE PLUS array[idx] ; PLUS idx BLOCK_of_VARS[PLUS] //
		// ZERO_is_PLUS // rewrite SILENT PARAMETER VARIABLE CALCS
		// on_ZERO on_PLUS on_MINUS on_SWEEP_END // complete archive
		// SIGNED M1 M128
		// DECODE MINUS idx OBJ_ID
		// DECODE MINUS idx OBJ_ID_i32_is_plenty on ARM32
		// fds = "{ MINUS ZERO PLUS }" //
		// API = "{ MINUS ZERO PLUS }" //
		// API += "{ MINUS ZERO_PLUS }" // DIALECT PAIR_in_ONE //
		// LEX += LEXICON finds all CIDENT and DOCS and SPEC and API
		// NAME += VAR_NAME holds "{ VAR_DATA VAR_SPEC VAR_NAME }"
		// when in doublt "{ do this }"
		// SUBLEX looks over LEXICON for SUBLEX SUBSEP SUBLEX 
		// PSG LEX // FUTUISTIC SELF PREDICT VAR_NAME SPEC_NAME MK_NOD
		// PSG VALUE = LEX
		// PSG LEX = VALUE = LEX // in situ //
		// FTP CTRL DATA
		// 
		int hi_N; // ALIAS N // ALIAS P2 // P0 N // UDEF i64_EIGHT
		// if hi_N < 0 goto is_MINUS or on_minus // 
		int sweep_pos; // pos_in_sweep _t

		const static int N_max = FD_SETSIZE;
		// POSIX demands ARRAY [ 1024 ] of STR0
		//               ARRAY   1024   of STR0
		// POSIX demands ARRAY [ 1024 ] of STR0 "IDX_%d" // CAST %d idx
		// MINI_CPU OBJ_ID idx = "{ STREAM }" // "{ CONNECT }" //
		// sweep_bit_range_u10 as ASCII VIA VIEW
		// process that channels incoming events
		// schedule that channels action events
		fd_set fds_bits; // _sub or _ind

		/*
			 EDIT CSR is here
			 REDO-ing

			 if reset bit is hi_N search for new hi_N or set M1
			 if set bit > hi_N set hi_N

			 sweep is ongoing process

			unfortunately select() does not return n per fds
			it adds the 3 n's
		*/

		fds_holder();

		bool find_highest_bit() {
	 		return FIND_highest_bit( hi_N, fds_bits );
		}

		bool sweep_init() {
			if( ! hi_N ) {
				// N is hi_N + 1
				hi_N = find_highest_bit() + 1; // hi_N
			}
			sweep_pos = M1;
			return true;
		}
		bool sweep_next() {
			return  sweep_next(sweep_pos);
		}
		bool sweep_next(int & sweep_pos) {
			// BEFORE: sweep_pos 0
			// BEFORE: sweep_pos is unread 
			// so read before increment
			// BEFORE: sweep_pos 99
			// BEFORE: sweep_pos is read
			// so increment before read // and limit test too
			// ans start from M1
			sweep_pos ++;
			for( sweep_pos ; sweep_pos < hi_N; sweep_pos++ ) {
				if( FD_ISSET( sweep_pos, & fds_bits) ) {
				//	sweep_pos = sweep_pos; // WRITE_BACK() 
					return true;
				}
				// else step to next
			}
		//	sweep_pos = sweep_pos; // WRITE_BACK() 
			return false;
		}

		bool sweep_all() {
			bool done_something_useful;
			if(!sweep_init()) return FAIL_FAILED();
			if( sweep_next()) {
				done_something_useful = true;
			}


			if( done_something_useful )
				return true; // OK

			WARN("sweep found nothing");
			return true;
		}

	};

 	enum SEL_R_W_X {
		SEL_R = 1,	// READ
		SEL_W = 2,	// WRITE
		SEL_X = 4,	// exception (not exe)
		SEL_RWX = 7 	// all set
	};

 	class sel_pool_base { // not a ref counted object - no dgb extras ?
	 
	 int n_fd_ind; // total count of bits indicated not hi_N sweep_pos
	 fd_set fds_read_ind; // indicated as 
	 fd_set fds_write_ind; // indicated as 
	 fd_set fds_except_ind; // indicated as 

	 int fd_hi_sub;
	 fd_set fds_read_sub; // subscribed
	 fd_set fds_write_sub; // subscribed
	 fd_set fds_except_sub; // subscribed

 // TODO // 
	 struct timeval *timeout;

	 bool call_select();

	 bool search_highest_bit_sub(); // sets fd_hi_sub

	public:
 	 sel_pool_base();
	 virtual
 	 ~sel_pool_base();
	}; // class


 }; // namespace
}; // namespace

#endif
