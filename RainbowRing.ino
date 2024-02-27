template<int tmpnote> void RainbowRing()
{
  // printf(tmpnote);
  for (int led = 0; led < NUM_LEDSR; led = led + LetAtOnceL) {
    for (int i = 0; i < LetAtOnceR + 1; i++) {
      if (led + i < NUM_LEDSR) {
        ledsR[led + i].setHSV(gHue, 255, 255);
      }
      if (NUM_LEDSR - led - i > -1) {
        ledsR[NUM_LEDSR - led - i].setHSV(gHue, 255, 255);
      }
    }
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    yield();
  }
  MIDInoteF[tmpnote] = 0;
}