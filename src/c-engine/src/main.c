
#include <stdio.h>
#include "sensor.h"

int main(void)
{
    SensorReading reading = {
        .sensor_id = 1,
        .temperature = 36.5,
        .pressure = 4.2,
        .vibration = 1.8
    };

    SensorStatus status = sensor_validate(&reading);

    printf("=== SensorOps Engine ===\n");
    printf("Sensor ID: %d\n", reading.sensor_id);
    printf("Temperature: %.2f C\n", reading.temperature);
    printf("Pressure: %.2f bar\n", reading.pressure);
    printf("Vibration: %.2f mm/s\n", reading.vibration);

    printf("Validation: %s\n",
           sensor_status_to_string(status));

    return status == SENSOR_VALID ? 0 : 1;
}
