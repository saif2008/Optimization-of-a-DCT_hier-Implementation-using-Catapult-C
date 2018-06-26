////////////////////////////////////////////////////////////////////////////////
// Catapult Synthesis
// 
// © 2005 Mentor Graphics Corporation
//       All Rights Reserved
// 
// This document contains information that is proprietary to Mentor Graphics  
// Corporation. The original recipient of this document may duplicate this  
// document in whole or in part for internal business purposes only, provided  
// that this entire notice appears in all copies. In duplicating any part of  
// this document, the recipient agrees to make every reasonable effort to  
// prevent the unauthorized use and distribution of the proprietary information.
////////////////////////////////////////////////////////////////////////////////
// Source:		global_dct.h
// Description:	Design Parameters
////////////////////////////////////////////////////////////////////////////////

#ifndef GLOBALS
#define GLOBALS
#include "ac_int.h"

#define XYSIZE       8
#define COEFFBITS    10

void hier_dct_proc( ac_int<9> input[][XYSIZE], ac_int<11> dct[][XYSIZE]);

#endif

