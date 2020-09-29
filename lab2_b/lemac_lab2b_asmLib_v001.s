.include "xc.inc"
.text		    ;BP (put the following data in ROM(program memory))
; This is a library, thus it can *not* contain a _main function: the C file will
; deine main(). However, we
; we will need a .global statement to make available ASM functions to C code.
; All functions utilized outside of this file will need to have a leading
; underscore (_) and be included in a comment delimited list below.
.global _write_0, _write_1, _lem_wait_100us, _lem_wait_1ms
    
 _write_0:            ;;2 calling
    bset LATA, #0    ; Start the write cycle; Bit set in Ws  ;1 cycle
    repeat #3        ;1 cycle to load and prep
    nop              ;3+1=4 cycles to execute
    clr LATA       ;BCLR LATA, #0     ;1 cycle
    repeat #8       ;1 cycle to load and prep
    nop               ;8+1=9 cycles to execute
    return	     ;3 cycles for the retur
    
    ;22 cycles

 _write_1:                ;;2 calling
    bset LATA, #0        ; Start the write cycle; Bit set in Ws;1 cycle
    repeat #8		 ;1 cycle to load and prep
    nop			 ;8+1=9 cycles to execute 
    clr LATA        ; Start the write cycle; Bit set in Ws;1 cycle
    repeat #3        ;1 cycle to load and prep
    nop                  ;1+3=4
    return		;3 cycles for the retur
    
   ;22 cycles

 _lem_wait_100us:   ;2 calling
    repeat #1593    ;1 cycle to load and prep
    nop             ;1593+1 cycles to execute
    return          ;3 cycles for the return
 ;1600 cycles
 _lem_wait_1ms:      ;;2 calling
    repeat #15993    ;1 cycle to load and prep
    nop            ;15995+1 cycles to execute 
    return         ;3 cycles for the return
  ;16000 cycles 
    .end




