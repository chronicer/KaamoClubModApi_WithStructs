#pragma once

//#include <ShipItems.h>
#include <Game/Item.h>
#include <abyssengine.h>

struct ShipInfo
{
public:
    int m_nShipId;
    int m_nMaxShipHealth;
    int m_nBasePrice;
    int m_nMaxCapacity;
    int m_nCurrentCapacity;
    int m_nPrice;
    float m_fControlMultiplier;
    int field_1C;
    int m_nArmor;
    int field_24;
    int m_nBonusCapacity;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    float m_fPower; //48
	bool m_bRepairBot;
	bool m_bJumpDrive;
	bool m_bCloak;
	short Race;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int* m_pShipInformation;
    AEArray<Item>* m_pShipEquipment;
    AEArray<Item>* m_pShipItems; //CustomArray<Item>*
};

//VALIDATE_SIZE(ShipInfo, 0x74);