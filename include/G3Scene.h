#pragma once
#include <memory>
#include <citro2d.h>

class G3Scene
{
private:
    int init();
    u32 m_temp_color{};
    G3Scene(u32 temp_color): m_temp_color{temp_color}{};
public:
    static G3Scene *create(u32 c);

    void update();
    void drawTop();
    void drawBottom();
};
