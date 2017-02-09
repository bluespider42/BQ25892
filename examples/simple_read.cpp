//#include "mbed.h"
#include "BQ25892.h"

Serial serial1(PA18, PA19);
//BQ25892 bq(PA08, PA09);
BQ25892 bq(PB16, PB17);
DigitalOut led(LED1);

int main() {
    // Setup
    serial1.baud(115200);
    wait(1);
    led = 0;

    serial1.printf("\nHello World!\n");
    bool rst = bq.reset();

    wait(2);
    if(rst) {
        serial1.printf("Device Reset\n");
        led = 1;
    }

    serial1.printf("Part Number: %s\n", bq.pn);
    serial1.printf("Revision Number: %i\n", bq.rev);

    char cmd[1];
    char data;

    cmd[0] = 0x00;
    int IinLim = 50;
    char AcLim;

    // Loop
    while (1) {

        bq.setIinLim(IinLim);
        wait(1);
        AcLim = bq.checkBit(IINLIM_REG, IINLIM_BIT);

        serial1.printf("Input Current Limit %i -> %imA\n", IinLim, AcLim*50+100);

        wait(2);
        IinLim += 10;

        if(IinLim > 3250){
            IinLim = 90;
        }

        // data = bq.ReadByte(cmd[0]);
        //
        // serial1.printf("Reg:%02X  - Data: %02X \n", cmd[0], data);
        // wait(10);
        // cmd[0] = cmd[0] + 0x01;
        // if(cmd[0] == 0x15){
        //     cmd[0] = 0x00;
        //     bq.powerOff();
        // }

    }

    // End
    return 0;
}
