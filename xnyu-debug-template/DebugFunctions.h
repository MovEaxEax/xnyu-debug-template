#pragma once

// All Debug Functions
std::vector<DebugFunctionParent> debugFunctions;

// Check if a variable parameter is 'none' or not
bool parameterValid(DebugFunction* targetFunction)
{
	bool parameterValid = true;
	for (int i = 0; i < targetFunction->parameter.size(); i++)
	{
		if (targetFunction->parameter[i].value == "none")
		{
			return false;
		}
	}
	return true;
}

EXTERN_DLL_EXPORT void ExecuteDebugFunction(DebugFunction* targetFunction)
{
	//
	// This function is called if the main mod executes a Debug Function.
	// It should resolve the name and execute the function logic
	//

	// Get the full name of the function
	std::string name = targetFunction->nameFull;
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);

	// Check if parameter is not 'none'
	bool vaild = parameterValid(targetFunction);

	// EXAMPLE
	// 
	// if (vaild && name == "player.setposition")
	// {
	//		DbgWriteFloat(addressPositionX, GetVariableFloat(&targetFunction->parameter[0]))
	//		DbgWriteFloat(addressPositionY, GetVariableFloat(&targetFunction->parameter[1]))
	//		DbgWriteFloat(addressPositionZ, GetVariableFloat(&targetFunction->parameter[2]))
	// }
	// if (vaild && name == "player.sethp") DbgWriteInt32(addressHP, GetVariableInt32(&targetFunction->parameter[0]))
	// if (name == "player.setisgamepaused") DbgWriteBool(addressIsGamePaused, valid ? GetVariableBool(&targetFunction->parameter[0]) : !DbgReadBool(addressIsGamePaused))
}


