#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>
//#include "VecFunctions.h"

int main(){
    int width = 192;
    int height = 51;
    int t = 0;
    float aspect = (float) width / height;
    float pixelAspect = 11.0 / 24.0;
    char gradient[] = " .a@";
    int gradientSize = std::size_t(gradient) - 2;

    char * screen = new char [width * height];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;


    while (true) {
        t++;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                float x = (float) i / width * 2.0 - 1.0;
                float y = (float) j / height * 2.0 - 1.0;
                x *= aspect * pixelAspect;
                x += sin(t * 0.01f);
                y += 0.5f * cos(t * 0.05f);
                char pixel = ' ';
                float dist = sqrt(x * x + y * y);
                if (dist < 0.5f)
                    pixel = gradient[1];
                if (dist < 0.3f)
                    pixel = gradient[2];
                if (dist < 0.2f)
                    pixel = gradient[3];
                screen[i + j * width] = pixel;

            }
        }
        screen[width * height - 1] = '\0';
        WriteConsoleOutputCharacter(hConsole, reinterpret_cast<LPCSTR>(screen), width * height, {0, 0 }, &dwBytesWritten);
    }
}