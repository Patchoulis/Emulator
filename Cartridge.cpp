#include "Cartridge.h"
#include <unordered_map>
#include <cstdint>

std::unordered_map<unsigned int, std::string> cartTypeMap {
    {0x00,"ROM ONLY"},
    {0x01,"MBC1"},
    {0x02,"MBC1+RAM"},
    {0x03,"MBC1+RAM+BATTERY"},
    {0x05,"MBC2"},
    {0x06,"MBC2+BATTERY"},
    {0x08,"ROM+RAM"},
    {0x09,"ROM+RAM+BATTERY"},
    {0x0B,"MMM01"},
    {0x0C,"MMM01+RAM"},
    {0x0D,"MMM01+RAM+BATTERY"},
    {0x0F,"MBC3+TIMER+BATTERY"},
    {0x10,"MBC3+TIMER+RAM+BATTERY"},
    {0x11,"MBC3"},
    {0x12,"MBC3+RAM"},
    {0x13,"MBC3+RAM+BATTERY"},
    {0x19,"MBC5"},
    {0x1A,"MBC5+RAM"},
    {0x1B,"MBC5+RAM+BATTERY"},
    {0x1C,"MBC5+RUMBLE"},
    {0x1D,"MBC5+RUMBLE+RAM"},
    {0x1E,"MBC5+RUMBLE+RAM+BATTERY"},
    {0x20,"MBC6"},
    {0x22,"MBC7+SENSOR+RUMBLE+RAM+BATTERY"},
    {0xFC,"POCKET CAMERA"},
    {0xFD,"BANDAI TAMA5"},
    {0xFE,"HuC3"},
    {0xFF,"HuC1+RAM+BATTERY"}
};
/* THERE'S WAY TOO MANY, I'll do it later...
std::unordered_map<unsigned int, std::string> oldLicenseeMap {
    {0x00,"None"},
    {0x00,"Nintendo"},
    {0x00,"Capcom"},
    {0x00,"HOT-B"},
    {0x00,"Jaleco"},
    {0x00,"Coconuts Japan"},
    {0x00,"Elite Systems"},
    {0x00,"EA (Electronic Arts)"},
    {0x00,"Hudson Soft"},
    {0x00,"ITC Entertainment"},
    {0x00,"Yanoman"},
    {0x00,"Japan Clary"},
    {0x00,"Virgin Games Ltd."},
    {0x00,"PCM Complete"},
    {0x00,"San-X"},
    {0x00,"Kemco"},
    {0x00,"SETA Corporation"},
    {0x00,"Infogrames"},
    {0x00,"Nintendo"},
    {0x00,"Bandai"},
    {0x00,"Konami"},
    {0x00,"HectorSoft"},
    {0x00,"Capcom"},
    {0x00,"Banpresto"},
    {0x00,".Entertainment i"},
    {0x00,"Gremlin"},
    {0x00,"Ubisoft"},
    {0x00,"Atlus"},
    {0x00,"Malibu Interactive"},
    {0x00,"Angel"},
    {0x00,"Spectrum Holoby"},
    {0x00,"Irem"},
    {0x00,"Virgin Games Ltd."},
    {0x00,"Malibu Interactive"},
    {0x00,"U.S. Gold"},
    {0x00,"Absolute"},
    {0x00,"Acclaim Entertainment"},
    {0x00,"Sammy USA Corporation"},
    {0x00,"GameTek"},
    {0x00,"Park Place"},
    {0x00,"LJN"},
    {0x00,"Matchbox"},
}; */

std::unordered_map<unsigned int, uint> romMap {
    {0x00,2},
    {0x01,4},
    {0x02,8},
    {0x03,16},
    {0x04,32},
    {0x05,64},
    {0x06,128},
    {0x07,256},
    {0x08,512},
    {0x52,72},
    {0x53,80},
    {0x54,96}
};

Cartridge::Cartridge(std::ifstream& file, ROM* roms) {
    ROM mainROM;
    mainROM.Load(file);
    roms[1] = mainROM;

    // Title of a cartridge
    this->game = "";
    for (uint i = 0x0134; i <= 0x0143; i++) {
        if (mainROM.memory[i] != 0) {
            this->game += static_cast<char>(mainROM.memory[i]);
        } else {
            break;
        }
    }
    std::cout << "CARTRIDGE TITLE LOADED: " << this->game << "\n";
    // Cartridge Type
    this->cartType = cartTypeMap[static_cast<unsigned int>(mainROM.memory[0x0147])];
    std::cout << "CARTRIDGE TYPE LOADED: " << this->cartType << "\n";

    // Cartridge Location
    this->japan = static_cast<unsigned int>(mainROM.memory[0x014A]) == 0;
    std::cout << "JAPAN CARTRIDGE: " << (this->japan ? "YES" : "NO") << "\n";

    // ROM banks
    this->banks = romMap[static_cast<unsigned int>(mainROM.memory[0x0148])];
    std::cout << "ROM BANKS DETECTED: " << this->banks << "\n";
    for (uint i = 2; i < this->banks; i++) {
        ROM newROM;
        newROM.Load(file);
        roms[i] = newROM;
    }

    // CHECKSUM VALIDATOR
    uint8_t checksum = 0;
    for (uint16_t address = 0x0134; address <= 0x014C; address++) {
        checksum = checksum - static_cast<uint8_t>(mainROM.memory[address]) - 1;
    }
    this->loaded = checksum == static_cast<uint8_t>(mainROM.memory[0x014D]);
    std::cout << "CHECKSUM VALID: " << (this->loaded ? "YES" : "NO") << "\n";

    file.close();
}


