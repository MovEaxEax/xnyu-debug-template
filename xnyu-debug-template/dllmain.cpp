#include "pch.h"
#include "xNyuLibrary.h"

EXTERN_DLL_EXPORT void OnInitDebugMod(DebugSettings _globalSettings, DebugFeatures* _features, void* _logger, void* _drawRectangle, void* _drawText)
{
	//
	// Standard initialization sequence, copy all debugaddress/function if needed, take settings and loggger and draw funtion pointers
	// Feature availability has to be written in the DebugFunction struct
	//

	GlobalSettings = _globalSettings;

	pDebugConsoleOutput = (DebugConsoleOutputT)_logger;
	pDebugDrawRectangle = (DebugDrawRectangleT)_drawRectangle;
	pDebugDrawText = (DebugDrawTextT)_drawText;

	DebugFeatures features;
	features.debugAddress = true;
	features.debugFunction = true;
	features.savefileEditor = true;
	features.supervision = false;

	std::memcpy(_features, &features, sizeof(DebugFeatures));
}

EXTERN_DLL_EXPORT void OnFrameDebugMod()
{

	//
	// This function get's called every frame, as long as the debug menu isn't opened. It get's called, even if the TAS is playing / recording
	//

}

EXTERN_DLL_EXPORT void OnExitDebugMod()
{

	//
	// This function get's called when den debug mod get's ejected, clear buffers and stuff here
	//

}


