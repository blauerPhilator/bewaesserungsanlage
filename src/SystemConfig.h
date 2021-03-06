#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include "classes/Soil.h"
#include "classes/Valve.h"
#include "classes/WateringPlan.h"

#define WIFI_SSID "Fritz!Box 7530 SI"
#define WIFI_PSK "48106592558002630888"

#define HTTP_USERNAME "admin"
#define HTTP_PASSWORD "yourpassword"

#define HARDWARE_VERSION_2_0
#include "hal.h"

#define SOIL_COUNT 1
Soil soils[SOIL_COUNT] = {
    Soil(SENSOR_1_PIN, "Basilikum", 3472, 1610),
};

#define VALVE_COUNT 1
Valve valves[VALVE_COUNT] = {
    Valve(OUTPUT_1_PIN, HIGH, "Basilikum"),
};

#define H_TO_MS_FACTOR 1000 * 60 * 60
#define WATERING_DEAD_TIME_MS H_TO_MS_FACTOR * 6 // Stunden

#define WATERINGPLAN_COUNT 1
WateringPlan wateringPlans[WATERINGPLAN_COUNT] = {
    WateringPlan(&soils[0], &valves[0], 40, 20000, WATERING_DEAD_TIME_MS),
};
#endif