#ifndef sel_fd_H
#define sel_fd_H

#include "sel_pool_stubs.h"
#include "obj_ref.h"
#include "fd_hold.h"

namespace BASE {
 namespace SEL_POOL {


	class sel_fd : public fd_hold_1 {
	 public:
	 virtual ~sel_fd();
	 sel_fd();
	 virtual sel_pool_base & get_SEL_POOL();
	 virtual bool sel_says_read(); // ignore bool or log and continue
	 virtual bool sel_says_write(); // 
	 virtual bool sel_says_except(); // 
	}; // class
	

 }; // namespace
}; // namespace

#endif

