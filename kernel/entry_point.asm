[bits 32]
[extern main] ; define the calling point

call main ; calls the C function (we finally don't need to touch assembly)
jmp $