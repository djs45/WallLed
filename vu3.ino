template<int tmpnote> void vu3() {
  int tmpval = map(audioval[0], 0, 255, 0, (NUM_LEDS * 2) - 1);  //tmpval 0 to 81
  int tmpval2 = map(audioval[0], 0, 255, 0, NUM_LEDSR  - 1);
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
  for (int i = 0; i < tmpval; i++) {
    if (i <= 40) {
      for (int j = 0; j < NUM_STRIPS; j = j + 2) {
        if (usePal == 0) {
          leds[j][i].setHSV(gHue, 255, 255);
        } else {
          leds[j][i] = ColorFromPalette(myPal, (255 / (NUM_LEDS * 2)) * i);
        }
      }
    }
    if (i > 40) {
      for (int j = 1; j < NUM_STRIPS; j = j + 2) {
        if (usePal == 0) {
          leds[j][NUM_LEDS * 2 - i - 1].setHSV(gHue, 255, 255);
        } else {
          leds[j][NUM_LEDS * 2 - i - 1] = ColorFromPalette(myPal, (255 / (NUM_LEDS * 2)) * i);
        }
      }
    }
  }
  for (int i = 0; i < tmpval2; i++) {
    if (usePal == 0) {
      ledsR[i].setHSV(gHue, 255, 255);
    } else {
      ledsR[i] = ColorFromPalette(myPal, (255 / NUM_LEDSR) * i);
    }
  }
    MIDInoteF[tmpnote] = 0;
}