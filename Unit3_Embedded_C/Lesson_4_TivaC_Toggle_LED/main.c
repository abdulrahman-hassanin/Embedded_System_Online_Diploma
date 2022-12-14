/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdulrahman Hassanin
 * @brief          : Toggle Led on TivaC
 ******************************************************************************
 */

#define SYSCTL_RCGC3_R      (*((volatile unsigned long*) 0x400FE108))
#define GPIP_PORTF_DIR_R    (*((volatile unsigned long*) 0x40025400))
#define GPIP_PORTF_DEN_R    (*((volatile unsigned long*) 0x4002551C))
#define GPIP_PORTF_DATA_R   (*((volatile unsigned long*) 0x400253FC))

int main()
{
    volatile unsigned long delay_count;
    SYSCTL_RCGC3_R = 0x20;
    // delay to make sure GIPIO is up and running
    for(delay_count=0; delay_count<200; delay_count++)  ;

    GPIP_PORTF_DIR_R |= 1<<3;       // Dir is ouput for pin3 port F
    GPIP_PORTF_DEN_R |= 1<<3;

    while(1)
    {
        GPIP_PORTF_DATA_R |= 1<<3;
        for(delay_count=0; delay_count<200000; delay_count++)  ;
        GPIP_PORTF_DATA_R &= ~(1<<3);
        for(delay_count=0; delay_count<200000; delay_count++)  ;
    }

    return 0;
}