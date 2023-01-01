#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "state.h"
#include "pressureSensor.h"
#include "pressureDetection.h"
#include "alarmMonitor.h"

void setup()
{
	pSensor_state = STATE(init);
    pressureDetection_state = STATE(highPressureDetection);
	alarm_state = STATE(alarmOff);
}

int main (){
	GPIO_INITIALIZATION();
	setup();

	while (1)
	{
		pSensor_state();
		alarm_state();
	}

}