#ifndef _M5DISPLAY_H_
#define _M5DISPLAY_H_

//#include <Arduino.h>
//#include <SPI.h>

#include <TFT_eSPI.h>

class M5Display : public TFT_eSPI {
   public:
    M5Display();
    void begin();

    void drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h,
                    const uint16_t *data);
    void drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h,
                    const uint8_t *data);
    void drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h,
                    uint16_t *data);
    void drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h,
                    uint8_t *data);
    void drawBitmap(int16_t x0, int16_t y0, int16_t w, int16_t h,
                    const uint16_t *data, uint16_t transparent);

    void qrcode(const char *string, uint16_t x = 5, uint16_t y = 45,
                uint8_t width = 70, uint8_t version = 7);
    void qrcode(const String &string, uint16_t x = 5, uint16_t y = 45,
                uint8_t width = 70, uint8_t version = 7);
 
};
#endif
