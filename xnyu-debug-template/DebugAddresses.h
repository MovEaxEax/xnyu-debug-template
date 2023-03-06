#pragma once

struct DebugAddress {
    std::string nameParent;
    std::string nameChild;
    std::string nameFull;
    Variable value;
};

struct DebugAddressParent {
    std::string nameParent;
    std::vector<DebugAddress> addresses;
};

std::vector<DebugAddressParent> debugAdresses;

EXTERN_DLL_EXPORT void SetDebugAddressValue(DebugAddress* targetAddress)
{
    //
    // This is the interface for setting debug values in memory
    // Debug values can be written from TAS scripts
    //
    // Example: WriteVariableToMemory(targetAddress, myMemoryAddress);
    //
}

EXTERN_DLL_EXPORT void GetDebugAddressValue(DebugAddress* targetAddress)
{
    //
    // This is the interface for reading debug values in memory
    // Debug values can be read from TAS scripts and debug menu
    // The debug menu however only reads the 'value' parameter
    // The TAS reads the type specific parameter
    // 
    // Example: ReadVariableFromMemory(targetAddress, myMemoryAddress);
    //
}


