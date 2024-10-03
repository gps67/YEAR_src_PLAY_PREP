#ifndef STRAY_LOCK_H
#define STRAY_LOCK_H
// raw typed in # uncompiled

/*
	test_and_set BIT 31 of LOCK_WORD

		if it was already SET
		some other thread had the LOCK

		so delay and retry or join a queue or ...

		if it was ZERO, we have just SET it
		so we exec our multi step locked action
		we remember to unset it, on end_LOCK_SCOPE // NOW

		This gives us the extra ability to then do something else,
		such as queueing a request, with final nudge, SESS end scope

		SESS.queue_request_on_lock_word_bit_31_and_stle

	CPU atomic actions
	wrapped in POSIX atomic ints

		there are other ATOMIC multi_byte 
		but probably FOUR_BYTE_WORD_LOHI

		we are demanding LOHI for real reasons
	
	RTFM

	https://stackoverflow.com/questions/44691392/atomic-operations-c

	https://gcc.gnu.org/onlinedocs/gcc-4.4.5/gcc/Atomic-Builtins.html
	https://gcc.gnu.org/onlinedocs/gcc-14.2.0/gcc/_005f_005fatomic-Builtins.html

	__atomic
	load
	store
	exchange
	compare_exchange

*/


// LOCK_t is to ACCESS a RESOURCE


	 // I think this LOCK might be MAD
	 // or it might simply need relocating and rephrasing IDK
	 // I think the WORD would have to be in memory, as part of a STRUCT
	 // and the FSM_springs_to_life on NREXT USE
	 // 
	 // typedef i64 WORD_t; // as good as ALIAS for C base class CTOR_fn
	 // struct LOCK_t {
	 //  WORD_t LOCK_WORD; // SINGLE USE RD RW // BRIEF USE // test_and_set
	 // LOCK += _one
	 //  EIGHT_t WORD_one;
	 // LOCK += _two
	 //  EIGHT_t WORD_two
	 //
	 // RESOURCE

// as found

	 bool OBTAIN_LOCK( WORD_t & WORD ) { // WORD 
	  // HMM what is LOCK_t //
	  // cunch of CODE that needs a DATA_WORD as the lock
	  // CT_RT a value to use, or INCR or DECR or BIT_0 or SIGN_BIT
	  // GLOBAL CODE LOCK
	  	LOCK_t LOCK( WORD );
		LOCK.use_CPU_test_and_set_MEM_lock(); // ALLOC the BIT
		if( LOCK.LOCK_OBTAINED() ) { // else was busy
			LOCK.sync_WORD(); // NOOP // already DONE // KNOW ...
			LOCK.register_LOCK_with_LOCK_BOX(); //
			LOCK.STO_WORD_and_DTOR(); // already DONE // SYNC
			return true; // LOCK obtained
		}
		} else {
			return FAIL_FAILED(); // already reported
		}
	  // GLOBAL_UN_LOCK
	 }

	 bool RELEASE_LOCK( WORD_t & WORD ) { // WORD 
	  	LOCK_t LOCK( WORD );
		LOCK.RELEASE(); // SAME_ALLOC_BIT CT_RT CODE_POINT KNOWN BIT
		return true;
	 };
 };



#endif

