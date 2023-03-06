#pragma once

struct DebugFunction {
    std::string nameParent;
    std::string nameChild;
    std::string nameFull;
    bool rapid;
    std::vector<Variable> parameter;
};

struct DebugFunctionParent {
    std::string nameParent;
    std::vector<DebugFunction> functions;
};

std::vector<DebugFunctionParent> debugFunctions;

EXTERN_DLL_EXPORT void ExecuteDebugFunction(DebugFunction* targetFunction)
{
    //
    // This is the interface for calling debug function
    // Debug functions can be called from TAS scripts and hotkeys
    // 
    // !!! Warning !!!
    // Parameter can be none, there must be a handling for it
    // 
    // Example: if (targetFunction->nameFull == "Player.SetPosition") DoSomething();
    //
}


