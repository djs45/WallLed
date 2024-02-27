//36
template<int tmpnote> void Strobo() {
  float tmpspeed = BPM * 8 / 60;  // BPM/2 = wrong //
  float speed = 1 / tmpspeed * 1000;
  // Serial.println(speed);
  for (int i = 0; i < 6; i++) {
    fill_solid(leds[i], NUM_LEDS, CRGB::White);
  }
  fill_solid(ledsR, NUM_LEDSR, CRGB::White);
  delay(speed);
  for (int i = 0; i < 6; i++) {
    fill_solid(leds[i], NUM_LEDS, CRGB::Black);
  }
  fill_solid(ledsR, NUM_LEDSR, CRGB::Black);
  delay(speed);

  // int speed = BPM / 2;
  // fill_solid(leds[0], NUM_LEDS, CRGB::White);
  // fill_solid(leds[1], NUM_LEDS, CRGB::White);
  // delay(speed);
  // fill_solid(leds[0], NUM_LEDS, CRGB::Black);
  // fill_solid(leds[1], NUM_LEDS, CRGB::Black);
  // delay(speed);

  // fill_solid(leds[2], NUM_LEDS, CRGB::White);
  // fill_solid(leds[3], NUM_LEDS, CRGB::White);
  // fill_solid(ledsR, NUM_LEDSR, CRGB::White);
  // delay(speed);
  // fill_solid(leds[2], NUM_LEDS, CRGB::Black);
  // fill_solid(leds[3], NUM_LEDS, CRGB::Black);
  // fill_solid(ledsR, NUM_LEDSR, CRGB::Black);
  // delay(speed);

  // fill_solid(leds[4], NUM_LEDS, CRGB::White);
  // fill_solid(leds[5], NUM_LEDS, CRGB::White);
  // delay(speed);
  // fill_solid(leds[4], NUM_LEDS, CRGB::Black);
  // fill_solid(leds[5], NUM_LEDS, CRGB::Black);
  // delay(speed);

  // fill_solid(leds[2], NUM_LEDS, CRGB::White);
  // fill_solid(leds[3], NUM_LEDS, CRGB::White);
  // fill_solid(ledsR, NUM_LEDSR, CRGB::White);
  // delay(speed);
  // fill_solid(leds[2], NUM_LEDS, CRGB::Black);
  // fill_solid(leds[3], NUM_LEDS, CRGB::Black);
  // fill_solid(ledsR, NUM_LEDSR, CRGB::Black);
  // delay(speed);

  MIDInoteF[tmpnote] = 0;
}

//37
template<int tmpnote> void Flash() {
  for (int i = 0; i < 6; i++) {
    fill_solid(leds[i], NUM_LEDS, CRGB::White);
  }
  fill_solid(ledsR, NUM_LEDSR, CRGB::White);
  MIDInoteF[tmpnote] = 0;
}