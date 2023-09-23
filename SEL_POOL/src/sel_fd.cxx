#include "sel_fd.h"
#include "sel_pool.h"

using namespace BASE::SEL_POOL;

sel_fd::
sel_fd()
{
}

sel_fd::
~sel_fd()
{
}

 bool
sel_fd::
 sel_says_read()
 {
 	return INFO("HERE");
 }

 bool
sel_fd::
 sel_says_write()
 {
 	return INFO("HERE");
 }

 bool
sel_fd::
 sel_says_except()
 {
 	return INFO("HERE");
 }


 static sel_pool_base sel_pool_global;
// ========================

 sel_pool_base &
 sel_fd::
 get_SEL_POOL()
 {
 	return sel_pool_global;
 }



