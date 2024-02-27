//34
template<int tmpnote> void SpectrumWave() {
  for (int i = 0; i < 31; i++) {
    ledsR[i + 30 * 0].setHSV(0, 255, audioval[0]);
    ledsR[i + 30 * 1].setHSV(32, 255, audioval[1]);
    ledsR[i + 30 * 2].setHSV(64, 255, audioval[2]);
    ledsR[i + 30 * 3].setHSV(96, 255, audioval[3]);
    ledsR[i + 30 * 4].setHSV(128, 255, audioval[4]);
    ledsR[i + 30 * 5].setHSV(160, 255, audioval[5]);
    ledsR[i + 30 * 6].setHSV(192, 255, audioval[6]);
  }
  // yield();
  MIDInoteF[tmpnote] = 0;
}

//35
template<int tmpnote> void SpectrumWave2() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < map(audioval[i], 0, 255, 0, 14); j++) {
      ledsR[(35 * i) + (14 - j)].setHSV(gHue, 255, 255);
      ledsR[(35 * i) + (15 + j)].setHSV(gHue, 255, 255);
    }
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < map(audioval[i], 0, 255, 0, 20); j++) {
      leds[i][20 - j].setHSV(gHue, 255, 255);
      leds[i][21 + j].setHSV(gHue, 255, 255);
    }
  }
  // yield();
  MIDInoteF[tmpnote] = 0;
}