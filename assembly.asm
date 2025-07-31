section .data
    factor dq 0.277777778

section .text
    bits 64
    default rel
    global asmcompute

asmcompute:
    movq xmm0, rcx        ; vi
    movq xmm1, rdx        ; vf
    movq xmm2, r8         ; t
    movsd xmm3, [factor] 

    ; Convert to m/s
    mulsd xmm0, xmm3
    mulsd xmm1, xmm3

    ; Compute (vf - vi)/t
    subsd xmm1, xmm0
    divsd xmm1, xmm2

    ; return int
    cvttsd2si eax, xmm1
    ret
