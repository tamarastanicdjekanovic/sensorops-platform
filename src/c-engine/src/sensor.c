
#include "sensor.h"

#include <math.h>

SensorStatus sensor_validate(const SensorReading *reading)
{
    if (reading == NULL || reading->sensor_id <= 0) {
        return SENSOR_INVALID_ID;
    }

    if (!isfinite(reading->temperature) ||
        reading->temperature < -50.0 ||
        reading->temperature > 150.0) {
        return SENSOR_INVALID_TEMPERATURE;
    }

    if (!isfinite(reading->pressure) ||
        reading->pressure < 0.0 ||
        reading->pressure > 100.0) {
        return SENSOR_INVALID_PRESSURE;
    }

    if (!isfinite(reading->vibration) ||
        reading->vibration < 0.0 ||
        reading->vibration > 50.0) {
        return SENSOR_INVALID_VIBRATION;
    }

    return SENSOR_VALID;
}

const char *sensor_status_to_string(SensorStatus status)
{
    switch (status) {
        case SENSOR_VALID:
            return "VALID";

        case SENSOR_INVALID_ID:
            return "INVALID_SENSOR_ID";

        case SENSOR_INVALID_TEMPERATURE:
            return "INVALID_TEMPERATURE";

        case SENSOR_INVALID_PRESSURE:
            return "INVALID_PRESSURE";

        case SENSOR_INVALID_VIBRATION:
            return "INVALID_VIBRATION";

        default:
            return "UNKNOWN_STATUS";
    }
}
