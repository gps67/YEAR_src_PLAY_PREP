#!/usr/bin/env python3

import eyed3

# AST FSM TEMPLATE VARNAME = VAR_NAME_X PLUS 'DATA_filename'
# BECOMES (STR0) DATA_filename
# BECOMES (STR_as_STREAM_XPOS_P0P2 DATA_filename
#  PSG adds KNOW convert from C_str to STR0_str
#  PSG adds KNOW how to APPLY (above)
#  PSG can use INTO_FILTER and FROM_FILTER amd FILTER_WHEN
#  FILTER_WHEN is a requirement to know XPOS of LEX_IDENT as-P0P2_in_STR
# P0P2_in_STR #
# P0P2_in_STREAM # eg IDENT_as_XPOS_in_STREAM_and_know_BVYTES # 0 -1 PLUS_MINUS
# P0P2_in_STR0 # TUPLE { STR0 OFFS_ } # PICK OFFS_
# LEX_ trailing_ may mean and MATCH DIAKECT USAGE "{ OFFS_%s }"
# TROUBLE finding CIDENT that means something, use a SAMPLE VALUE # SPELLING
# OPTION flag SPELLING as consistently exact SPELLING
# OPTION flag SPELLING adds parsed ALIAS SPELLING
# OPTION flag SPELLING adds parsed similar SPELLING
# OPTION flag SPELLING adds ANYSTR # use of same spelling is same OBJ_ID
# EVAL SPELLING # EA_EXPR obj_id # RET_VAL = "SIMPLE"
# EVAL SPELLING # EA_EXPR obj_id # RET_VAL = "COMPLEX"
# EVAL SPELLING # EA_EXPR obj_id # RET_VAL = "EXACT"
# EVAL SPELLING # EA_EXPR obj_id # RET_VAL = "GUESSED"
# EVAL SPELLING # EA_EXPR obj_id # RET_VAL = "DECODE" SO_FAR += LIST_of_FOUND
# EVAL LIST_of_FOUND to make a DECISION or RHYME_or_REASON SIMILAR_RHYME
# EVAL_DECISION( DATA KNOW_about_DATA _EXPECTED _FOUND )
# CALLER has to provide some CODE that INTELI_CHOICE each ATTR it wishes to BE
# CALLER CACHE HOLD IS # LIBR_OBJ_API # each var picks a C++ class possible _FF
# NAMESPACE keeps restarting _FF as _01 or _02 # M3 M2 M1 Z0 X1 X2
# MINUS_ZERO_PLUS # long name for a project suite
# MINUS_ZERO_PLUS # M_z_N # L_R # P0P2 # PTR_N # RESERVE AVOID { int N_bytes }
# MINUS_ZERO_PLUS # ZOOM_USED # i7 i15 
# define  i7_REALLY u8 _getting_zero_fill_if_minus _from_ASM
# i64_WORD_from_i7_in
# MASK_for_i7
# TEST_bit_7 # CPU has BITFIELD_from_OPCODE_and_DATA_WORD # LONG_from_BYTE
# TEST_bit_6 # CPU has test bit but not BITFIELD_from_OPCODE_and_DATA_WORD
# TEST_bit_5 # CPU has test bit but not BITFIELD_from_OPCODE_and_DATA_WORD
# TEST_bit_4 # CPU has test bit but not BITFIELD_from_OPCODE_and_DATA_WORD
# TEST_bit_3 # CPU has test bit but not BITFIELD_from_OPCODE_and_DATA_WORD
# TEST_bit_2 # CPU has test bit but not BITFIELD_from_OPCODE_and_DATA_WORD
# TEST_bit_1 # CPU has test bit but not BITFIELD_from_OPCODE_and_DATA_WORD
# TEST_bit_0 # CPU has test bit but not BITFIELD_from_OPCODE_and_DATA_WORD
# PICK for u1 to u8 #
# PICK OPTS to u16
# PICK OPTS to u32
# PICK OPTS to u63 # we must break this with a LIMIT u63 fits in i64 asif i64
# PICK OPTS to %s plus one one BIT # we have special CODE for BIT_ONE_DATA_ZERO
# BIT_DATA _ONE_ZERO
# solve that and you LOSE is_MINUS vary_fast_test available to us
# MINUS_ZERO_PLUS # uses i16 to hold u8 and i9 # actually expect i5 u4_PICK
# ALLOC # allocate 32 for i5 # ALLOC 16 for u4
# define  i7_REALLY u8 _needing zero fill if minus
# define  i7_REALLY i8
# define  i7_REALLY i7
# define _i7 i7_REALLY

# NEAR_CLASS requires BASE_CLASS_API EG_MATCH_EXACT # EG ALIAS # EG DECODE #
# OFFS_%s }
# convert from C_str to STR0_str

D='/home/gps/audio/mp3_V4/mr_mister/broken_wings/'
FILENAME=D + '01_broken_wings.mp3'

print( FILENAME )

pathname_mp3 = FILENAME

mp3file = eyed3.load( FILENAME )
if mp3file.tag is None:
	print("GOT tag None")
	mp3file.tag = eyed3.id3.Tag() # set to something

if 1:
	tag = mp3file.tag

	print( "artist", tag.artist )
	print( "album", tag.album )
	print( "title", tag.title )
	print( "track", tag.track ) # NO SUCH FIELD ' TODO # RTFM # SLEEP #



# str = $format(title:,bold=y) %title%\n

# eyeD3 FILE_MP3

# ----------------------------------------------------------------------------
# Time: 05:36   MPEG1, Layer III        [ ~154 kb/s @ 44100 Hz - Joint stereo ]
# ----------------------------------------------------------------------------
# ID3 v2.4:
# title: Broken Wings
# artist: Mr, Mister
# album: Broken Wings
# album artist: Mr, Mister
# recording date: 1999
# track: 1                genre: Retro (id 76)
# Comment: [Description: ] [Lang: eng]
# 
