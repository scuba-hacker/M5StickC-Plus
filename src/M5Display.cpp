#include "M5Display.h"

M5Display::M5Display() : TFT_eSPI() {
}

void M5Display::begin()
{
  init();
  fillScreen(TFT_BLACK);
}

void M5Display::drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h,
                           const uint16_t *data) {
    setSwapBytes(true);
    pushImage((int32_t)x0, (int32_t)y0, (uint32_t)w, (uint32_t)h, data);
    setSwapBytes(false);
}

void M5Display::drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h,
                           uint16_t *data) {
    setSwapBytes(true);
    pushImage((int32_t)x0, (int32_t)y0, (uint32_t)w, (uint32_t)h, data);
    setSwapBytes(false);
}

void M5Display::drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h,
                           const uint16_t *data, uint16_t transparent) {
    setSwapBytes(true);
    pushImage((int32_t)x0, (int32_t)y0, (uint32_t)w, (uint32_t)h, data,
              transparent);
    setSwapBytes(false);
}

void M5Display::drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h,
                           const uint8_t *data) {
    setSwapBytes(true);
    pushImage((int32_t)x0, (int32_t)y0, (uint32_t)w, (uint32_t)h,
              (const uint16_t *)data);
    setSwapBytes(false);
}

void M5Display::drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h,
                           uint8_t *data) {
    setSwapBytes(true);
    pushImage((int32_t)x0, (int32_t)y0, (uint32_t)w, (uint32_t)h,
              (uint16_t *)data);
    setSwapBytes(false);
}

#include "utility/qrcode.h"
void M5Display::qrcode(const char *string, uint16_t x, uint16_t y,
                       uint8_t width, uint8_t version) {
    // Create the QR code
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(version)];
    qrcode_initText(&qrcode, qrcodeData, version, 0, string);

    // Top quiet zone
    uint8_t thickness   = width / qrcode.size;
    uint16_t lineLength = qrcode.size * thickness;
    uint8_t xOffset     = x + (width - lineLength) / 2;
    uint8_t yOffset     = y + (width - lineLength) / 2;
    fillRect(x, y, width, width, TFT_WHITE);

    for (uint8_t y = 0; y < qrcode.size; y++) {
        for (uint8_t x = 0; x < qrcode.size; x++) {
            uint8_t q = qrcode_getModule(&qrcode, x, y);
            if (q)
                fillRect(x * thickness + xOffset, y * thickness + yOffset,
                         thickness, thickness, TFT_BLACK);
        }
    }
}

void M5Display::qrcode(const String &string, uint16_t x, uint16_t y,
                       uint8_t width, uint8_t version) {
    int16_t len = string.length() + 1;
    char buffer[len];
    string.toCharArray(buffer, len);
    qrcode(buffer, x, y, width, version);
}

