#include <DxLib.h>
#include <float.h>
#include "../Library/Time.h"
#include "MouseUtility.h"
#include <corecrt_math.h>

namespace MouseBuffer
{
    static const float REPEAT_TIME = 0.5f;
    static bool triggerBuffer[3];
    static float repeatBuffer[3];
}


static int ConvertButton(int mouseButton)
{
    switch (mouseButton)
    {
    case MOUSE_INPUT_LEFT:
        return 0;

    case MOUSE_INPUT_RIGHT:
        return 1;

    case MOUSE_INPUT_MIDDLE:
        return 2;
    }

    return -1;
}

void MouseUtility::Init()
{
    for (int i = 0; i < 3; i++)
    {
        MouseBuffer::triggerBuffer[i] = false;
        MouseBuffer::repeatBuffer[i] = 0.0f;
    }
}

bool MouseUtility::CheckTrigger(int mouseButton)
{
    int id = ConvertButton(mouseButton);
    if (id == -1)
        return false;

    bool trigger = false;

    if (GetMouseInput() & mouseButton)
    {
        if (!MouseBuffer::triggerBuffer[id])
        {
            trigger = true;
        }

        MouseBuffer::triggerBuffer[id] = true;
    }
    else
    {
        MouseBuffer::triggerBuffer[id] = false;
    }

    return trigger;
}

bool MouseUtility::CheckRepeat(int mouseButton)
{
    int id = ConvertButton(mouseButton);
    if (id == -1)
        return false;

    bool repeat = false;

    if (GetMouseInput() & mouseButton)
    {
        if (fabs(MouseBuffer::repeatBuffer[id]) < DBL_EPSILON)
        {
            MouseBuffer::repeatBuffer[id] = Time::DeltaTime();
            repeat = true;
        }
        else
        {
            MouseBuffer::repeatBuffer[id] += Time::DeltaTime();

            if (MouseBuffer::repeatBuffer[id] >= MouseBuffer::REPEAT_TIME)
            {
                repeat = true;

                // éüÇÃÉäÉsÅ[ÉgÇ‹Ç≈ë“Ç¬
                MouseBuffer::repeatBuffer[id] = 0.0f;
            }
        }
    }
    else
    {
        MouseBuffer::repeatBuffer[id] = 0.0f;
    }

    return repeat;
}