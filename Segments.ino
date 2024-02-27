template<int tmpnote> void RandSeg() {
  seg(random8(3), random8(8));
  delay(globSpeedL);
  // yield();
  MIDInoteF[tmpnote] = 0;
}

template<int tmpnote> void ChenSeg() {
  for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 3; i++) {
      seg(i, j);
    }
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    delay(globSpeedL);
    // yield();
  }
  MIDInoteF[tmpnote] = 0;
}

void seg(int cadre, int segment) {
  cadre = cadre * 2;
  if (segment == 0) {
    for (int i = 0; i < 5; i++) { leds[cadre + 1][i].setHSV(gHue, 255, 255); }
    for (int i = 0; i < 5; i++) { leds[cadre][i].setHSV(gHue, 255, 255); }
  }
  if (segment == 1) {
    for (int i = 5; i < 15; i++) { leds[cadre + 1][i].setHSV(gHue, 255, 255); }
  }
  if (segment == 2) {
    for (int i = 15; i < 25; i++) { leds[cadre + 1][i].setHSV(gHue, 255, 255); }
  }
  if (segment == 3) {
    for (int i = 25; i < 36; i++) { leds[cadre + 1][i].setHSV(gHue, 255, 255); }
  }
  if (segment == 4) {
    for (int i = 36; i < 41; i++) { leds[cadre][i].setHSV(gHue, 255, 255); }
    for (int i = 36; i < 41; i++) { leds[cadre + 1][i].setHSV(gHue, 255, 255); }
  }
  if (segment == 5) {
    for (int i = 25; i < 36; i++) { leds[cadre][i].setHSV(gHue, 255, 255); }
  }
  if (segment == 6) {
    for (int i = 15; i < 25; i++) { leds[cadre][i].setHSV(gHue, 255, 255); }
  }
  if (segment == 7) {
    for (int i = 5; i < 15; i++) { leds[cadre][i].setHSV(gHue, 255, 255); }
  }
}