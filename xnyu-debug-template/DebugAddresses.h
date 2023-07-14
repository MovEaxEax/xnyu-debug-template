#pragma once

// All Debug Addresses
std::vector<DebugAddressParent> debugAdresses;

// Buffer, that can be used to save memory
int int32Buffer = 0;
long long int64Buffer = 0;
float floatBuffer = 0;
double doubleBuffer = 0;
bool boolBuffer = 0;
BYTE byteBuffer = 0;
char* stringBuffer = new char[2048];
void* pointerBuffer;

EXTERN_DLL_EXPORT void SetDebugAddressValue(DebugAddress* targetAddress)
{
	//
	// This function is called if the main mod writes a value from the Debug Menu.
	// It should write the value from the DebugAddress to the memory address of the game
	//

	// Get the full name of the address
	std::string name = targetAddress->nameFull;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	// EXAMPLE
	// 
	// if (name == "player.getposition") DbgWriteFloat(addressPosition, GetVariableFloat(&targetAddress->value))
	// if (name == "player.gethp") DbgWriteInt32(addressHP, GetVariableInt32(&targetAddress->value))
	// if (name == "player.isgamepaused") DbgWriteFloat(addressIsGamePaused, GetVariableBool(&targetAddress->value))
}

EXTERN_DLL_EXPORT void GetDebugAddressValue(DebugAddress* targetAddress)
{
	//
	// This function is called if the main mod reads a value from the Debug Menu.
	// It should write the read value from the address to the DebugAddress object
	//

	// Get the full name of the address
	std::string name = targetAddress->nameFull;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	// Set value to 'none', if nothing was found
	SetVariable(&targetAddress->value, "none");

	// EXAMPLE
	// 
	// if (name == "player.getposition") SetVariable(&targetAddress->value, GetPlayerPosition());
	// if (name == "player.gethp") SetVariable(&targetAddress->value, GetPlayerHP());
	// if (name == "player.isgamepaused") SetVariable(&targetAddress->value, IsGamePaused());
}


