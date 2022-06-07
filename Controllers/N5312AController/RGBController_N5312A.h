/*-----------------------------------------*\
|  RGBController_N5312A.h                   |
|                                           |
|  Generic RGB Interface for OpenRGB        |
|  N5312A RGB USB Driver                    |
|                                           |
|  Guimard Morgan (morg) 4/02/2022          |
\*-----------------------------------------*/

#pragma once

#include "RGBController.h"
#include "N5312AController.h"

class RGBController_N5312A : public RGBController
{
public:
    RGBController_N5312A(N5312AController* controller_ptr);
    ~RGBController_N5312A();

    void SetupZones();
    void ResizeZone(int zone, int new_size);
    void DeviceUpdateLEDs();
    void UpdateZoneLEDs(int zone);
    void UpdateSingleLED(int led);
    void DeviceUpdateMode();
    void SetCustomMode();

private:
    N5312AController* controller;
};
