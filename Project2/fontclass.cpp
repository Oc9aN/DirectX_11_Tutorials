#include "fontclass.h"

FontClass::FontClass()
{
    m_Font = 0;
    m_Texture = 0;
}


FontClass::FontClass(const FontClass& other)
{
}


FontClass::~FontClass()
{
}

bool FontClass::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, int fontChoice)
{
    char fontFilename[128];
    char fontTextureFilename[128];
    bool result;

    // Choose one of the available fonts, and default to the first font otherwise.
    switch (fontChoice)
    {
    case 0:
    {
        strcpy_s(fontFilename, "../Engine/data/font/font01.txt");
        strcpy_s(fontTextureFilename, "../Engine/data/font/font01.tga");
        m_fontHeight = 32.0f;
        m_spaceSize = 3;
        break;
    }
    default:
    {
        strcpy_s(fontFilename, "../Engine/data/font/font01.txt");
        strcpy_s(fontTextureFilename, "../Engine/data/font/font01.tga");
        m_fontHeight = 32.0f;
        m_spaceSize = 3;
        break;
    }
    }

    // Load in the text file containing the font data.
    result = LoadFontData(fontFilename);
    if (!result)
    {
        return false;
    }

    // Load the texture that has the font characters on it.
    result = LoadTexture(device, deviceContext, fontTextureFilename);
    if (!result)
    {
        return false;
    }

    return true;
}