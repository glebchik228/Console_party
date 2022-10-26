#include <iostream>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "VecFunctions.h"

int main() {
    int width = 192;
    int height = 51;
    long long t = 0;
    float aspect = (float) width / height;
    float pixelAspect = 11.0 / 24.0;
    char gradient[] = " `.',:^;*!/r(?+cL7t1zfJCF3S2Zk5AXG8#%RNBM&Q@";
//    char gradient[] = " .:!/r(l1Z4H9W8$@";
    int gradientSize = sizeof(gradient) - 2;

    char *screen = new char[width * height];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    while (true) {
        t++;
        vec3 light = norm(vec3(sin(t * 0.005), cos(t * 0.005), -0.5));
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                vec2 uv = vec2(i, j) / vec2(width, height) * 2.0f - 1;
                uv.x *= aspect * pixelAspect;
                vec3 ro = vec3(-2, 0, 0);
                vec3 rd = norm(vec3(1, uv));
                char pixel = ' ';
                int color = 0;
                vec2 intersection = sphere(ro, rd, 1);
                if (intersection.x > 0) {
                    vec3 itPoint = ro + rd * intersection.x;
                    vec3 n = norm(itPoint);
                    float diff = dot(n, light);
                    color = (int)(diff * 45);
                }
                color = clamp(color, 0, gradientSize);
                pixel = gradient[color];
                screen[i + j * width] = pixel;
            }
        }
        screen[width * height - 1] = '\0';
        WriteConsoleOutputCharacter(hConsole, reinterpret_cast<LPCSTR>(screen), width * height, {0, 0},&dwBytesWritten);
    }
}