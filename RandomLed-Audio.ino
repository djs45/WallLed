//30
template<int tmpnote> void RandomLedAudio() {
  readMSGEQ7();
  int tmpval = map(audioval[0], 0, 255, 0, NUM_LEDSR);
  if (tmpval > 127) {
    for (int j = 0; j < NUM_STRIPS; j++) {
      fill_solid(leds[j], NUM_LEDS, CHSV(gHue, 255, 255));
      // leds[j][random8(NUM_LEDS)].setHSV(tmpval, 255, 255);
    }

    fill_solid(ledsR, NUM_LEDSR, CHSV(gHue, 255, 255));
    fill_solid(ledsLEGO, NUM_LEDSLEGO, CRGB::White);
    // ledsR[random8(NUM_LEDSR)].setHSV(tmpval, 255, 255);
  }
  yield();
  MIDInoteF[tmpnote] = 0;
}