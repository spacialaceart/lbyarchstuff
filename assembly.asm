section .data
    factor dq 0.277777778

section .text
    bits 64
    global asmcompute

asmcompute:

    movsd xmm3, [factor] 

    ; Convert to m/s
    mulsd xmm0, xmm3
    mulsd xmm1, xmm3

    ; Compute (vf - vi)/t
    subsd xmm1, xmm0
    divsd xmm1, xmm2

    ; Convert result to integer and return
    cvttsd2si eax, xmm1
    ret
