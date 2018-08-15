
#include "MK22F51212.h"
#include <stdbool.h>

static int i = 0;

int main(void)
{
       // Enable the clock for the port control module
       SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;
       // Enable the clock for the port control module
       SIM_SCGC5 |= 0x3e00;

       // Initialise all LEDs
       PORTA->PCR[1] = 0x100; // Select GPIO mode
       PORTA->PCR[2] = 0x100; // Select GPIO mode
       PORTD->PCR[5] = 0x100; // Select GPIO mode

       // Data Directions set
       GPIOA_PDDR = (1 << 1) | (1 << 2);
       GPIOD_PDDR = (1 << 5);

       // Flash the LED
       int counter;
       for (;;) {
              //RED
              GPIOA_PDOR = 0;
              GPIOD_PDOR = 0;
              GPIOA_PTOR = (1 << 2);
              GPIOD_PTOR = (1 << 5);
              for (counter = 0; counter < 1000000; counter++) {
                     // waste time by using the "no-operation" assembly code instruction
                     __asm volatile ("nop");
              }
              //GREEN
              GPIOA_PDOR = 0;
              GPIOD_PDOR = 0;
              GPIOA_PTOR = (1 << 1);
              GPIOD_PTOR = (1 << 5);
              for (counter = 0; counter < 1000000; counter++) {
                     // waste time by using the "no-operation" assembly code instruction
                     __asm volatile ("nop");
              }
              //BLUE
              GPIOA_PDOR = 0;
              GPIOD_PDOR = 0;
              GPIOA_PTOR = (1 << 1);
              GPIOA_PTOR = (1 << 2);
              for (counter = 0; counter < 1000000; counter++) {
                     // waste time by using the "no-operation" assembly code instruction
                     __asm volatile ("nop");
              }
              //YELLOW
              GPIOA_PDOR = 0;
              GPIOD_PDOR = 0;
              GPIOD_PTOR = (1 << 5);
              for (counter = 0; counter < 1000000; counter++) {
                     // waste time by using the "no-operation" assembly code instruction
                     __asm volatile ("nop");
              }
              //PURPLE
              GPIOA_PDOR = 0;
              GPIOD_PDOR = 0;
              GPIOA_PTOR = (1 << 2);
              for (counter = 0; counter < 1000000; counter++) {
                     // waste time by using the "no-operation" assembly code instruction
                     __asm volatile ("nop");
              }
              //CYAN
              GPIOA_PDOR = 0;
              GPIOD_PDOR = 0;
              GPIOA_PTOR = (1 << 1);
              for (counter = 0; counter < 1000000; counter++) {
                     // waste time by using the "no-operation" assembly code instruction
                     __asm volatile ("nop");
              }
              // WHITE
              GPIOA_PDOR = 0;
              GPIOD_PDOR = 0;
              for (counter = 0; counter < 1000000; counter++) {
                     // waste time by using the "no-operation" assembly code instruction
                     __asm volatile ("nop");
              }




       }
    return 0;
}

/*

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
*/
