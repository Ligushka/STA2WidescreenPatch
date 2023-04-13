// armada2_patch.cpp
//
// Author: Ligushka
//
// An ASI patch for Star Trek™: Armada II (2001) which automatically expands
// resolution support to include your monitor's current modern widescreen
// resolution which is not supported by the original game.
// 
// Compatible with Star Trek™: Armada II 1.0, patch 1.1, GOG.com version,
// Star Trek™: Armada II Patch Project 1.2.5, and any compatible version
// combined with a DirectX wrapper such as dxwrapper or d3d8to9.
//
// Homepage: https://github.com/Ligushka/STA2WidescreenPatch
//
// This patch was inspired by and made possible thanks to the excellent video tutorial
// for patching Roller Coaster Tycoon (1999) by jeFF0Falltrades: https://youtu.be/cwBoUuy4nGc
// 
// This patch also utilizes "Ultimate ASI Loader" by ThirteenAG,
// under MIT License Copyright (c) 2018 ThirteenAG.
// https://github.com/ThirteenAG/Ultimate-ASI-Loader
//
// MIT License
//
// Copyright (c) 2023 Ligushka
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <Windows.h>
#include <iostream>

enum {
    VERSION10 = 10,
    VERSION11 = 11,
    VERSIONDEMO = 00
};

// Function to convert integer to little-endian hexadecimal format
void intToLittleEndianHex(int val, char* hex) {
    hex[0] = (val & 0xFF);
    hex[1] = (val >> 8) & 0xFF;
}

// Function to check memory address to determine which game version we're using
int checkVersion()
{
    const char* memoryLocation = (const char*)0x622BBA;     // compare the first memory address we are going to patch
    const char version10Byte = (unsigned char)0x45;         // default value pre-patch for version 1.0
    const char version11Byte = (unsigned char)0xC0;         // default value pre-patch for version 1.1
    const char versionDemoByte = (unsigned char)0x00;       // default value pre-patch for the demo version

    if (*memoryLocation == version10Byte)
    {
        return VERSION10; // we are using version 1.0
    }
    else if (*memoryLocation == version11Byte)
    {
        return VERSION11; // we are using version 1.1
    }
    else if (*memoryLocation == versionDemoByte)
    {
        return VERSIONDEMO; // we are using the demo version
    }
    else
    {
        return 0;
    }
}

// Function to replace value at memory address with given value
void replaceMemoryAddressValue(void* address, void* value, size_t size) {
    DWORD oldProtect;
    VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);
    memcpy(address, value, size);
    VirtualProtect(address, size, oldProtect, &oldProtect);
}

// Entry point for DLL
BOOL APIENTRY DllMain(HMODULE, DWORD ul_reason_for_call, LPVOID) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    {
        // Get current screen resolution of the desktop
        int g_screenWidth = GetSystemMetrics(SM_CXSCREEN);
        int g_screenHeight = GetSystemMetrics(SM_CYSCREEN);

        // Convert screen resolution to little-endian hexadecimal
        char hex_screenWidth[2];
        intToLittleEndianHex(g_screenWidth, hex_screenWidth);
        char hex_screenHeight[2];
        intToLittleEndianHex(g_screenHeight, hex_screenHeight);

        // replace 1280 x 960 resolution's memory addresses with the current desktop screen resolution
        // so when the game looks for a supported resolution, it finds that instead of 1280 x 960
        // and the desktop screen resolution appears in the Graphics Options dropdown list

        switch (checkVersion())
        {
        case VERSION10:
            replaceMemoryAddressValue((void*)0x615341, hex_screenHeight, sizeof(hex_screenHeight));
            replaceMemoryAddressValue((void*)0x615346, hex_screenWidth, sizeof(hex_screenWidth));
            replaceMemoryAddressValue((void*)0x6150CF, hex_screenWidth, sizeof(hex_screenWidth));
            replaceMemoryAddressValue((void*)0x6150D9, hex_screenHeight, sizeof(hex_screenHeight));
            break;
        case VERSION11:
            replaceMemoryAddressValue((void*)0x622BBA, hex_screenHeight, sizeof(hex_screenHeight));
            replaceMemoryAddressValue((void*)0x622BB0, hex_screenWidth, sizeof(hex_screenWidth));
            replaceMemoryAddressValue((void*)0x622E24, hex_screenWidth, sizeof(hex_screenWidth));
            replaceMemoryAddressValue((void*)0x622E1F, hex_screenHeight, sizeof(hex_screenHeight));
            break;
        case VERSIONDEMO:
            replaceMemoryAddressValue((void*)0x617679, hex_screenHeight, sizeof(hex_screenHeight));
            replaceMemoryAddressValue((void*)0x61766F, hex_screenWidth, sizeof(hex_screenWidth));
            replaceMemoryAddressValue((void*)0x617877, hex_screenWidth, sizeof(hex_screenWidth));
            replaceMemoryAddressValue((void*)0x617872, hex_screenHeight, sizeof(hex_screenHeight));
            break;
        default:
            break;
        }
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
