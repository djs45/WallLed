#define MIDIrcvDEBUG 0 // Display Midi messages INPUT in terminal
#define bpmDEBUG 1 // Dispplay BPM in terminal

// #include "MIDIUSB.h" // To test with Ableton // NOT WORKING

#include <FastLED.h>
#include <Scheduler.h>
#include <DueFlashStorage.h>
DueFlashStorage dueFlashStorage;

#include <usbh_midi.h>
#ifndef ARDUINO_SAM_DUE
#include <usbhub.h>
#endif

#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif

USB Usb;
USBH_MIDI Midi(&Usb);

void MIDI_poll();
void doDelay(unsigned long t1, unsigned long t2, unsigned long delayTime);

boolean bFirst;
uint16_t pid, vid;

bool MIDInote[127];
bool MIDInoteF[127];

#define NUM_STRIPS 6
#define NUM_LEDS 41
#define NUM_LEDS_HALF 20
#define NUM_LEDSR 211
#define NUM_LEDSLEGO 52
#define BRIGHTNESS 255
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB  //RGB
CRGB leds[NUM_STRIPS][NUM_LEDS];
CRGB ledsR[NUM_LEDSR];
CRGB ledsLEGO[NUM_LEDSLEGO];

uint8_t gHue = 171;     // Default Color
uint8_t gHueDelta = 3;  //3
bool autogHue = 1;
bool BtShift = 0;
byte  FTB1 = 20;
byte  FTB2 = 20;
unsigned long BPMtime; // unsigned long
unsigned long oldBPMtime; // unsigned long
byte audiovalPi = 0;
byte audiovalPt = 0;
byte tmpaudiovalP = 0;
float BPM = 120; // int
byte  LetAtOnceR = 8;
byte  LetAtOnceL = 8;
int globSpeedR = 100;
int oldTimeR = millis();
int globSpeedL = 100;
int oldTimeL = millis();
int globSpeedgHue = 300;
int oldTimegHue = millis();
byte PotPal = 1;
int OffsetLed;

#include "MSGEQ7.h"
byte  audioval[6]; // int
byte  audiovalP[6]; //int
#define pinAnalogAudio A5
#define pinReset 15
#define pinStrobe 14
#define MSGEQ7_SMOOTH false
//#define MSGEQ7_SMOOTH 191 // Range: 0-255

CMSGEQ7<MSGEQ7_SMOOTH, pinReset, pinStrobe, pinAnalogAudio> MSGEQ7;

DEFINE_GRADIENT_PALETTE(VU_gp){
  0, 0, 255, 0,
  130, 0, 255, 0,
  131, 255, 0, 0,
  255, 255, 0, 0
};
DEFINE_GRADIENT_PALETTE(test_gp){
  0, 0, 255, 0,
  127, 255, 0, 0,
  255, 0, 0, 255
};
DEFINE_GRADIENT_PALETTE( heatmap_gp ) {
  0,     0,  0,  0,   //black
128,   255,  0,  0,   //red
224,   255,255,  0,   //bright yellow
255,   255,255,255 }; //full white
// CRGBPalette16 myPal = heatmap_gp;

void setup() {
  SetupINO();
}

void FTBall(int sp, int sp2) {
  if (MIDInote[21] == 0) {
    if (sp == -1) {
      FastLED.clear();
    } else {
      for (int st2 = 0; st2 < NUM_STRIPS; st2++) {
        fadeToBlackBy(leds[st2], NUM_LEDS, sp);
      }
      fadeToBlackBy(ledsR, NUM_LEDSR, sp2);
      fadeToBlackBy(ledsLEGO, NUM_LEDSLEGO, sp2);
    }
  }
}

void AutoGHUE() {
  if (autogHue == 1) {
    if (millis() > oldTimegHue + globSpeedgHue) {
      gHue += gHueDelta;
      oldTimegHue = millis();
    }
  }
  yield();
}

void loop() {
  readMSGEQ7();
  FastLED.show();
  FTBall(FTB1, FTB2);
  yield();
}
