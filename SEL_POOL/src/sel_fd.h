#ifndef sel_fd_H
#define sel_fd_H

#if 0
	COMMENT

	This is a rework of fd_selectable for select_says 
	That was glib based, which is good
	We also need the event loop from Tcl Python EV Node
	lib_event Apache LIBC_SELECT POLL_ETC

	To make it easy to stitch this back, it is based on fd_hold
	That does almost nothing other than call close when refcount zero
	That makes THIS sel_fd_one the BASE_CLASS of fd

	We are avoiding all MEANINGS from libs_apps, for ZERO use of VOCAB
	We are invoking the EXISTING basic storage items
	We are subclassing the EVENT_LOOP_ITEMS for behaviour

#endif

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

