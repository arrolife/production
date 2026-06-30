#pragma once

class MouseUtility
{
public:
    static void Init();
    static bool CheckTrigger(int mouseButton);
    static bool CheckRepeat(int mouseButton);
};