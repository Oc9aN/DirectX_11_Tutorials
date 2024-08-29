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
#include "inputclass.h"


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
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
	bool Frame(InputClass*);
	bool UpdateFps();

private:
	bool Render();
	bool UpdateMouseStrings(int, int, bool);
	bool UpdateKeyboardStrings(InputClass*);

private:
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	FontShaderClass* m_FontShader;
	FontClass* m_Font;
	FpsClass* m_Fps;
	TextClass* m_FpsString;
	int m_previousFps;
	TextClass* m_MouseStrings;
	TextClass* m_KeyboardString;
};

#endif