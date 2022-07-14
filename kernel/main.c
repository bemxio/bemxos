#include "../drivers/screen.h"
#include "../cpu/isr.h"

void main() {
    isr_install();
    irq_install();

    kclear();
    
    kprintln("\nbemxOS v0.1.0 (very early beta tester alpha verison!!!)");
    kprintln("for now, this is only a text editor with no option to save lmao");
    kprintln("but still, hope you have fun :3\n");

    init_keyboard();
}