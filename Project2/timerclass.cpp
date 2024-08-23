#include "timerclass.h"


TimerClass::TimerClass()
{
}


TimerClass::TimerClass(const TimerClass& other)
{
}


TimerClass::~TimerClass()
{
}

bool TimerClass::Initialize()
{
    INT64 frequency;


    // Get the cycles per second speed for this system.
    // ���� ���� �Լ�
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    if (frequency == 0)
    {
        return false;
    }

    // Store it in floating point.
    m_frequency = (float)frequency;

    // Get the initial start time.
    // ���� ������ �ð�
    QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);

    return true;
}

void TimerClass::Frame()
{
    INT64 currentTime;
    INT64 elapsedTicks;


    // Query the current time.
    // �������� ���۵ɶ��� Ŭ�� ��
    QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

    // Calculate the difference in time since the last time we queried for the current time.
    // ���� �����Ӱ� ���� �������� Ŭ�� �� 
    elapsedTicks = currentTime - m_startTime;

    // Calculate the frame time.
    // ������ ������ Ŭ�� �� ���̸� ���ļ��� ����� ������ ������ second�� ����
    m_frameTime = (float)elapsedTicks / m_frequency;

    // Restart the timer.
    m_startTime = currentTime;

    return;
}

float TimerClass::GetTime()
{
    return m_frameTime;
}