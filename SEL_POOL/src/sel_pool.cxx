#include "sel_pool.h"
#include "dgb.h"

 using namespace BASE::SEL_POOL;

 bool
 BASE::SEL_POOL:: /* STUPID C++ needs namespace here, but not for class */
 FIND_highest_bit( int & hi_N, fd_set & set )
 {
 	// we have to scan the full rhs
	// and downward loops are fast
 	hi_N = -1;
	int i = FD_SETSIZE;
	while( i > 0 ) {
		i--;
		if( FD_ISSET( i, & set) )
		{
			hi_N = i;
			return true;
			break;
		}
	}
	return FAIL("NO BITS SET");
 }

 bool
 BASE::SEL_POOL::
 find_next_bit( int & lo, int max, fd_set & set )
 {
 	if( max != FD_SETSIZE ) {
		WARN("expected max %d got %d", FD_SETSIZE, max );
	}
 	// lo was -1 or previous found bit
	// max is N so actually max+1
	for( int i = lo + 1; i < max; i++ ) {
		if( FD_ISSET( i, & set) ) {
			lo = i;
			return true;
		}
	}
	if( !lo ) {
		INFO("was all zero");
	}
//	lo = i; // i not avail // thought it was // some syntax exists
	lo = max;
	lo = -1; // reset for next ?
	INFO("no more bits"); // 
	return false;
 }
// ========================

 fds_holder::
 fds_holder() {
	FD_ZERO( & fds_bits );
	hi_N = -1;
	sweep_pos = -1;
 }

// ========================

 sel_pool_base::
 sel_pool_base() {

	n_fd_ind = 0;
	FD_ZERO( & fds_read_ind );
	FD_ZERO( & fds_write_ind );
	FD_ZERO( & fds_except_ind );

	fd_hi_sub = 0;
	FD_ZERO( & fds_read_sub );
	FD_ZERO( & fds_write_sub );
	FD_ZERO( & fds_except_sub );

 	INFO("CTOR");
 	INFO("FD_SETSIZE = %d", FD_SETSIZE ); // 1024
 }

 sel_pool_base::
 ~sel_pool_base() {
 	INFO("DTOR");
 }

 bool
 sel_pool_base::
 search_highest_bit_sub() {
	 fd_hi_sub = -1;
	 int hi_N = -1;
	 if(! FIND_highest_bit( hi_N, fds_read_sub ) ) return FAIL_FAILED();
	 if( fd_hi_sub < hi_N ) fd_hi_sub = hi_N;
	 if(! FIND_highest_bit( hi_N, fds_write_sub ) ) return FAIL_FAILED();
	 if( fd_hi_sub < hi_N ) fd_hi_sub = hi_N;
	 if(! FIND_highest_bit( hi_N, fds_except_sub ) ) return FAIL_FAILED();
	 if( fd_hi_sub < hi_N ) fd_hi_sub = hi_N;
	 return true;
 }

 bool
 sel_pool_base::
 call_select() {
 	// copy _sub to _ind
	fds_read_ind   = fds_read_sub;
	fds_write_ind  = fds_write_sub;
	fds_except_ind = fds_except_sub;

 	if(!  search_highest_bit_sub() ) {
		return FAIL("( fd_hi_sub < 0 ) in all 3");
	}

	// int fd_hi_sub; // DONE //
	if( fd_hi_sub < 0 ) {
		return FAIL("( fd_hi_sub < 0 )");
	}

	int n_fd_ind = select(
		fd_hi_sub,
		& fds_read_ind,
		& fds_write_ind,
                & fds_except_ind,
		NULL // no timeout // struct timeval *timeout
	);
	if( n_fd_ind == -1 ) {
		// see errno
		// *_ind are unchanged // 
		if( errno == EINTR ) {
			INFO("EINTR");
		}
		FAIL("selected returned -1 - poss retry");
		return false;
	}
	return true;
 }
// ========================
