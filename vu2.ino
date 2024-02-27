//28
template<int tmpnote> void vu2() {
  int j = 0;
  int tmpval = map(audioval[0], 0, 255, 0, NUM_LEDS_HALF);
  uint8_t heatindex = (audioval[0]);
  bool usePal = 1;
  CRGBPalette16 myPal = CloudColors_p;
  switch (PotPal) {
    case 1: usePal = 0; break;
    case 2: myPal = VU_gp; break;
    case 3: myPal = RainbowColors_p; break;
    case 4: myPal = OceanColors_p; break;
    case 5: myPal = CloudColors_p; break;
    case 6: myPal = LavaColors_p; break;
    case 7: myPal = ForestColors_p; break;
    case 8: myPal = PartyColors_p; break;
  }
  // yield();
  for (int i = 0; i < tmpval; i++) {
    if (usePal == 0) {
      leds[j][i].setHSV(gHue, 255, 255);
      leds[j][NUM_LEDS - i - 1].setHSV(gHue, 255, 255);
      leds[j + 1][i].setHSV(gHue, 255, 255);
      leds[j + 1][NUM_LEDS - i - 1].setHSV(gHue, 255, 255);
    } else {
      leds[j][i] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
      leds[j][NUM_LEDS - i - 1] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
      leds[j + 1][i] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
      leds[j + 1][NUM_LEDS - i - 1] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
    }
  }
  // yield();
  j = 2;
  tmpval = map(audioval[3], 0, 255, 0, NUM_LEDS_HALF);
  for (int i = 0; i < tmpval; i++) {
    if (usePal == 0) {
      leds[j][i].setHSV(gHue, 255, 255);
      leds[j][NUM_LEDS - i - 1].setHSV(gHue, 255, 255);
      leds[j + 1][i].setHSV(gHue, 255, 255);
      leds[j + 1][NUM_LEDS - i - 1].setHSV(gHue, 255, 255);
    } else {
      leds[j][i] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
      leds[j][NUM_LEDS - i - 1] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
      leds[j + 1][i] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
      leds[j + 1][NUM_LEDS - i - 1] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
    }
  }
  // yield();
  j = 4;
  tmpval = map(audioval[5], 0, 255, 0, NUM_LEDS_HALF);
  for (int i = 0; i < tmpval; i++) {
    if (usePal == 0) {
      leds[j][i].setHSV(gHue, 255, 255);
      leds[j][NUM_LEDS - i - 1].setHSV(gHue, 255, 255);
      leds[j + 1][i].setHSV(gHue, 255, 255);
      leds[j + 1][NUM_LEDS - i - 1].setHSV(gHue, 255, 255);
    } else {
      leds[j][i] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
      leds[j][NUM_LEDS - i - 1] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
      leds[j + 1][i] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
      leds[j + 1][NUM_LEDS - i - 1] = ColorFromPalette(myPal, 255 / NUM_LEDS_HALF * i);
    }
  }
  // yield();
  MIDInoteF[tmpnote] = 0;
}