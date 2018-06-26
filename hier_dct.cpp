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
//  Source:         hier_dct.cpp
//  Description:    DCT transform from JPEG example.
////////////////////////////////////////////////////////////////////////////////

#include "global_dct.h"

const ac_int<10> coeff[XYSIZE][XYSIZE] = {
    362,  362,  362,  362,  362,  362,  362,  362,
    502,  425,  284,   99,  -99, -284, -425, -502,
    473,  195, -195, -473, -473, -195,  195,  473,
    425,  -99, -502, -284,  284,  502,   99, -425,
    362, -362, -362,  362,  362, -362, -362,  362,
    284, -502,   99,  425, -425,  -99,  502, -284,
    195, -473,  473, -195, -195,  473, -473,  195,
     99, -284,  425, -502,  502, -425,  284,  -99
  };

#pragma hls_design  
void matmult1 ( ac_int<9> input[][XYSIZE], ac_int<21> temp[][XYSIZE] ) {
   ac_int<21> tmp;
   ac_int<31> dct_value;
   
   mult1:for (int i=0; i < XYSIZE; ++i ) 
     middle1:for (int j=0; j < XYSIZE; ++j ) {
       tmp = 0;
       inner1:for (int k=0; k < XYSIZE; ++k ) 
	     tmp = tmp + input[i][k] * coeff[j][k];
       temp[j][i] = tmp;
     }
}  

#pragma hls_design
void matmult2 ( ac_int<21> temp[][XYSIZE], ac_int<11> dct[][XYSIZE] ) {
  ac_int<21> tmp;
  ac_int<31> dct_value;   
  
  mult2:for (int ii=0 ; ii < XYSIZE; ++ii ) 
     middle2:for (int j=0; j < XYSIZE; ++j ) {
       dct_value = 0;
       inner2:for (int k=0 ; k < XYSIZE ; ++k )  
	     dct_value = dct_value + coeff[ii][k] * temp[j][k];
 	   dct[ii][j] = dct_value >> 20;
     }  
}

#pragma design top
void hier_dct_proc(ac_int<9> input[XYSIZE][XYSIZE], ac_int<11> dct[XYSIZE][XYSIZE]) {

  ac_int<21> temp[XYSIZE][XYSIZE];

  
  matmult1( input, temp);
  matmult2(temp, dct);

}
