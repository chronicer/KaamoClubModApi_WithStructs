#include "memoryutils.h"
#include "abyssengine.h"
#include <Game/player.h>
#include <Game/system.h>
#include <Game/station.h>
#include <Game/mission.h>
#include <Game/asset.h>

void Station::init()
{
    globals_status = MemoryUtils::GetModuleBase("GoF2.exe") + 0x20AD6C; // Globals::status
}

int Station::getid()
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x8});
    return MemoryUtils::Read<int>(finaladdr);
}

void Station::setid(int value)
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x8});
    MemoryUtils::Write<int>(finaladdr, value);
}

std::string Station::getname()
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x0, 0x0});
    return MemoryUtils::ReadWideString(finaladdr);
}

void Station::setname(const std::string value)
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x0, 0x0});
    MemoryUtils::WriteWideString(finaladdr, value);
}

int Station::gettechlevel()
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x1C});
    return MemoryUtils::Read<int>(finaladdr);
}

void Station::settechlevel(int value)
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x1C});
    MemoryUtils::Write<int>(finaladdr, value);
}

bool Station::isvoid(void)
{
    if (getid() == -1)
        return true;
    return false;
}

int Station::getangaritemscount()
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x24, 0x0});
    return MemoryUtils::Read<int>(finaladdr);
}

void Station::setangaritemscount(int value)
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x24, 0x0});
    MemoryUtils::Write<int>(finaladdr, value);
}

int Station::getangarshipscount()
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x28, 0x0});
    return MemoryUtils::Read<int>(finaladdr);
}

void Station::setangarshipscount(int value)
{
    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x28, 0x0});
    MemoryUtils::Write<int>(finaladdr, value);
}

void Station::setangarshipid(int id, int value)
{
    unsigned int offset = (id == 0) ? 0 : (1 << (id + 1));

    uintptr_t finaladdr = MemoryUtils::GetPointerAddress(globals_status, {0x160, 0x28, 0x4, offset, 0x0});
    MemoryUtils::Write<int>(finaladdr, value);
}

int Station::create(const std::string& str, int techlevel, int textureid, int systemid)
{
    if (EventManager::isearlyinit_finished) {
        std::cout << "[-] Failed to call station:Create(), you can only call it in the EarlyInit event" << std::endl;
        return -1;
    }
    SingleStation s;
    
    memset(&s, 0, sizeof(SingleStation));

    // utf8 to utf16 bruh I hate this game (sol2 can't pass a wchar directly -_-)
    int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
    std::wstring out(len, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, out.data(), len);

    s.name = AbyssEngine::newstring(out.c_str());
    s.id = created_stations.empty() ? 109 : 109 + created_stations.size();
    s.systemid = systemid;
    s.techlevel = techlevel;
    s.textureid = textureid;
    s.unk0 = 0; s.unk1 = 0; s.unk2.fill(0);

    created_stations.push_back(s);
    return 108 + created_stations.size();
}