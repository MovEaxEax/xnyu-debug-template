#include "pch.h"
#include "xNyuLibrary.h"

EXTERN_DLL_EXPORT void __cdecl OnInitDebugMod(DebugSettings _globalSettings, DebugFeatures* _features, DebugReferences _references, ThreadReferences _threadReferences)
{
	//
	// Standard initialization sequence, copy all debugaddress/function if needed, take settings and loggger and draw funtion pointers
	// Feature availability has to be written in the DebugFunction struct
	//

	// Get the gloabl settings from the template
	GlobalSettings = _globalSettings;

	// Utility functions from the main mod
	pDebugConsoleOutput = (DebugConsoleOutputT)_references.logger;
	pDebugDrawRectangle = (DebugDrawRectangleT)_references.drawRectangle;
	pDebugDrawText = (DebugDrawTextT)_references.drawText;

	// Utility functions for graphic hooking
	pInstallGraphicHook = (InstallGraphicHookT)_references.installGraphicsHook;
	pRemoveGraphicHook = (RemoveGraphicHookT)_references.removeGraphicsHook;

	// Utility functions thread handling
	pThreadHookerGetThreadCount = (ThreadHookerGetThreadCountT)_threadReferences.ThreadHookerGetThreadCount;
	pThreadHookerGetThreads = (ThreadHookerGetThreadsT)_threadReferences.ThreadHookerGetThreads;
	pThreadHookerGetSafeThreadCount = (ThreadHookerGetSafeThreadCountT)_threadReferences.ThreadHookerGetSafeThreadCount;
	pThreadHookerGetSafeThreads = (ThreadHookerGetSafeThreadsT)_threadReferences.ThreadHookerGetSafeThreads;
	pThreadHookerSuspendThreads = (ThreadHookerSuspendThreadsT)_threadReferences.ThreadHookerSuspendThreads;
	pThreadHookerResumeThreads = (ThreadHookerResumeThreadsT)_threadReferences.ThreadHookerResumeThreads;
	pThreadHookerCreateThread = (ThreadHookerCreateThreadT)_threadReferences.ThreadHookerCreateThread;
	pThreadHookerCreateRemoteThread = (ThreadHookerCreateRemoteThreadT)_threadReferences.ThreadHookerCreateRemoteThread;
	pThreadHookerCreateRemoteThreadEx = (ThreadHookerCreateRemoteThreadExT)_threadReferences.ThreadHookerCreateRemoteThreadEx;

	// If for some reason, the TASRoutine has to be executed in this mod, this function has to be called
	pTASRoutine = (TASRoutineT)_references.TASRoutine;

	// Determines if a specific features for the Debug Menu is can be used or not
	DebugFeatures features;
	features.debugAddress = true;
	features.debugFunction = true;
	features.savefileEditor = false;
	features.supervision = false;
	features.editorMode = false;
	std::memcpy(_features, &features, sizeof(DebugFeatures));

	// Example to handle initialization for different versions
	if (GlobalSettings.config_version == "version_1")
	{
	}
	else if (GlobalSettings.config_version == "version_2")
	{
	}

	// Initialize memory regions
	GetMemoryRegions(memoryRegionsStart, memoryRegionsEnd, &memoryRegionsCounter);
}

EXTERN_DLL_EXPORT void OnDebugMenu(bool isEnabled)
{
	//
	// Additional trigger, to determine if the Debug Menu is open or not
	//
}

int updateSettingsFrameskip = 0;
EXTERN_DLL_EXPORT void OnFrameDebugMod()
{
	//
	// Main logic, this function is called each frame when the Debug Menu isn't opened
	// 

	// Suspend all threads
	pThreadHookerSuspendThreads(0);

	// EditorMode Handling
	if (EditorModeActivated)
	{
		canMove = false;
		canRotate = false;
		isRunning = false;
	}

	// Frameskip system for settings that have no need to be executed too often
	if (updateSettingsFrameskip >= 120)
	{
		GetMemoryRegions(memoryRegionsStart, memoryRegionsEnd, &memoryRegionsCounter);
		updateSettingsFrameskip = 0;
	}
	updateSettingsFrameskip++;

	// Resume threads again
	pThreadHookerResumeThreads(0);
}

EXTERN_DLL_EXPORT void OnExitDebugMod()
{

	//
	// This function get's called when den debug mod get's ejected, clear buffers and stuff here
	//

}


