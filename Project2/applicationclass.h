////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <windows.h>

//////////////////////
// MY CLASS INCLUDE //
//////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "fontshaderclass.h"
#include "fontclass.h"
#include "textclass.h"
#include "fpsclass.h"


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = false;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.3f;

////////////////////////////////////////////////////////////////////////////////
// Class name: ApplicationClass
////////////////////////////////////////////////////////////////////////////////
class ApplicationClass
{
public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass&);
	~ApplicationClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();
	bool UpdateFps();

private:
	bool Render();

private:
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	FontShaderClass* m_FontShader;
	FontClass* m_Font;
	FpsClass* m_Fps;
	TextClass* m_FpsString;
	int m_previousFps;
};

#endif