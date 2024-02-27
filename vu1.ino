//27
template<int tmpnote> void vu1() {
  int tmpval = map(audioval[0], 0, 255, 0, NUM_LEDSR);
  for (int i = 0; i < tmpval / 4; i++) {
    ledsR[i].setHSV(gHue, 255, 255);
    ledsR[NUM_LEDSR - i].setHSV(gHue, 255, 255);
    ledsR[i + NUM_LEDSR / 2].setHSV(gHue, 255, 255);
    ledsR[NUM_LEDSR / 2 - i].setHSV(gHue, 255, 255);
  }
  // yield();
  MIDInoteF[tmpnote] = 0;
}

//40
template<int tmpnote> void VUp3() {
  int tmpval = map(audiovalP[0], 0, 255, 0, NUM_LEDS-1);
  for (int j = 0; j < 6; j++) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[j][tmpval].setHSV(gHue, 255, 255);
  }
  // yield();
  MIDInoteF[tmpnote] = 0;
}