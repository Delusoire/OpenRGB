#include "Detector.h"
#include "SteelSeriesRivalController.h"
#include "SteelSeriesRival3Controller.h"
#include "SteelSeriesSiberiaController.h"
#include "SteelSeriesQCKMatController.h"
#include "SteelSeriesApexController.h"
#include "SteelSeriesApexTZoneController.h"
#include "SteelSeriesOldApexController.h"
#include "SteelSeriesApexMController.h"
#include "SteelSeriesSenseiController.h"
#include "SteelSeriesGeneric.h"
#include "RGBController.h"
#include "RGBController_SteelSeriesRival.h"
#include "RGBController_SteelSeriesRival3.h"
#include "RGBController_SteelSeriesSiberia.h"
#include "RGBController_SteelSeriesQCKMat.h"
#include "RGBController_SteelSeriesApex.h"
#include "RGBController_SteelSeriesApexTZone.h"
#include "RGBController_SteelSeriesOldApex.h"
#include "RGBController_SteelSeriesSensei.h"
#include <hidapi/hidapi.h>

/*-----------------------------------------------------*\
| Vendor ID                                             |
\*-----------------------------------------------------*/
#define STEELSERIES_VID                             0x1038
/*-----------------------------------------------------*\
| Mouse product IDs                                     |
\*-----------------------------------------------------*/
#define STEELSERIES_RIVAL_100_PID                   0x1702
#define STEELSERIES_RIVAL_100_DOTA_PID              0x170c
#define STEELSERIES_RIVAL_105_PID                   0x1814
#define STEELSERIES_RIVAL_110_PID                   0x1729
#define STEELSERIES_RIVAL_300_PID                   0x1710
#define ACER_PREDATOR_RIVAL_300_PID                 0x1714
#define STEELSERIES_RIVAL_300_CSGO_PID              0x1394
#define STEELSERIES_RIVAL_300_CSGO_STM32_PID        0x1716
#define STEELSERIES_RIVAL_300_CSGO_HYPERBEAST_PID   0x171a
#define STEELSERIES_RIVAL_300_DOTA_PID              0x1392
#define STEELSERIES_RIVAL_300_HP_PID                0x1718
#define STEELSERIES_RIVAL_300_BLACKOPS_PID          0x1710
#define STEELSERIES_RIVAL_310_PID                   0x1720
#define STEELSERIES_RIVAL_310_CSGO_HOWL_PID         0x171e
#define STEELSERIES_RIVAL_310_PUBG_PID              0x1736
#define STEELSERIES_RIVAL_600_PID                   0x1724
#define STEELSERIES_RIVAL_600_DOTA_2_PID            0x172E
#define STEELSERIES_RIVAL_650_PID                   0x172B
#define STEELSERIES_RIVAL_650_WIRELESS_PID          0x1726
#define STEELSERIES_RIVAL_700_PID                   0x1700
#define STEELSERIES_RIVAL_710_PID                   0x1730
#define STEELSERIES_RIVAL_3_OLD_PID                 0x1824
#define STEELSERIES_RIVAL_3_PID                     0x184C
#define STEELSERIES_SENSEI_TEN_PID                  0x1832
#define STEELSERIES_SENSEI_TEN_CSGO_NEON_RIDER_PID  0x1834
#define STEELSERIES_SENSEI_310_PID                  0x1722
/*-----------------------------------------------------*\
| Headset product IDs                                   |
\*-----------------------------------------------------*/
#define STEELSERIES_SIBERIA_350_PID                 0x1229
/*-----------------------------------------------------*\
| Mousemat product IDs                                  |
\*-----------------------------------------------------*/
#define STEELSERIES_QCK_PRISM_CLOTH_MED_PID         0x150A
#define STEELSERIES_QCK_PRISM_CLOTH_XL_PID          0x150D
#define STEELSERIES_QCK_PRISM_CLOTH_3XL_PID         0x1516
#define STEELSERIES_QCK_PRISM_CLOTH_4XL_PID         0x1518
/*-----------------------------------------------------*\
| Keyboard product IDs                                  |
\*-----------------------------------------------------*/
#define STEELSERIES_APEX_3_PID                      0x161A
#define STEELSERIES_APEX_5_PID                      0x161C
#define STEELSERIES_APEX_7_PID                      0x1612
#define STEELSERIES_APEX_7_TKL_PID                  0x1618
#define STEELSERIES_APEX_PRO_PID                    0x1610
#define STEELSERIES_APEX_PRO_TKL_PID                0x1614
#define STEELSERIES_APEX_M750_PID                   0x0616
#define STEELSERIES_APEX_OG_PID                     0x1202
#define STEELSERIES_APEX_350_PID                    0x1206

