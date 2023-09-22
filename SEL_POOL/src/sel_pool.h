#ifndef sel_pool_H
#define sel_pool_H

#include "sel_pool_stubs.h"

#include "obj_ref.h"
#include "dgb.h"
#include "fd_hold.h"
// #include "fd_selectable.h" // this replaces that // for now

#include <sys/select.h>


// select is more POSIX but is limited to N_fd < FD_SETSIZE // 1024


namespace BASE {
 namespace SEL_POOL {

 	enum SEL_R_W_X {
		SEL_R = 1,	// READ
		SEL_W = 2,	// WRITE
		SEL_X = 4,	// exception (not exe)
		SEL_RWX = 7 	// all set
	};

 	class sel_pool_base { // not a ref counted object - no dgb extras ?
	 
	 int n_fd_ind; // total count of bits indicated not hi pos
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

	 static
	 bool find_highest_bit( int & hi, fd_set & set );

	 bool search_highest_bit_sub(); // sets fd_hi_sub

	public:
 	 sel_pool_base();
	 virtual
 	 ~sel_pool_base();
	}; // class


//	class fd_sel : public obj_ref {}
	class fd_sel : public fd_hold_1 {
	 public:
	 virtual ~fd_sel();
	 fd_sel();
	 virtual sel_pool_base & get_SEL_POOL();
	}; // class

 }; // namespace
}; // namespace

#endif
