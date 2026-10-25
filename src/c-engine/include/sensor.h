
#ifndef SENSOR_H
#define SENSOR_H

typedef struct {
    int sensor_id;
    double temperature;
    double pressure;
    double vibration;
} SensorReading;

typedef enum {
    SENSOR_VALID = 0,
    SENSOR_INVALID_ID,
    SENSOR_INVALID_TEMPERATURE,
    SENSOR_INVALID_PRESSURE,
    SENSOR_INVALID_VIBRATION
} SensorStatus;

SensorStatus sensor_validate(const SensorReading *reading);

const char *sensor_status_to_string(SensorStatus status);

#endif
