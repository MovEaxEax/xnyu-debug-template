#pragma once

typedef void(__stdcall* DebugConsoleOutputT)(std::string text, bool dev, std::string color);
DebugConsoleOutputT pDebugConsoleOutput = nullptr;

typedef void(__stdcall* DebugDrawRectangleT)(int x, int y, int w, int h, unsigned char* color, float alpha);
DebugDrawRectangleT pDebugDrawRectangle = nullptr;

typedef void(__stdcall* DebugDrawTextT)(int x, int y, int w, int h, unsigned char* color, float alpha);
DebugDrawTextT pDebugDrawText = nullptr;

