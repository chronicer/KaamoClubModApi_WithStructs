#include "memoryutils.h"
#include <Game/global_status.h>
#include <Game/player.h>
#include <Game/system.h>
#include <Game/station.h>
#include <Game/mission.h>
#include <Game/asset.h>



void Player::init()
{
	globals_status = MemoryUtils::GetModuleBase("GoF2.exe") + 0x20AD6C; // Globals::status
	globals_appmanager = MemoryUtils::GetModuleBase("GoF2.exe") + 0x20AEFC; // Globals::appManager
	
	while (globalStatus==0) globalStatus = *reinterpret_cast<global_status**>(MemoryUtils::GetModuleBase("GoF2.exe") + 0x20AD6C);
}




int Player::getmoney()
{
	 return globalStatus->m_nMoney;
}

void Player::setmoney(int value)
{
	globalStatus->m_nMoney = value;
}

int Player::getmaxcargo()
{
	return globalStatus->m_pShipInfo->m_nMaxCapacity;
}

void Player::setmaxcargo(int value)
{
	globalStatus->m_pShipInfo->m_nMaxCapacity = value;
   // uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x154, 0x0});
   // MemoryUtils::Write<int>(finaladdr, value);
}

int Player::getcargo()
{
	return globalStatus->m_pShipInfo->m_nCurrentCapacity;
}

void Player::setcargo(int value)
{
	globalStatus->m_pShipInfo->m_nCurrentCapacity = value;
    //uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x154, 0x10});
    //MemoryUtils::Write<int>(finaladdr, value);
}

int Player::getshiparmor()
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x154, 0x20});
    return MemoryUtils::Read<int>(finaladdr);
}

void Player::setshiparmor(int value)
{
	globalStatus->m_pShipInfo->m_nArmor = value;
    //uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x154, 0x20});
    //MemoryUtils::Write<int>(finaladdr, value);
}

bool Player::hasshiparmor()
{
    if (getshiparmor() != 0)
        return true;
    return false;
}

int Player::getmaxshiphealth()
{
	return globalStatus->m_pShipInfo->m_nMaxShipHealth;
    //uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x154, 0x4});
   // return MemoryUtils::Read<int>(finaladdr); 
}

void Player::setmaxshiphealth(int value)
{
	globalStatus->m_pShipInfo->m_nMaxShipHealth = value;
    //uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x154, 0x4});
   // MemoryUtils::Write<int>(finaladdr, value);
}

int Player::getenemieskilled()
{
	return globalStatus->m_nEnemiesKilled;
  //  uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x188});
   // return MemoryUtils::Read<int>(finaladdr);
}

void Player::setenemieskilled(int value)
{
	globalStatus->m_nEnemiesKilled = value;
    //uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x188});
   //MemoryUtils::Write<int>(finaladdr, value);
}

int Player::getlevel()
{
    return globalStatus->m_nPlayerLevel;
    //return globalStatus->m_pShipInfo->m_pShipItems->data[0]->m_nPrice;
}

void Player::setlevel(int value)
{
	globalStatus->m_nPlayerLevel = value;
    //uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x190});
    //MemoryUtils::Write<int>(finaladdr, value);
}

int Player::getvisitedstations()
{
	return globalStatus->m_nVisitedStations;
    //uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x198});
    //return MemoryUtils::Read<int>(finaladdr);
}

void Player::setvisitedstations(int value)
{
	globalStatus->m_nVisitedStations = value;
    //uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x198});
    //MemoryUtils::Write<int>(finaladdr, value);
}

int Player::getjumpgateusedcount()
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x198});
    return MemoryUtils::Read<int>(finaladdr);
}

void Player::setjumpgateusedcount(int value)
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x198});
    MemoryUtils::Write<int>(finaladdr, value);
}

int Player::getcargotookcount()
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x1A8});
    return MemoryUtils::Read<int>(finaladdr);
}

void Player::setcargotookcount(int value)
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x1A8});
    MemoryUtils::Write<int>(finaladdr, value);
}

bool Player::isdocked(void)
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_appmanager, {0x58});
    int isdocked = MemoryUtils::Read<int>(finaladdr);

    if (isdocked == 5)
        return true;
    return false;
}