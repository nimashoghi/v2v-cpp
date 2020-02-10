#pragma once

#include <iostream>
#include <memory>
#include <thread>

// #include <ZXing/DecodeHints.h>
// #include <ZXing/TextUtfEncoding.h>
// #include <ZXing/GenericLuminanceSource.h>
// #include <ZXing/HybridBinarizer.h>
// #include <ZXing/MultiFormatReader.h>
// #include <ZXing/Result.h>
#include <ZXing/ReadBarcode.h>

#include "webcam.h"

using namespace std;

template <typename T>
inline auto barcode_main(T &&callback, const string &device = "/dev/video0", const chrono::duration<double> sleep_duration = 0.01s)
{
    auto webcam = Webcam(device);

    while (true)
    {
        const auto &frame = webcam.frame();

        // ZXing::GenericLuminanceSource source{frame.width, frame.height, frame.data, frame.width * 3, 3, 2, 1, 0};
        // ZXing::HybridBinarizer binImage(shared_ptr<ZXing::LuminanceSource>(&source, [](void *) {}));
        // ZXing::MultiFormatReader reader(ZXing::DecodeHints().setTryHarder(false).setTryRotate(true).setPossibleFormats({ZXing::BarcodeFormat::QR_CODE}).setCharacterSet("ASCII"));
        // auto barcode = reader.read(binImage);

        auto barcode = ZXing::ReadBarcode(frame.width, frame.height, frame.data, frame.width * 3, 3, 2, 1, 0, {ZXing::BarcodeFormat::QR_CODE}, true, false);
        if (barcode.isValid())
        {
            callback(barcode);
        }

        this_thread::sleep_for(sleep_duration);
    }
}
