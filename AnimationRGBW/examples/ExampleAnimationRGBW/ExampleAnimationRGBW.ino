#include <Adafruit_NeoPixel.h>
#include <AnimationRGBW.h>

#define MAX_BRIGHTNESS 255
#define MAX_TIME 750
#define NUMPIXELS 24
#define PIN_OF_RING 2

long actualSeconds = 0;
long actualTime = 0;
long offsetActualSeconds = 0;
byte brightnessOfColor = 0;

//Ciração dos objetos para as cores RGB
AnimationRGBW animationHandlerRed = AnimationRGBW();
AnimationRGBW animationHandlerGreen = AnimationRGBW();
AnimationRGBW animationHandlerBlue = AnimationRGBW();
//Criação do objeto para op anel de leds
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN_OF_RING, NEO_GRB + NEO_KHZ800);

void setup()
{
    pixels.begin();
}

void loop()
{
    actualTime = millis();
    if (actualTime < (MAX_TIME + offsetActualSeconds))
    {
        actualSeconds = actualTime - offsetActualSeconds;
    }
    else
    {
        offsetActualSeconds += MAX_TIME;
        actualSeconds = actualTime - offsetActualSeconds;
    }

    brightnessOfColor = animationHandlerRed.pulseColor(MAX_TIME, actualSeconds, MAX_BRIGHTNESS);
    pixels.setPixelColor(0, brightnessOfColor, 0, 0); 
    brightnessOfColor = animationHandlerGreen.pulseColor(MAX_TIME, actualSeconds, MAX_BRIGHTNESS);
    pixels.setPixelColor(1, 0, brightnessOfColor, 0); 
    brightnessOfColor = animationHandlerBlue.pulseColor(MAX_TIME, actualSeconds, MAX_BRIGHTNESS);
    pixels.setPixelColor(2, 0, 0, brightnessOfColor); 
    pixels.show();                                        
}
