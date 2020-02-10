#include <iostream>
#include <locale>
#include <codecvt>
#include <chrono>
#include <fstream>

#include <ZXing/ReadBarcode.h>
#include <ZXing/TextUtfEncoding.h>

#include "barcode_reader.hpp"

using namespace std;

auto detected(const std::vector<char> &bytesChar)
{
}

int main(int argc, char *argv[])
{
    barcode_main([](ZXing::Result barcode) {
        ofstream out{"./public.bin", ios::binary | ios::out};

        vector<char> bytesChar;
        auto bytes = barcode.text();
        for (auto byte : bytes)
        {
            bytesChar.push_back((char)byte);
        }

        detected(bytesChar);
    });
}