void DetectSteelSeriesApexTZone(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesApexTZoneController* controller = new SteelSeriesApexTZoneController(dev, APEX_TZONE, info->path);
        RGBController_SteelSeriesApexTZone* rgb_controller = new RGBController_SteelSeriesApexTZone(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesApex(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesApexController* controller = new SteelSeriesApexController(dev, APEX, info->path);
        RGBController_SteelSeriesApex* rgb_controller = new RGBController_SteelSeriesApex(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesApexTKL(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesApexController* controller = new SteelSeriesApexController(dev, APEX_TKL, info->path);
        RGBController_SteelSeriesApex* rgb_controller = new RGBController_SteelSeriesApex(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesApexM(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesApexMController* controller = new SteelSeriesApexMController(dev, APEX_M, info->path);
        RGBController_SteelSeriesApex* rgb_controller = new RGBController_SteelSeriesApex(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesApexOld(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesOldApexController* controller = new SteelSeriesOldApexController(dev, APEX_OLD, info->path);
        RGBController_SteelSeriesOldApex* rgb_controller = new RGBController_SteelSeriesOldApex(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesHeadset(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesSiberiaController* controller = new SteelSeriesSiberiaController(dev, info->path);
        RGBController_SteelSeriesSiberia* rgb_controller = new RGBController_SteelSeriesSiberia(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesMousemat(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesQCKMatController* controller = new SteelSeriesQCKMatController(dev, info->path);
        RGBController_SteelSeriesQCKMat* rgb_controller = new RGBController_SteelSeriesQCKMat(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesRival100(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesRivalController* controller = new SteelSeriesRivalController(dev, RIVAL_100, info->path);
        RGBController_SteelSeriesRival* rgb_controller = new RGBController_SteelSeriesRival(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesRival300(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesRivalController* controller = new SteelSeriesRivalController(dev, RIVAL_300, info->path);
        RGBController_SteelSeriesRival* rgb_controller = new RGBController_SteelSeriesRival(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesRival600(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesRivalController* controller = new SteelSeriesRivalController(dev, RIVAL_600, info->path);
        RGBController_SteelSeriesRival* rgb_controller = new RGBController_SteelSeriesRival(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}


void DetectSteelSeriesRival650(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesRivalController* controller = new SteelSeriesRivalController(dev, RIVAL_650, info->path);
        RGBController_SteelSeriesRival* rgb_controller = new RGBController_SteelSeriesRival(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesRival700(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesRivalController* controller = new SteelSeriesRivalController(dev, RIVAL_700, info->path);
        RGBController_SteelSeriesRival* rgb_controller = new RGBController_SteelSeriesRival(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}


void DetectSteelSeriesRival3(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesRival3Controller* controller = new SteelSeriesRival3Controller(dev, RIVAL_3, info->path);
        RGBController_SteelSeriesRival3* rgb_controller = new RGBController_SteelSeriesRival3(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

void DetectSteelSeriesSensei(hid_device_info* info, const std::string& name)
{
    hid_device* dev = hid_open_path(info->path);
    if(dev)
    {
        SteelSeriesSenseiController* controller = new SteelSeriesSenseiController(dev, SENSEI, info->path);
        RGBController_SteelSeriesSensei* rgb_controller = new RGBController_SteelSeriesSensei(controller);
        rgb_controller->name = name;
        ResourceManager::get()->RegisterRGBController(rgb_controller);
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*\
| Mice                                                                                                                                                                  |
\*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
REGISTER_HID_DETECTOR_I("SteelSeries Rival 100",                            DetectSteelSeriesRival100,  STEELSERIES_VID, STEELSERIES_RIVAL_100_PID,                 0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 100 DotA 2 Edition",             DetectSteelSeriesRival100,  STEELSERIES_VID, STEELSERIES_RIVAL_100_DOTA_PID,            0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 105",                            DetectSteelSeriesRival100,  STEELSERIES_VID, STEELSERIES_RIVAL_105_PID,                 0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 110",                            DetectSteelSeriesRival100,  STEELSERIES_VID, STEELSERIES_RIVAL_110_PID,                 0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 300",                            DetectSteelSeriesRival300,  STEELSERIES_VID, STEELSERIES_RIVAL_300_PID,                 0  );
REGISTER_HID_DETECTOR_I("Acer Predator Gaming Mouse (Rival 300)",           DetectSteelSeriesRival300,  STEELSERIES_VID, ACER_PREDATOR_RIVAL_300_PID,               0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 300 CS:GO Fade Edition",         DetectSteelSeriesRival300,  STEELSERIES_VID, STEELSERIES_RIVAL_300_CSGO_PID,            0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 300 CS:GO Fade Edition (stm32)", DetectSteelSeriesRival300,  STEELSERIES_VID, STEELSERIES_RIVAL_300_CSGO_STM32_PID,      0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 300 CS:GO Hyperbeast Edition",   DetectSteelSeriesRival300,  STEELSERIES_VID, STEELSERIES_RIVAL_300_CSGO_HYPERBEAST_PID, 0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 300 Dota 2 Edition",             DetectSteelSeriesRival300,  STEELSERIES_VID, STEELSERIES_RIVAL_300_DOTA_PID,            0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 300 HP Omen Edition",            DetectSteelSeriesRival300,  STEELSERIES_VID, STEELSERIES_RIVAL_300_HP_PID,              0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 300 Black Ops Edition",          DetectSteelSeriesRival300,  STEELSERIES_VID, STEELSERIES_RIVAL_300_BLACKOPS_PID,        0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 310",                            DetectSteelSeriesSensei,    STEELSERIES_VID, STEELSERIES_RIVAL_310_PID,                 0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 310 CS:GO Howl Edition",         DetectSteelSeriesSensei,    STEELSERIES_VID, STEELSERIES_RIVAL_310_CSGO_HOWL_PID,       0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 310 PUBG Edition",               DetectSteelSeriesSensei,    STEELSERIES_VID, STEELSERIES_RIVAL_310_PUBG_PID,            0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 600",                            DetectSteelSeriesRival600,  STEELSERIES_VID, STEELSERIES_RIVAL_600_PID,                 0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 600 Dota 2 Edition",             DetectSteelSeriesRival600,  STEELSERIES_VID, STEELSERIES_RIVAL_600_DOTA_2_PID,          0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 650",                            DetectSteelSeriesRival650,  STEELSERIES_VID, STEELSERIES_RIVAL_650_PID,                 0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 650 Wireless",                   DetectSteelSeriesRival650,  STEELSERIES_VID, STEELSERIES_RIVAL_650_WIRELESS_PID,        0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 700",                            DetectSteelSeriesRival700,  STEELSERIES_VID, STEELSERIES_RIVAL_700_PID,                 0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 710",                            DetectSteelSeriesRival700,  STEELSERIES_VID, STEELSERIES_RIVAL_710_PID,                 0  );
REGISTER_HID_DETECTOR_I("SteelSeries Rival 3 (Old Firmware)",               DetectSteelSeriesRival3,    STEELSERIES_VID, STEELSERIES_RIVAL_3_OLD_PID,                   3);
REGISTER_HID_DETECTOR_I("SteelSeries Rival 3",                              DetectSteelSeriesRival3,    STEELSERIES_VID, STEELSERIES_RIVAL_3_PID,                   3);
REGISTER_HID_DETECTOR_I("SteelSeries Sensei TEN",                           DetectSteelSeriesSensei,    STEELSERIES_VID, STEELSERIES_SENSEI_TEN_PID,                0  );
REGISTER_HID_DETECTOR_I("SteelSeries Sensei TEN CS:GO Neon Rider Edition",  DetectSteelSeriesSensei,    STEELSERIES_VID, STEELSERIES_SENSEI_TEN_CSGO_NEON_RIDER_PID,0  );
REGISTER_HID_DETECTOR_I("SteelSeries Sensei 310",                           DetectSteelSeriesSensei,    STEELSERIES_VID, STEELSERIES_SENSEI_310_PID,                0  );
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*\
| Headsets                                                                                                                                                              |
\*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
REGISTER_HID_DETECTOR_I("SteelSeries Siberia 350",                          DetectSteelSeriesHeadset,   STEELSERIES_VID, STEELSERIES_SIBERIA_350_PID,               3  );
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*\
| Mousemats                                                                                                                                                             |
\*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
REGISTER_HID_DETECTOR_I("SteelSeries QCK Prism Cloth Medium",                DetectSteelSeriesMousemat,  STEELSERIES_VID, STEELSERIES_QCK_PRISM_CLOTH_MED_PID,      0  );
REGISTER_HID_DETECTOR_I("SteelSeries QCK Prism Cloth XL",                    DetectSteelSeriesMousemat,  STEELSERIES_VID, STEELSERIES_QCK_PRISM_CLOTH_XL_PID,       0  );
REGISTER_HID_DETECTOR_I("SteelSeries QCK Prism Cloth 3XL",                   DetectSteelSeriesMousemat,  STEELSERIES_VID, STEELSERIES_QCK_PRISM_CLOTH_3XL_PID,      0  );
REGISTER_HID_DETECTOR_I("SteelSeries QCK Prism Cloth 4XL",                   DetectSteelSeriesMousemat,  STEELSERIES_VID, STEELSERIES_QCK_PRISM_CLOTH_4XL_PID,      0  );
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*\
| Keyboards                                                                                                                                                             |
\*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
REGISTER_HID_DETECTOR_I("SteelSeries Apex 3",                               DetectSteelSeriesApexTZone, STEELSERIES_VID, STEELSERIES_APEX_3_PID,                    3  );
REGISTER_HID_DETECTOR_I("SteelSeries Apex 5",                               DetectSteelSeriesApex,      STEELSERIES_VID, STEELSERIES_APEX_5_PID,                    1  );
REGISTER_HID_DETECTOR_I("SteelSeries Apex 7",                               DetectSteelSeriesApex,      STEELSERIES_VID, STEELSERIES_APEX_7_PID,                    1  );
REGISTER_HID_DETECTOR_I("SteelSeries Apex 7 TKL",                           DetectSteelSeriesApexTKL,   STEELSERIES_VID, STEELSERIES_APEX_7_TKL_PID,                1  );
REGISTER_HID_DETECTOR_I("SteelSeries Apex Pro",                             DetectSteelSeriesApex,      STEELSERIES_VID, STEELSERIES_APEX_PRO_PID,                  1  );
REGISTER_HID_DETECTOR_I("SteelSeries Apex Pro TKL",                         DetectSteelSeriesApexTKL,   STEELSERIES_VID, STEELSERIES_APEX_PRO_TKL_PID,              1  );
REGISTER_HID_DETECTOR_I("SteelSeries Apex M750",                            DetectSteelSeriesApexM,     STEELSERIES_VID, STEELSERIES_APEX_M750_PID,                 2  );
REGISTER_HID_DETECTOR_I("SteelSeries Apex (OG)/Apex Fnatic",                DetectSteelSeriesApexOld,   STEELSERIES_VID, STEELSERIES_APEX_OG_PID,                   0  );
REGISTER_HID_DETECTOR_I("SteelSeries Apex 350",                             DetectSteelSeriesApexOld,   STEELSERIES_VID, STEELSERIES_APEX_350_PID,                  0  );
