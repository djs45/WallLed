void SetupINO() {
  initPresets();
  bFirst = true;
  vid = pid = 0;
  Serial.begin(115200);

#ifdef ARDUINO_SAM_DUE
  Serial.println("USBH_MIDI_dump");
#else
  //Workaround for non UHS2.0 Shield
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);

  if (Usb.Init() == -1) {
    while (1)
      ;  //halt
  }      //if (Usb.Init() == -1...
#endif
  delay(200);
  MSGEQ7.begin();
  BPMtime = millis();
  for (int i = 0; i < 128; i++) {
    MIDInoteF[i] = 0;
  }
  for (int i = 0; i < 7; i++) {
    audioval[i] = 0;    audiovalP[i] = 0;
  }
  FastLED.addLeds<LED_TYPE, 7, COLOR_ORDER>(leds[0], NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 6, COLOR_ORDER>(leds[1], NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 5, COLOR_ORDER>(leds[2], NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(leds[3], NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 3, COLOR_ORDER>(leds[4], NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 2, COLOR_ORDER>(leds[5], NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 30, COLOR_ORDER>(ledsR, NUM_LEDSR).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, 31, COLOR_ORDER>(ledsLEGO, NUM_LEDSLEGO).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();  
  fill_solid(ledsR, NUM_LEDSR, CRGB::Blue);  FastLED.show();
  MIDInote[24] = 1;  MIDInote[32] = 1;
  Scheduler.startLoop(MidiTest);
  Scheduler.startLoop(AutoGHUE);
  Scheduler.startLoop(usbtask);  // ADD YIELD to line 314 of usb_midi.cpp // ADD YIELD to line 714 of Usb.cpp // need to verify that from V21
  Scheduler.startLoop(refreshDisp);
}
