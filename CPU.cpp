#include "CPU.h"

std::unordered_map<unsigned int, std::vector<std::string>> noPreInstructs {
    {0x00, {"NOP"}},
    {0x01, {"LD", "BC", "n16"}},
    {0x02, {"LD", "BC", "ADDR", "A"}},
    {0x03, {"INC", "BC"}},
    {0x04, {"INC", "B"}},
    {0x05, {"DEC", "B"}},
    {0x06, {"LD", "B", "n8"}},
    {0x07, {"RLCA"}},
    {0x08, {"LD", "a16", "ADDR", "SP"}},
    {0x09, {"ADD", "HL", "BC"}},
    {0x0A, {"LD", "A", "BC", "ADDR"}},
    {0x0B, {"DEC", "BC"}},
    {0x0C, {"INC", "C"}},
    {0x0D, {"DEC", "C"}},
    {0x0E, {"LD", "C", "n8"}},
    {0x0F, {"RRCA"}},
    {0x10, {"STOP", "n8"}},
    {0x11, {"LD", "DE", "n16"}},
    {0x12, {"LD", "DE", "ADDR", "A"}},
    {0x13, {"INC", "DE"}},
    {0x14, {"INC", "D"}},
    {0x15, {"DEC", "D"}},
    {0x16, {"LD", "D", "n8"}},
    {0x17, {"RLA"}},
    {0x18, {"JR", "e8"}},
    {0x19, {"ADD", "HL", "DE"}},
    {0x1A, {"LD", "A", "DE", "ADDR"}},
    {0x1B, {"DEC", "DE"}},
    {0x1C, {"INC", "E"}},
    {0x1D, {"DEC", "E"}},
    {0x1E, {"LD", "E", "n8"}},
    {0x1F, {"RRA"}},
    {0x20, {"JR", "NZ", "e8"}},
    {0x21, {"LD", "HL", "n16"}},
    {0x22, {"LD", "HL", "ADDR", "INCR", "A"}},
    {0x23, {"INC", "HL"}},
    {0x24, {"INC", "H"}},
    {0x25, {"DEC", "H"}},
    {0x26, {"LD", "H", "n8"}},
    {0x27, {"DAA"}},
    {0x28, {"JR", "Z", "e8"}},
    {0x29, {"ADD", "HL", "HL"}},
    {0x2A, {"LD", "A", "HL", "ADDR", "INCR"}},
    {0x2B, {"DEC", "HL"}},
    {0x2C, {"INC", "L"}},
    {0x2D, {"DEC", "L"}},
    {0x2E, {"LD", "L", "n8"}},
    {0x2F, {"CPL"}},
    {0x30, {"JR", "NC", "e8"}},
    {0x31, {"LD", "SP", "n16"}},
    {0x32, {"LD", "HL", "ADDR", "DECR", "A"}},
    {0x33, {"INC", "SP"}},
    {0x34, {"INC", "HL", "ADDR"}},
    {0x35, {"DEC", "HL", "ADDR"}},
    {0x36, {"LD", "HL", "ADDR", "n8"}},
    {0x37, {"SCF"}},
    {0x38, {"JR", "C", "e8"}},
    {0x39, {"ADD", "HL", "SP"}},
    {0x3A, {"LD", "A", "HL", "ADDR", "DECR"}},
    {0x3B, {"DEC", "SP"}},
    {0x3C, {"INC", "A"}},
    {0x3D, {"DEC", "A"}},
    {0x3E, {"LD", "A", "n8"}},
    {0x3F, {"CCF"}},
    {0x40, {"LD", "B", "B"}},
    {0x41, {"LD", "B", "C"}},
    {0x42, {"LD", "B", "D"}},
    {0x43, {"LD", "B", "E"}},
    {0x44, {"LD", "B", "H"}},
    {0x45, {"LD", "B", "L"}},
    {0x46, {"LD", "B", "HL", "ADDR"}},
    {0x47, {"LD", "B", "A"}},
    {0x48, {"LD", "C", "B"}},
    {0x49, {"LD", "C", "C"}},
    {0x4A, {"LD", "C", "D"}},
    {0x4B, {"LD", "C", "E"}},
    {0x4C, {"LD", "C", "H"}},
    {0x4D, {"LD", "C", "L"}},
    {0x4E, {"LD", "C", "HL", "ADDR"}},
    {0x4F, {"LD", "C", "A"}},
    {0x50, {"LD", "D", "B"}},
    {0x51, {"LD", "D", "C"}},
    {0x52, {"LD", "D", "D"}},
    {0x53, {"LD", "D", "E"}},
    {0x54, {"LD", "D", "H"}},
    {0x55, {"LD", "D", "L"}},
    {0x56, {"LD", "D", "HL", "ADDR"}},
    {0x57, {"LD", "D", "A"}},
    {0x58, {"LD", "E", "B"}},
    {0x59, {"LD", "E", "C"}},
    {0x5A, {"LD", "E", "D"}},
    {0x5B, {"LD", "E", "E"}},
    {0x5C, {"LD", "E", "H"}},
    {0x5D, {"LD", "E", "L"}},
    {0x5E, {"LD", "E", "HL", "ADDR"}},
    {0x5F, {"LD", "E", "A"}},
    {0x60, {"LD", "H", "B"}},
    {0x61, {"LD", "H", "C"}},
    {0x62, {"LD", "H", "D"}},
    {0x63, {"LD", "H", "E"}},
    {0x64, {"LD", "H", "H"}},
    {0x65, {"LD", "H", "L"}},
    {0x66, {"LD", "H", "HL", "ADDR"}},
    {0x67, {"LD", "H", "A"}},
    {0x68, {"LD", "L", "B"}},
    {0x69, {"LD", "L", "C"}},
    {0x6A, {"LD", "L", "D"}},
    {0x6B, {"LD", "L", "E"}},
    {0x6C, {"LD", "L", "H"}},
    {0x6D, {"LD", "L", "L"}},
    {0x6E, {"LD", "L", "HL", "ADDR"}},
    {0x6F, {"LD", "L", "A"}},
    {0x70, {"LD", "HL", "ADDR", "B"}},
    {0x71, {"LD", "HL", "ADDR", "C"}},
    {0x72, {"LD", "HL", "ADDR", "D"}},
    {0x73, {"LD", "HL", "ADDR", "E"}},
    {0x74, {"LD", "HL", "ADDR", "H"}},
    {0x75, {"LD", "HL", "ADDR", "L"}},
    {0x76, {"HALT"}},
    {0x77, {"LD", "HL", "ADDR", "A"}},
    {0x78, {"LD", "A", "B"}},
    {0x79, {"LD", "A", "C"}},
    {0x7A, {"LD", "A", "D"}},
    {0x7B, {"LD", "A", "E"}},
    {0x7C, {"LD", "A", "H"}},
    {0x7D, {"LD", "A", "L"}},
    {0x7E, {"LD", "A", "HL", "ADDR"}},
    {0x7F, {"LD", "A", "A"}},
    {0x80, {"ADD", "A", "B"}},
    {0x81, {"ADD", "A", "C"}},
    {0x82, {"ADD", "A", "D"}},
    {0x83, {"ADD", "A", "E"}},
    {0x84, {"ADD", "A", "H"}},
    {0x85, {"ADD", "A", "L"}},
    {0x86, {"ADD", "A", "HL", "ADDR"}},
    {0x87, {"ADD", "A", "A"}},
    {0x88, {"ADC", "A", "B"}},
    {0x89, {"ADC", "A", "C"}},
    {0x8A, {"ADC", "A", "D"}},
    {0x8B, {"ADC", "A", "E"}},
    {0x8C, {"ADC", "A", "H"}},
    {0x8D, {"ADC", "A", "L"}},
    {0x8E, {"ADC", "A", "HL", "ADDR"}},
    {0x8F, {"ADC", "A", "A"}},
    {0x90, {"SUB", "A", "B"}},
    {0x91, {"SUB", "A", "C"}},
    {0x92, {"SUB", "A", "D"}},
    {0x93, {"SUB", "A", "E"}},
    {0x94, {"SUB", "A", "H"}},
    {0x95, {"SUB", "A", "L"}},
    {0x96, {"SUB", "A", "HL", "ADDR"}},
    {0x97, {"SUB", "A", "A"}},
    {0x98, {"SBC", "A", "B"}},
    {0x99, {"SBC", "A", "C"}},
    {0x9A, {"SBC", "A", "D"}},
    {0x9B, {"SBC", "A", "E"}},
    {0x9C, {"SBC", "A", "H"}},
    {0x9D, {"SBC", "A", "L"}},
    {0x9E, {"SBC", "A", "HL", "ADDR"}},
    {0x9F, {"SBC", "A", "A"}},
    {0xA0, {"AND", "A", "B"}},
    {0xA1, {"AND", "A", "C"}},
    {0xA2, {"AND", "A", "D"}},
    {0xA3, {"AND", "A", "E"}},
    {0xA4, {"AND", "A", "H"}},
    {0xA5, {"AND", "A", "L"}},
    {0xA6, {"AND", "A", "HL", "ADDR"}},
    {0xA7, {"AND", "A", "A"}},
    {0xA8, {"XOR", "A", "B"}},
    {0xA9, {"XOR", "A", "C"}},
    {0xAA, {"XOR", "A", "D"}},
    {0xAB, {"XOR", "A", "E"}},
    {0xAC, {"XOR", "A", "H"}},
    {0xAD, {"XOR", "A", "L"}},
    {0xAE, {"XOR", "A", "HL", "ADDR"}},
    {0xAF, {"XOR", "A", "A"}},
    {0xB0, {"OR", "A", "B"}},
    {0xB1, {"OR", "A", "C"}},
    {0xB2, {"OR", "A", "D"}},
    {0xB3, {"OR", "A", "E"}},
    {0xB4, {"OR", "A", "H"}},
    {0xB5, {"OR", "A", "L"}},
    {0xB6, {"OR", "A", "HL", "ADDR"}},
    {0xB7, {"OR", "A", "A"}},
    {0xB8, {"CP", "A", "B"}},
    {0xB9, {"CP", "A", "C"}},
    {0xBA, {"CP", "A", "D"}},
    {0xBB, {"CP", "A", "E"}},
    {0xBC, {"CP", "A", "H"}},
    {0xBD, {"CP", "A", "L"}},
    {0xBE, {"CP", "A", "HL", "ADDR"}},
    {0xBF, {"CP", "A", "A"}},
    {0xC0, {"RET", "NZ"}},
    {0xC1, {"POP", "BC"}},
    {0xC2, {"JP", "NZ", "a16"}},
    {0xC3, {"JP", "a16"}},
    {0xC4, {"CALL", "NZ", "a16"}},
    {0xC5, {"PUSH", "BC"}},
    {0xC6, {"ADD", "A", "n8"}},
    {0xC7, {"RST", "00"}},
    {0xC8, {"RET", "Z"}},
    {0xC9, {"RET"}},
    {0xCA, {"JP", "Z", "a16"}},
    {0xCB, {"PREFIX"}},
    {0xCC, {"CALL", "Z", "a16"}},
    {0xCD, {"CALL", "a16"}},
    {0xCE, {"ADC", "A", "n8"}},
    {0xCF, {"RST", "08"}},
    {0xD0, {"RET", "NC"}},
    {0xD1, {"POP", "DE"}},
    {0xD2, {"JP", "NC", "a16"}},
    {0xD3, {"ILLEGAL_D3"}},
    {0xD4, {"CALL", "NC", "a16"}},
    {0xD5, {"PUSH", "DE"}},
    {0xD6, {"SUB", "A", "n8"}},
    {0xD7, {"RST", "10"}},
    {0xD8, {"RET", "C"}},
    {0xD9, {"RETI"}},
    {0xDA, {"JP", "C", "a16"}},
    {0xDB, {"ILLEGAL_DB"}},
    {0xDC, {"CALL", "C", "a16"}},
    {0xDD, {"ILLEGAL_DD"}},
    {0xDE, {"SBC", "A", "n8"}},
    {0xDF, {"RST", "18"}},
    {0xE0, {"LDH", "a8", "ADDR", "A"}},
    {0xE1, {"POP", "HL"}},
    {0xE2, {"LD", "C", "ADDR", "A"}},
    {0xE3, {"ILLEGAL_E3"}},
    {0xE4, {"ILLEGAL_E4"}},
    {0xE5, {"PUSH", "HL"}},
    {0xE6, {"AND", "A", "n8"}},
    {0xE7, {"RST", "20"}},
    {0xE8, {"ADD", "SP", "e8"}},
    {0xE9, {"JP", "HL"}},
    {0xEA, {"LD", "a16", "ADDR", "A"}},
    {0xEB, {"ILLEGAL_EB"}},
    {0xEC, {"ILLEGAL_EC"}},
    {0xED, {"ILLEGAL_ED"}},
    {0xEE, {"XOR", "A", "n8"}},
    {0xEF, {"RST", "28"}},
    {0xF0, {"LDH", "A", "a8", "ADDR"}},
    {0xF1, {"POP", "AF"}},
    {0xF2, {"LD", "A", "C", "ADDR"}},
    {0xF3, {"DI"}},
    {0xF4, {"ILLEGAL_F4"}},
    {0xF5, {"PUSH", "AF"}},
    {0xF6, {"OR", "A", "n8"}},
    {0xF7, {"RST", "30"}},
    {0xF8, {"LD", "HL", "SP", "INCR", "e8"}},
    {0xF9, {"LD", "SP", "HL"}},
    {0xFA, {"LD", "A", "a16", "ADDR"}},
    {0xFB, {"EI"}},
    {0xFC, {"ILLEGAL_FC"}},
    {0xFD, {"ILLEGAL_FD"}},
    {0xFE, {"CP", "A", "n8"}},
    {0xFF, {"RST", "38"}}
};

