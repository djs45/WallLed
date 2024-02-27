//29
template<int tmpnote> void Pulse() {
  int speed = 10; //10
    for (int j = 25; j < 255; j=j+speed) {
      fill_solid(ledsR, NUM_LEDSR, CRGB( 0, 0, j));
      if (MIDInoteF[tmpnote] == 0){break;}
      yield();
    }
    for (int j = 255; j > 25; j=j-speed) {
      fill_solid(ledsR, NUM_LEDSR, CRGB( 0, 0, j));
      if (MIDInoteF[tmpnote] == 0){break;}
      yield();
    }
  MIDInoteF[tmpnote] = 0;
}