#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <d3dcompiler.h>
#include <string>
#include <tuple>
#include <windows.h>
#include <d3d11.h>
using namespace std;
bool SaveDataToFile(const string& filePath,
    const D3D11_TEXTURE2D_DESC& textureDesc,
    const D3D11_MAPPED_SUBRESOURCE& mappedTexture)
{
    ofstream file(filePath, ofstream::binary);
    bool result = file.good();

    // Configures bitmap file header and writes to file.
    BITMAPFILEHEADER fileHeader = { 'MB', 0, 0, 0, 0 };
    UINT width = textureDesc.Width;
    UINT height = textureDesc.Height;
    UINT pixelDataSize = 4 * width * height;
    fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + pixelDataSize;
    fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    if (result)
    {
        file.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
        result = file.good();
    }

    // Configures bitmap info header and writes to file
    BITMAPINFOHEADER infoHeader = { 40, 1, 1, 1, 8, 0, 0, 0, 0, 0, 0 };
    infoHeader.biWidth = width;
    infoHeader.biHeight = -1 * height;
    infoHeader.biBitCount = 32;
    infoHeader.biCompression = BI_RGB;
    infoHeader.biXPelsPerMeter = 1000;
    infoHeader.biYPelsPerMeter = 1000;
    if (result)
    {
        file.write(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
        result = file.good();
    }

    if (result)
    {
        char* pixelRow = static_cast<char*>(mappedTexture.pData);
        UINT rowPitch = mappedTexture.RowPitch;
        char swappedPixel[4] = { 0 };
        for (UINT i = 0; i < height; ++i)
        {
            char* currentPixel = pixelRow;
            for (UINT j = 0; j < width; ++j)
            {
                swappedPixel[0] = currentPixel[2];
                swappedPixel[1] = currentPixel[1];
                swappedPixel[2] = currentPixel[0];
                swappedPixel[3] = currentPixel[3];
                file.write(swappedPixel, 4);
                currentPixel += 4;
            }
            pixelRow += rowPitch;
        }
        result = file.good();
    }

    file.close();
    return result;
}
