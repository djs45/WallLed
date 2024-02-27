template<int tmpnote> void vu5() {
  int tmpval = map(audioval[0], 0, 255, 0, 105);  //105
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
    if (i == 0) {
      for (int j = 19; j <= 24; j++) { leds[0][j].setHSV(gHue, 255, 255); }
      for (int j = 15; j <= 19; j++) { leds[5][j].setHSV(gHue+127, 255, 255); }
    }
    if (i > 0 && i <= 16) {
      leds[0][i + 24].setHSV(gHue, 255, 255);
      leds[5][16 - i].setHSV(gHue+127, 255, 255);
    }
    if (i > 16 && i <= 32) {
      leds[1][41 - i + 16].setHSV(gHue, 255, 255);
      leds[4][i - 17].setHSV(gHue+127, 255, 255);
    }
    if (i == 33) {
      for (int j = 19; j <= 24; j++) { leds[1][j].setHSV(gHue, 255, 255); }
      for (int j = 15; j <= 19; j++) { leds[4][j].setHSV(gHue+127, 255, 255); }
    }
    if (i == 34) {
      for (int j = 19; j <= 24; j++) { leds[2][j].setHSV(gHue, 255, 255); }
      for (int j = 15; j <= 19; j++) { leds[3][j].setHSV(gHue+127, 255, 255); }
    }
    if (i > 35 && i <= 51) {
      leds[2][i + 24 - 35].setHSV(gHue, 255, 255);
      leds[3][51 - i].setHSV(gHue+127, 255, 255);
    }
    //
    if (i > 52 && i <= 68) {
      leds[3][41 - i + 52].setHSV(gHue, 255, 255);
      leds[2][i - 53].setHSV(gHue+127, 255, 255);
    }
    if (i == 69) {
      for (int j = 19; j <= 24; j++) { leds[3][j].setHSV(gHue, 255, 255); }
      for (int j = 15; j <= 19; j++) { leds[2][j].setHSV(gHue+127, 255, 255); }
    }
    if (i == 70) {
      for (int j = 19; j <= 24; j++) { leds[4][j].setHSV(gHue, 255, 255); }
      for (int j = 15; j <= 19; j++) { leds[1][j].setHSV(gHue+127, 255, 255); }
    }
    if (i > 71 && i <= 87) {
      leds[4][i + 24 - 71].setHSV(gHue, 255, 255);
      leds[1][87 - i].setHSV(gHue+127, 255, 255);
    }
    if (i > 87 && i <= 103) {
      leds[5][41 - i + 87].setHSV(gHue, 255, 255);
      leds[0][i - 88].setHSV(gHue+127, 255, 255);
    }
    if (i > 103) {
      for (int j = 19; j <= 24; j++) { leds[5][j].setHSV(gHue, 255, 255); }
      for (int j = 15; j <= 19; j++) { leds[0][j].setHSV(gHue+127, 255, 255); }
    }
  }
  MIDInoteF[tmpnote] = 0;
}