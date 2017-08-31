#ifndef BATTERY_GAUGE_BQ35100_H
#define BATTERY_GAUGE_BQ35100_H

#include <Wire.h>
#include <stdint.h>
#include "BQ35100_registers.h"

/**
 * BQ35100 battery status.
 */
typedef struct {
    bool isDischargeDetected;
    bool isAlertActive;
} battery_status_t;

/**
 * BQ35100 battery alert status enumeration
 */
enum battery_alert_t {
    BQ35100_BATLOW = 0,
    BQ35100_TEMPLOW,
    BQ35100_TEMPHIGH,
    BQ35100_SOH_LOW,
    BQ35100_EOS,
    BQ35100_G_DONE,
    BQ35100_INITCOMP
};

/**
 * BQ35100 class for measuring battery
 */
class BQ35100 {
public:
    BQ35100();
    ~BQ35100();

    bool begin(uint8_t address = 0x55);
    uint16_t readVoltage();
    battery_status_t readBatteryStatus();
    int16_t readCurrent();
private:
    uint8_t i2cAddress;
};

#endif