template<int tmpnote> void VUseg() {
  int tmpval = map(audioval[0], 0, 255, 0, 5);
  int tmpOfS = map(OffsetLed,0,127,0,11);
  for (int i = 0; i < tmpval; i++) {
    for (int j = 0; j < NUM_STRIPS; j = j + 2) {
      for (int k = 0; k < 4; k++) {
        int tmpl = (i + tmpOfS + 10 * k) % NUM_LEDS;
        int tmpl2 = abs((i - tmpOfS - 10 * (k+1))) % NUM_LEDS;

        leds[j][tmpl].setHSV(gHue, 255, 255);
        leds[j+1][40-tmpl].setHSV(gHue, 255, 255);

        leds[j][tmpl2].setHSV(gHue, 255, 255);
        leds[j+1][40-tmpl2].setHSV(gHue, 255, 255);
      }
    }
  }
  MIDInoteF[tmpnote] = 0;
}
