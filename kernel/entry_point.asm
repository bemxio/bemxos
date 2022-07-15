[bits 32]
[extern kernel_main] ; define the calling point

call kernel_main ; calls the C function (we finally don't need to touch assembly)
jmp $