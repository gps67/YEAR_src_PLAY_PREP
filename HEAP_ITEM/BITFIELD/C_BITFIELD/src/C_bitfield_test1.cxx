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


struct C_BITFIELD_test_1_t {

	int one:8;		// LO BYTE on AMD64
	int two:24;		// HI 24_bits

	bool set_one( int _one ) {
		one = _one;
		return true;
	}

	bool set_two( int _two ) {
		two = _two;
		return true;
	}

	bool get_one( int & _one ) {
		_one = one;
		return true;
	}

	bool get_two( int & _two ) {
		_two = two;
		return true;
	}


};

	#if 1
	bool get_word( C_BITFIELD_test_1_t * test_1 , int & word ) {

		word = *(int *)test_1;
		return true;
	}
	#endif


bool bool_main( int argc, char ** argv ) {
  
	C_BITFIELD_test_1_t test_1 ;
	test_1.set_one( 99 );
	test_1.set_two( -1 );
	int v1, v2,word ;
	word = -2;
	test_1.get_one( v1 );
	test_1.get_two( v2 );
	get_word( & test_1, word );
	INFO("v1 = %X  V2 = %X word = %X", v1, v2, word );


	return PASS("SO FAR SO GOOD");
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