std::unordered_map<unsigned int, std::vector<std::string>> PreInstructs {
    {0x00, {"RLC", "B"}},
    {0x01, {"RLC", "C"}},
    {0x02, {"RLC", "D"}},
    {0x03, {"RLC", "E"}},
    {0x04, {"RLC", "H"}},
    {0x05, {"RLC", "L"}},
    {0x06, {"RLC", "HL", "ADDR"}},
    {0x07, {"RLC", "A"}},
    {0x08, {"RRC", "B"}},
    {0x09, {"RRC", "C"}},
    {0x0A, {"RRC", "D"}},
    {0x0B, {"RRC", "E"}},
    {0x0C, {"RRC", "H"}},
    {0x0D, {"RRC", "L"}},
    {0x0E, {"RRC", "HL", "ADDR"}},
    {0x0F, {"RRC", "A"}},
    {0x10, {"RL", "B"}},
    {0x11, {"RL", "C"}},
    {0x12, {"RL", "D"}},
    {0x13, {"RL", "E"}},
    {0x14, {"RL", "H"}},
    {0x15, {"RL", "L"}},
    {0x16, {"RL", "HL", "ADDR"}},
    {0x17, {"RL", "A"}},
    {0x18, {"RR", "B"}},
    {0x19, {"RR", "C"}},
    {0x1A, {"RR", "D"}},
    {0x1B, {"RR", "E"}},
    {0x1C, {"RR", "H"}},
    {0x1D, {"RR", "L"}},
    {0x1E, {"RR", "HL", "ADDR"}},
    {0x1F, {"RR", "A"}},
    {0x20, {"SLA", "B"}},
    {0x21, {"SLA", "C"}},
    {0x22, {"SLA", "D"}},
    {0x23, {"SLA", "E"}},
    {0x24, {"SLA", "H"}},
    {0x25, {"SLA", "L"}},
    {0x26, {"SLA", "HL", "ADDR"}},
    {0x27, {"SLA", "A"}},
    {0x28, {"SRA", "B"}},
    {0x29, {"SRA", "C"}},
    {0x2A, {"SRA", "D"}},
    {0x2B, {"SRA", "E"}},
    {0x2C, {"SRA", "H"}},
    {0x2D, {"SRA", "L"}},
    {0x2E, {"SRA", "HL", "ADDR"}},
    {0x2F, {"SRA", "A"}},
    {0x30, {"SWAP", "B"}},
    {0x31, {"SWAP", "C"}},
    {0x32, {"SWAP", "D"}},
    {0x33, {"SWAP", "E"}},
    {0x34, {"SWAP", "H"}},
    {0x35, {"SWAP", "L"}},
    {0x36, {"SWAP", "HL", "ADDR"}},
    {0x37, {"SWAP", "A"}},
    {0x38, {"SRL", "B"}},
    {0x39, {"SRL", "C"}},
    {0x3A, {"SRL", "D"}},
    {0x3B, {"SRL", "E"}},
    {0x3C, {"SRL", "H"}},
    {0x3D, {"SRL", "L"}},
    {0x3E, {"SRL", "HL", "ADDR"}},
    {0x3F, {"SRL", "A"}},
    {0x40, {"BIT", "0", "B"}},
    {0x41, {"BIT", "0", "C"}},
    {0x42, {"BIT", "0", "D"}},
    {0x43, {"BIT", "0", "E"}},
    {0x44, {"BIT", "0", "H"}},
    {0x45, {"BIT", "0", "L"}},
    {0x46, {"BIT", "0", "HL", "ADDR"}},
    {0x47, {"BIT", "0", "A"}},
    {0x48, {"BIT", "1", "B"}},
    {0x49, {"BIT", "1", "C"}},
    {0x4A, {"BIT", "1", "D"}},
    {0x4B, {"BIT", "1", "E"}},
    {0x4C, {"BIT", "1", "H"}},
    {0x4D, {"BIT", "1", "L"}},
    {0x4E, {"BIT", "1", "HL", "ADDR"}},
    {0x4F, {"BIT", "1", "A"}},
    {0x50, {"BIT", "2", "B"}},
    {0x51, {"BIT", "2", "C"}},
    {0x52, {"BIT", "2", "D"}},
    {0x53, {"BIT", "2", "E"}},
    {0x54, {"BIT", "2", "H"}},
    {0x55, {"BIT", "2", "L"}},
    {0x56, {"BIT", "2", "HL", "ADDR"}},
    {0x57, {"BIT", "2", "A"}},
    {0x58, {"BIT", "3", "B"}},
    {0x59, {"BIT", "3", "C"}},
    {0x5A, {"BIT", "3", "D"}},
    {0x5B, {"BIT", "3", "E"}},
    {0x5C, {"BIT", "3", "H"}},
    {0x5D, {"BIT", "3", "L"}},
    {0x5E, {"BIT", "3", "HL", "ADDR"}},
    {0x5F, {"BIT", "3", "A"}},
    {0x60, {"BIT", "4", "B"}},
    {0x61, {"BIT", "4", "C"}},
    {0x62, {"BIT", "4", "D"}},
    {0x63, {"BIT", "4", "E"}},
    {0x64, {"BIT", "4", "H"}},
    {0x65, {"BIT", "4", "L"}},
    {0x66, {"BIT", "4", "HL", "ADDR"}},
    {0x67, {"BIT", "4", "A"}},
    {0x68, {"BIT", "5", "B"}},
    {0x69, {"BIT", "5", "C"}},
    {0x6A, {"BIT", "5", "D"}},
    {0x6B, {"BIT", "5", "E"}},
    {0x6C, {"BIT", "5", "H"}},
    {0x6D, {"BIT", "5", "L"}},
    {0x6E, {"BIT", "5", "HL", "ADDR"}},
    {0x6F, {"BIT", "5", "A"}},
    {0x70, {"BIT", "6", "B"}},
    {0x71, {"BIT", "6", "C"}},
    {0x72, {"BIT", "6", "D"}},
    {0x73, {"BIT", "6", "E"}},
    {0x74, {"BIT", "6", "H"}},
    {0x75, {"BIT", "6", "L"}},
    {0x76, {"BIT", "6", "HL", "ADDR"}},
    {0x77, {"BIT", "6", "A"}},
    {0x78, {"BIT", "7", "B"}},
    {0x79, {"BIT", "7", "C"}},
    {0x7A, {"BIT", "7", "D"}},
    {0x7B, {"BIT", "7", "E"}},
    {0x7C, {"BIT", "7", "H"}},
    {0x7D, {"BIT", "7", "L"}},
    {0x7E, {"BIT", "7", "HL", "ADDR"}},
    {0x7F, {"BIT", "7", "A"}},
    {0x80, {"RES", "0", "B"}},
    {0x81, {"RES", "0", "C"}},
    {0x82, {"RES", "0", "D"}},
    {0x83, {"RES", "0", "E"}},
    {0x84, {"RES", "0", "H"}},
    {0x85, {"RES", "0", "L"}},
    {0x86, {"RES", "0", "HL", "ADDR"}},
    {0x87, {"RES", "0", "A"}},
    {0x88, {"RES", "1", "B"}},
    {0x89, {"RES", "1", "C"}},
    {0x8A, {"RES", "1", "D"}},
    {0x8B, {"RES", "1", "E"}},
    {0x8C, {"RES", "1", "H"}},
    {0x8D, {"RES", "1", "L"}},
    {0x8E, {"RES", "1", "HL", "ADDR"}},
    {0x8F, {"RES", "1", "A"}},
    {0x90, {"RES", "2", "B"}},
    {0x91, {"RES", "2", "C"}},
    {0x92, {"RES", "2", "D"}},
    {0x93, {"RES", "2", "E"}},
    {0x94, {"RES", "2", "H"}},
    {0x95, {"RES", "2", "L"}},
    {0x96, {"RES", "2", "HL", "ADDR"}},
    {0x97, {"RES", "2", "A"}},
    {0x98, {"RES", "3", "B"}},
    {0x99, {"RES", "3", "C"}},
    {0x9A, {"RES", "3", "D"}},
    {0x9B, {"RES", "3", "E"}},
    {0x9C, {"RES", "3", "H"}},
    {0x9D, {"RES", "3", "L"}},
    {0x9E, {"RES", "3", "HL", "ADDR"}},
    {0x9F, {"RES", "3", "A"}},
    {0xA0, {"RES", "4", "B"}},
    {0xA1, {"RES", "4", "C"}},
    {0xA2, {"RES", "4", "D"}},
    {0xA3, {"RES", "4", "E"}},
    {0xA4, {"RES", "4", "H"}},
    {0xA5, {"RES", "4", "L"}},
    {0xA6, {"RES", "4", "HL", "ADDR"}},
    {0xA7, {"RES", "4", "A"}},
    {0xA8, {"RES", "5", "B"}},
    {0xA9, {"RES", "5", "C"}},
    {0xAA, {"RES", "5", "D"}},
    {0xAB, {"RES", "5", "E"}},
    {0xAC, {"RES", "5", "H"}},
    {0xAD, {"RES", "5", "L"}},
    {0xAE, {"RES", "5", "HL", "ADDR"}},
    {0xAF, {"RES", "5", "A"}},
    {0xB0, {"RES", "6", "B"}},
    {0xB1, {"RES", "6", "C"}},
    {0xB2, {"RES", "6", "D"}},
    {0xB3, {"RES", "6", "E"}},
    {0xB4, {"RES", "6", "H"}},
    {0xB5, {"RES", "6", "L"}},
    {0xB6, {"RES", "6", "HL", "ADDR"}},
    {0xB7, {"RES", "6", "A"}},
    {0xB8, {"RES", "7", "B"}},
    {0xB9, {"RES", "7", "C"}},
    {0xBA, {"RES", "7", "D"}},
    {0xBB, {"RES", "7", "E"}},
    {0xBC, {"RES", "7", "H"}},
    {0xBD, {"RES", "7", "L"}},
    {0xBE, {"RES", "7", "HL", "ADDR"}},
    {0xBF, {"RES", "7", "A"}},
    {0xC0, {"SET", "0", "B"}},
    {0xC1, {"SET", "0", "C"}},
    {0xC2, {"SET", "0", "D"}},
    {0xC3, {"SET", "0", "E"}},
    {0xC4, {"SET", "0", "H"}},
    {0xC5, {"SET", "0", "L"}},
    {0xC6, {"SET", "0", "HL", "ADDR"}},
    {0xC7, {"SET", "0", "A"}},
    {0xC8, {"SET", "1", "B"}},
    {0xC9, {"SET", "1", "C"}},
    {0xCA, {"SET", "1", "D"}},
    {0xCB, {"SET", "1", "E"}},
    {0xCC, {"SET", "1", "H"}},
    {0xCD, {"SET", "1", "L"}},
    {0xCE, {"SET", "1", "HL", "ADDR"}},
    {0xCF, {"SET", "1", "A"}},
    {0xD0, {"SET", "2", "B"}},
    {0xD1, {"SET", "2", "C"}},
    {0xD2, {"SET", "2", "D"}},
    {0xD3, {"SET", "2", "E"}},
    {0xD4, {"SET", "2", "H"}},
    {0xD5, {"SET", "2", "L"}},
    {0xD6, {"SET", "2", "HL", "ADDR"}},
    {0xD7, {"SET", "2", "A"}},
    {0xD8, {"SET", "3", "B"}},
    {0xD9, {"SET", "3", "C"}},
    {0xDA, {"SET", "3", "D"}},
    {0xDB, {"SET", "3", "E"}},
    {0xDC, {"SET", "3", "H"}},
    {0xDD, {"SET", "3", "L"}},
    {0xDE, {"SET", "3", "HL", "ADDR"}},
    {0xDF, {"SET", "3", "A"}},
    {0xE0, {"SET", "4", "B"}},
    {0xE1, {"SET", "4", "C"}},
    {0xE2, {"SET", "4", "D"}},
    {0xE3, {"SET", "4", "E"}},
    {0xE4, {"SET", "4", "H"}},
    {0xE5, {"SET", "4", "L"}},
    {0xE6, {"SET", "4", "HL", "ADDR"}},
    {0xE7, {"SET", "4", "A"}},
    {0xE8, {"SET", "5", "B"}},
    {0xE9, {"SET", "5", "C"}},
    {0xEA, {"SET", "5", "D"}},
    {0xEB, {"SET", "5", "E"}},
    {0xEC, {"SET", "5", "H"}},
    {0xED, {"SET", "5", "L"}},
    {0xEE, {"SET", "5", "HL", "ADDR"}},
    {0xEF, {"SET", "5", "A"}},
    {0xF0, {"SET", "6", "B"}},
    {0xF1, {"SET", "6", "C"}},
    {0xF2, {"SET", "6", "D"}},
    {0xF3, {"SET", "6", "E"}},
    {0xF4, {"SET", "6", "H"}},
    {0xF5, {"SET", "6", "L"}},
    {0xF6, {"SET", "6", "HL", "ADDR"}},
    {0xF7, {"SET", "6", "A"}},
    {0xF8, {"SET", "7", "B"}},
    {0xF9, {"SET", "7", "C"}},
    {0xFA, {"SET", "7", "D"}},
    {0xFB, {"SET", "7", "E"}},
    {0xFC, {"SET", "7", "H"}},
    {0xFD, {"SET", "7", "L"}},
    {0xFE, {"SET", "7", "HL", "ADDR"}},
    {0xFF, {"SET", "7", "A"}}
};



