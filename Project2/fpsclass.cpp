#include "fpsclass.h"

FpsClass::FpsClass()
{
}


FpsClass::FpsClass(const FpsClass& other)
{
}


FpsClass::~FpsClass()
{
}

void FpsClass::Initialize()
{
    m_fps = 0;
    m_count = 0;

    m_startTime = timeGetTime();

    return;
}

void FpsClass::Frame()
{
    m_count++;

    // 1초에 불려지는 Frame의 횟수를 기록
    if (timeGetTime() >= (m_startTime + 1000))
    {
        m_fps = m_count;
        m_count = 0;

        m_startTime = timeGetTime();
    }

    return;
}

int FpsClass::GetFps()
{
    return m_fps;
}