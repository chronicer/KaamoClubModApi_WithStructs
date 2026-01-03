#pragma once

struct ShipItems
{
    int m_nPrimary;
    int m_nSecondary;
    int m_nTurret;
    int m_nEquipment;
};

VALIDATE_SIZE(ShipItems, 0x10);