CPU::CPU(uint freq) {
    this->roms = new ROM[MAXROMS];
    this->delay = (1/freq) * 1000;
}

void CPU::LoadBootRom(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to load the boot ROM" << std::endl;
        return;
    }
    ROM bootROM;
    bootROM.Load(file);
    this->roms[0] = bootROM;
    file.close();
    currentROM = bootROM.memory;
}

void CPU::LoadCart(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to load the Cartridge ROM" << std::endl;
        return;
    }
    
    this->cart = new Cartridge(file,this->roms);
}

bool conditionCheck(const std::string& token, uint16_t flags) {
    if (token == "Z") return (flags & 0x80) == 0x80;
    if (token == "NZ") return (flags & 0x80) == 0x0;
    if (token == "C") return (flags & 0x10) == 0x10;
    if (token == "NC") return (flags & 0x10) == 0x0;
    return false;
}

uint8_t* CPU::GetRegisterByteByToken(const std::string& token) {
    if (token == "A") return reinterpret_cast<uint8_t*>(&regs.AF) + 1;
    if (token == "F") return reinterpret_cast<uint8_t*>(&regs.AF);
    if (token == "B") return reinterpret_cast<uint8_t*>(&regs.BC) + 1;
    if (token == "C") return reinterpret_cast<uint8_t*>(&regs.BC);
    if (token == "D") return reinterpret_cast<uint8_t*>(&regs.DE) + 1;
    if (token == "E") return reinterpret_cast<uint8_t*>(&regs.DE);
    if (token == "H") return reinterpret_cast<uint8_t*>(&regs.HL) + 1;
    if (token == "L") return reinterpret_cast<uint8_t*>(&regs.HL);
    if (token == "n8") return &(currentROM[regs.PC++]);

    return nullptr;
}

