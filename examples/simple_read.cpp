//#include "mbed.h"
#include "BQ25892.h"

Serial serial1(PA18, PA19);
BQ25892 bq(PA08, PA09);
DigitalOut led(LED1);

int main() {
    // Setup
    serial1.baud(115200);
    wait(1);

    serial1.printf("Hello World!\n");
    // Loop
    while (1) {

        serial1.printf("Part Number: %s\n", bq.pn[8]);
        serial1.printf("Revision Number: %c\n", bq.rev);
        serial1.printf("pnc: %c\n", bq.pnc);

        //bq.ChgEnable();
        led = 1;

        wait(20);

        //bq.ChgDisable();
        led = 0;

        wait(20);

    }

    // End
    return 0;
}
