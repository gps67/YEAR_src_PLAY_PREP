#include "sel_pool.h"
#include "dgb.h"

 using namespace BASE::SEL_POOL;

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
 find_highest_bit( int & hi, fd_set & set )
 {
 	// we have to scan the full rhs
	// and downward loops are fast
 	hi = -1;
	int i = FD_SETSIZE;
	while( i > 0 ) {
		i--;
		if( FD_ISSET( i, & set) )
		{
			hi = i;
			return true;
			break;
		}
	}
	return FAIL("NO BITS SET");
 }

 bool
 sel_pool_base::
 search_highest_bit_sub() {
	 fd_hi_sub = -1;
	 int hi = -1;
	 if(! find_highest_bit( hi, fds_read_sub ) ) return FAIL_FAILED();
	 if( fd_hi_sub < hi ) fd_hi_sub = hi;
	 if(! find_highest_bit( hi, fds_write_sub ) ) return FAIL_FAILED();
	 if( fd_hi_sub < hi ) fd_hi_sub = hi;
	 if(! find_highest_bit( hi, fds_except_sub ) ) return FAIL_FAILED();
	 if( fd_hi_sub < hi ) fd_hi_sub = hi;
	 return true;
 }

 bool
 sel_pool_base::
 call_select() {
 	// copy _sub to _ind
	fds_read_ind   = fds_read_sub;
	fds_write_ind  = fds_write_sub;
	fds_except_ind = fds_except_sub;

	// int fd_hi_sub; // DONE //

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

 static sel_pool_base sel_pool_global;

 sel_pool_base & fd_sel:: get_SEL_POOL()
 {
 	return sel_pool_global;
 }

 // virtual
 fd_sel:: ~fd_sel() {
 }

 fd_sel:: fd_sel() {

 }

