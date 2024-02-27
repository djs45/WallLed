//25
template<int tmpnote> void RandomRingLed() {
  int tmpTime = millis();
  if (tmpTime > oldTimeR + globSpeedR) {
    for (int s = 0; s < LetAtOnceR; s++) {
      ledsR[random8(NUM_LEDSR)].setHSV(gHue, 255, 255);
      // yield();
      // ledsLEGO[random8(NUM_LEDSLEGO)].setHSV(gHue, 255, 255);
    }
    oldTimeR = tmpTime;
  }
  yield();
  MIDInoteF[tmpnote] = 0;
}


//26
template<int tmpnote> void RandomLed() {
  int tmpTime = millis();
  if (tmpTime > oldTimeL + globSpeedL) {
    for (int s = 0; s < LetAtOnceL; s++) {
      if (autogHue == 0) {
      leds[random8(NUM_STRIPS)][random8(NUM_LEDS)].setHSV(gHue, 255, 255);
      }
      if (autogHue == 1) {
        leds[random8(NUM_STRIPS)][random8(NUM_LEDS)].setHSV(gHue + (s * 32), 255, 255);
      }
    }
    oldTimeL = tmpTime;
  }
  yield();
  MIDInoteF[tmpnote] = 0;
}