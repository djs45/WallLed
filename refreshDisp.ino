void refreshDisp() {
  if (Midi.vid > 0) {
    for (int note = 16; note < 41; note++) {
      if (MIDInote[note] > 0) {
        noteOn(note, 3);
      } else {
        noteOn(note, 1);
      }
      yield();
    }
    for (int tmpnote = 64; tmpnote < 72; tmpnote++) {
      if (tmpnote - 63 == PotPal) {
        noteOn(tmpnote, 1);
      } else {
        noteOn(tmpnote, 0);
      }
      yield();
    }
    delay(200);
  } else {
    delay(200);
    yield();
  }
}