section .text
    bits 64
    global asmcompute

asmcompute:

    subsd xmm1, xmm0 ; (vf - vi)
    divsd xmm1, xmm2 ; accel km/h/s
    
    ; Convert km/h/s to m/s^2
    mov rax, 0x408F400000000000    ; 1000.0
    movq xmm3, rax
    mulsd xmm1, xmm3            
    
    mov rax, 0x40AC200000000000 ; 3600.0
    movq xmm3, rax  
    divsd xmm1, xmm3    ; m/s^2

    cvtsd2si eax, xmm1 
    ret
