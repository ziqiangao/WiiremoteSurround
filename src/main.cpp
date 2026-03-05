#include "testwav.h"
#include <wiiuse/wpad.h>
#include <stdio.h>
#include <gccore.h>
#include <grrlib.h>
#include <vector>

void drawwaveform(const std::vector<s16> &wave, f32 x, f32 y, f32 w, f32 h) {
    if (wave.empty()) return;

    u16 size = wave.size();
    f32 step = w / size;             // horizontal spacing per sample
    f32 midY = y + h / 2.0f;         // vertical center of the waveform

    for (u16 i = 0; i < size - 1; i++) {
        // scale samples to fit in [-h/2, h/2]
        f32 y1 = midY - ((f32)wave[i] / 32768.0f) * (h / 2.0f);
        f32 y2 = midY - ((f32)wave[i + 1] / 32768.0f) * (h / 2.0f);

        f32 x1 = x + i * step;
        f32 x2 = x + (i + 1) * step;

        GRRLIB_Line(x1, y1, x2, y2, 0xFFFFFFFF);
    }
}

int main()
{
    GRRLIB_Init();
    while (1) {

    GRRLIB_FillScreen(0x000000FF);

    GRRLIB_Line(50, 50, 200, 200, 0xFFFFFFFF);
    GRRLIB_Line(200, 50, 50, 200, 0xFF0000FF);

    GRRLIB_Render();
}
    return 0;
}