// REMEMBER TO DO DAA
void CPU::Execute() {
    uint8_t opcode = currentROM[this->regs.PC++];
    const std::vector<std::string> *tokens = &noPreInstructs[opcode];
    if ((*tokens)[0] == "PREFIX") {
        opcode = currentROM[this->regs.PC++];
        tokens = &PreInstructs[opcode];
    }
    if ((*tokens)[0] == "NOP") {
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "STOP") {
        this->regs.PC++;
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "CCF") {
        this->regs.AF = (this->regs.AF & 0xFFEF) | (~(this->regs.AF & 0x10));
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "CPL") {
        this->regs.AF = (~(this->regs.AF & 0xFF00)) | (this->regs.AF & 0xFF);
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "DI") {
        this->interrupts.IME = false;
        return;
    }
    if ((*tokens)[0] == "EI") {
        this->interrupts.IME_scheduled = true;
        return;
    }
    if ((*tokens)[0] == "HALT") {
        // Still gotta add some logic
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "RETI") {
        this->interrupts.IME = true;
        this->regs.PC = (this->currentROM[this->regs.SP++] & 0xFF) | (static_cast<uint16_t>(this->currentROM[this->regs.SP++]) << 8);
        return;
    }
    if ((*tokens)[0] == "RET" && (*tokens).size() == 1) {
        this->regs.PC = (this->currentROM[this->regs.SP++] & 0xFF) | (static_cast<uint16_t>(this->currentROM[this->regs.SP++]) << 8);
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "RLA") {
        bool carry = (this->regs.AF & 0x8000) == 0x8000;
        this->regs.AF = ((this->regs.AF & 0xFF00) << 1) | (this->regs.AF & 0xFF) | (((this->regs.AF & 0x10) == 0x10) ? 0x100 : 0x0);
        if (carry) {this->regs.AF |= 0x10;} else {this->regs.AF &= 0xFFEF;}
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "RCLA") {
        bool carry = (this->regs.AF & 0x8000) == 0x8000;
        this->regs.AF = ((this->regs.AF & 0xFF00) << 1) | (this->regs.AF & 0xFF) | (carry ? 0x110 : 0x0);
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "RRA") {
        bool carry = (this->regs.AF & 0x100) == 0x100;
        this->regs.AF = ((this->regs.AF & 0xFF00) >> 1) | (this->regs.AF & 0xFF) | (((this->regs.AF & 0x10) == 0x10) ? 0x8000 : 0x0);
        if (carry) {this->regs.AF |= 0x10;} else {this->regs.AF &= 0xFFEF;}
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "RRCA") {
        bool carry = (this->regs.AF & 0x100) == 0x100;
        this->regs.AF = ((this->regs.AF & 0xFF00) >> 1) | (this->regs.AF & 0xFF) | (carry ? 0x8010 : 0x0);
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "SCF") {
        this->regs.AF |= 0x100;
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "RST") {
        currentROM[--this->regs.SP] = (this->regs.PC & 0xFF00) >> 8;
        currentROM[--this->regs.SP] = (this->regs.PC & 0xFF);
        this->regs.SP = std::stoul((*tokens)[1], nullptr, 16);
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
    if ((*tokens)[0] == "ADC") {
        bool carry = ((this->regs.AF & 0x10) == 0x10);
        uint16_t res = ((this->regs.AF & 0xFF00) >> 8) + carry;
        if ((*tokens)[2] == "HL") {
            res += this->currentROM[this->regs.HL];
        } else {
            res += *GetRegisterByteByToken((*tokens)[2]);
        }
        if (this->interrupts.IME_scheduled) {
            this->interrupts.IME_scheduled = false;
            this->interrupts.IME = true;
        }
        return;
    }
}


CPU::~CPU() {
    delete[] this->roms;
    delete this->cart;
    this->cart = nullptr;
    this->roms = nullptr;
}

