template<int tmpnote> void vu4() {
  int tmpval = map(audioval[0], 0, 255, 0, 47);  //tmpval 0 to 81
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
    if (i >= 0 && i <= 14) {
      leds[3][40].setHSV(gHue, 255, 255);
      leds[2][40].setHSV(gHue, 255, 255);
      leds[3][i].setHSV(gHue, 255, 255);
      leds[3][39 - i].setHSV(gHue, 255, 255);
      leds[2][i].setHSV(gHue, 255, 255);
      leds[2][39 - i].setHSV(gHue, 255, 255);
    }
    if (i == 15) {
      for (int j = 15; j <= 24; j++) {
        leds[3][j].setHSV(gHue, 255, 255);
        leds[2][j].setHSV(gHue, 255, 255);
      }
    }
    if (i == 16) {
      for (int j = 15; j <= 24; j++) {
        leds[4][j].setHSV(gHue, 255, 255);
        leds[1][j].setHSV(gHue, 255, 255);
      }
    }
    if (i >= 17 && i <= 31) { ///////////////////////////////////// A VERIFIER
      // leds[4][40].setHSV(gHue, 255, 255);
      // leds[1][40].setHSV(gHue, 255, 255);
      leds[4][i - 17 + 26].setHSV(gHue, 255, 255);
      leds[4][31 - i].setHSV(gHue, 255, 255);
      leds[1][i - 17 + 26].setHSV(gHue, 255, 255);
      leds[1][31 - i].setHSV(gHue, 255, 255);
    }
    if (i >= 32 && i <= 46) {
      leds[5][40].setHSV(gHue, 255, 255);
      // leds[5][41].setHSV(gHue, 255, 255);
      leds[0][40].setHSV(gHue, 255, 255);
      // leds[0][41].setHSV(gHue, 255, 255);
      leds[5][i - 32].setHSV(gHue, 255, 255);
      leds[5][39 - i + 32].setHSV(gHue, 255, 255);
      leds[0][i - 32].setHSV(gHue, 255, 255);
      leds[0][39 - i + 32].setHSV(gHue, 255, 255);
    }
    if (i >= 46) {
      for (int j = 15; j <= 24; j++) {
        leds[5][j].setHSV(gHue, 255, 255);
        leds[0][j].setHSV(gHue, 255, 255);
      }
    }
  }
  MIDInoteF[tmpnote] = 0;
}