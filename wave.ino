//31
template<int tmpnote> void wave() {
  int speed = globSpeedL;// BPM / 2;
  // CRGB couleur = CRGB::Crimson;
  CRGB couleur = CRGB::Blue;
  uint8_t beat1 = beatsin8(speed, 0, NUM_LEDS, 0, 0);
  uint8_t beat2 = beatsin8(speed, 0, NUM_LEDS, 0, 0); //64
  uint8_t beat3 = beatsin8(speed, 0, NUM_LEDS, 0, 0); //64
  uint8_t beat4 = beatsin8(speed, 0, NUM_LEDSR, 0, 0);

  leds[0][NUM_LEDS / 2 + beat1 / 2] = couleur;
  leds[0][NUM_LEDS / 2 - beat1 / 2] = couleur;
  leds[5][NUM_LEDS / 2 + beat1 / 2] = couleur;
  leds[5][NUM_LEDS / 2 - beat1 / 2] = couleur;
  leds[1][NUM_LEDS / 2 + beat2 / 2] = couleur;
  leds[1][NUM_LEDS / 2 - beat2 / 2] = couleur;
  leds[4][NUM_LEDS / 2 + beat2 / 2] = couleur;
  leds[4][NUM_LEDS / 2 - beat2 / 2] = couleur;
  leds[2][NUM_LEDS / 2 + beat3 / 2] = couleur;
  leds[2][NUM_LEDS / 2 - beat3 / 2] = couleur;
  leds[3][NUM_LEDS / 2 + beat3 / 2] = couleur;
  leds[3][NUM_LEDS / 2 - beat3 / 2] = couleur;

  ledsR[NUM_LEDSR / 2 + beat4 / 2] = couleur;
  ledsR[NUM_LEDSR / 2 - beat4 / 2] = couleur;

  yield();
  MIDInoteF[tmpnote] = 0;
}

//38
template<int tmpnote> void wave2() {
  readMSGEQ7();
  ledsR[1].setHSV(gHue, 255, audioval[0]);
  ledsR[NUM_LEDSR].setHSV(gHue, 255, audioval[0]);
  for (int i = NUM_LEDSR / 2; i > 0; i--) {
    ledsR[i] = ledsR[i - 1];
  }
  for (int i = NUM_LEDSR / 2 + 1; i < NUM_LEDSR; i++) {
    ledsR[i] = ledsR[i + 1];
  }
  for (int j = 0; j < 6; j++) {
    leds[j][0].setHSV(gHue, 255, audioval[0]);
    for (int i = NUM_LEDS - 1; i > 0; i--) {
      leds[j][i] = leds[j][i - 1];
    }
  }
  yield();
  MIDInoteF[tmpnote] = 0;
}
