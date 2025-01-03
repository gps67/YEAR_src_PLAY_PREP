#include "dgb.h"
#include <linux/unistd.h>

// <string.h>
extern "C"
	void *memset(void *s, int c, size_t n);


extern "C" bool bool_main( int argc, char ** argv );

# include <asm/ldt.h>
 extern "C"      int get_thread_area(struct user_desc *u_info);
 extern "C"      int set_thread_area(struct user_desc *u_info);

#include <unistd.h>
#include <sys/syscall.h>     /* Definition of SYS_* constants */


struct user_desc_MGR {

	user_desc _user_desc;

	void memset_ZERO() {
	//	INFO("memset ZERO");
		memset( & _user_desc, 0x0, sizeof( _user_desc ));
		_user_desc.entry_number = -1;
	}

	user_desc_MGR() { // CTOR 
		memset_ZERO();
	};

	~user_desc_MGR() { // CTOR 
		memset_ZERO();
	};

	void print_entry_number() {
		INFO("user_desc.entry_number == %d", _user_desc.entry_number );
	}

	bool SET_thread_area() {
		print_entry_number();
	// int t =  set_thread_area( &_user_desc);

	//	int t = syscall(SYS_get_thread_area, struct user_desc *u_info);
		int t = syscall(SYS_set_thread_area, & _user_desc);
		if( t == -1 ) { return FAIL("SYSCALL %m"); } // didnt print ERRNO
		print_entry_number();
		return true;

// # UNIX errno(err 38) == ENOSYS - Function not implemented ## 


	}

};
	user_desc_MGR
	 global_user_desc;

bool bool_main( int argc, char ** argv ) {

	global_user_desc.SET_thread_area();

	return FAIL("UNDONE");
	return WARN("UNDONE");
}


// RTFM man get_thread_area, set_thread_area 
// - manipulate thread-local storage in‐


#if 0
           struct user_desc {
               unsigned int  entry_number;
               unsigned int  base_addr;
               unsigned int  limit;
               unsigned int  seg_32bit:1;
               unsigned int  contents:2;
               unsigned int  read_exec_only:1;
               unsigned int  limit_in_pages:1;
               unsigned int  seg_not_present:1;
               unsigned int  useable:1;
           #ifdef __x86_64__
               unsigned int  lm:1;
           #endif
           };
#endif


