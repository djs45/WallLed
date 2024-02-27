template<int tmpnote> void VUring() {
  int tmpval = audioval[0];
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
  for (int i = 0; i < NUM_LEDS; i++) {
    for (int j = 0; j < NUM_STRIPS; j=j+2) {
      if (usePal == 0) {
        leds[j][i].setHSV(gHue, tmpval, tmpval);
        leds[j+1][i].setHSV(gHue, tmpval, tmpval);
      } else {
        leds[j][i] = ColorFromPalette(myPal, ((255/(NUM_LEDS))*i) - (tmpval*2/map(OffsetLed,0,127,1,20)),tmpval);
        leds[j+1][abs(i-40)] = ColorFromPalette(myPal, ((255/(NUM_LEDS))*i) - (tmpval*2/map(OffsetLed,0,127,1,20)),tmpval);
      }
    }
  }
  MIDInoteF[tmpnote] = 0;
}