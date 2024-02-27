void MIDI_poll() {
  char buf[16];
  uint8_t bufMidi[64];
  uint16_t rcvd;

  if (Midi.vid != vid || Midi.pid != pid) {
    if (MIDIrcvDEBUG) {
      sprintf(buf, "VID:%04X, PID:%04X", Midi.vid, Midi.pid);
      Serial.println(buf);
    }
    vid = Midi.vid;
    pid = Midi.pid;
  }
  if (Midi.RecvData(&rcvd, bufMidi) == 0) {
    if (MIDIrcvDEBUG) {
      for (int i = 0; i < 4; i++) {
        Serial.print(bufMidi[i]);
        Serial.print(' ');
        Serial.println("");
      }
    }
    if (bufMidi[1] == 144) {
      midi_note_on(0, bufMidi[2], 127);
    }
    if (bufMidi[1] == 128) {
      midi_note_off(0, bufMidi[2], 0);
      if (bufMidi[2] == 21) { MIDInote[37] = 0; }
    }
    if (bufMidi[1] == 176) {
      midi_control_change(0, bufMidi[2], bufMidi[3]);
    }
    if (bufMidi[1] == 177 && bufMidi[2] == 64 && bufMidi[3]) {
      dispPreset();
    }
    if (bufMidi[1] == 145) {
      midi_note_on(1, bufMidi[2], 127);
    }
    if (bufMidi[1] == 129) {
      midi_note_off(1, bufMidi[2], 0);
    }
  }
}

void midi_note_on(byte channel, byte note, byte velocity) {
  // printf("note on, chan: %d, note: %d, velocity: %d\r\n", channel, note, velocity);
  if (channel == 1) { MIDInote[note - 32] = 1; }
  if (channel == 0) {
    if (note == 91) { autogHue = 1; }
    if (note == 93) { autogHue = 0; }
    if (note == 81) { ResetMIDInote(); }
    if (note == 64) { PotPal = 1; }
    if (note == 65) { PotPal = 2; }
    if (note == 66) { PotPal = 3; }
    if (note == 67) { PotPal = 4; }
    if (note == 68) { PotPal = 5; }
    if (note == 69) { PotPal = 6; }
    if (note == 70) { PotPal = 7; }
    if (note == 71) { PotPal = 8; }
    if (note == 98) { BtShift = 1; }
    if (note < 16) {
      if (BtShift == 1) { dataStore(note); }
      if (BtShift == 0) {
        dataStoreRead(note);
        for (int i = 0; i < 16; i++) {
          noteOn(i, 0);
        }
        noteOn(note, 5);
      }
    }
    if (note >= 16 && note <= 40) {
      if (MIDInote[note] == 0) {
        MIDInote[note] = 1;
        noteOn(note, 3);
      } else {
        MIDInote[note] = 0;
        noteOn(note, 1);
      }
    }
  }
}

void midi_note_off(byte channel, byte note, byte velocity) {
  if (channel == 1) { MIDInote[note - 32] = 0; }
  if (channel == 0) {
    if (note == 98) { BtShift = 0; }
  }
  // printf("note off, chan: %d, note: %d\r\n", channel, note);
}

void ResetMIDInote() {
  for (int i = 0; i < 128; i++) {
    MIDInote[i] = 0;
  }
}

void noteOn(byte note, byte velocity) {
  byte buf[3];
  buf[0] = 0x90;
  buf[1] = note;
  buf[2] = velocity;
  Midi.SendData(buf);
  Midi.SendData(buf);
}

void noteOff(byte note) {
  byte buf[3];
  buf[0] = 0x80;
  buf[1] = note;
  buf[2] = 0x00;
  Midi.SendData(buf);
  Midi.SendData(buf);
}

void midi_control_change(byte channel, byte number, byte value) {
  //printf("control change, chan: %d, number: %d, value: %d\r\n", channel, number, value);
  if (number == 48) {
    FTB1 = value;
    FTB2 = value;
  }
  if (number == 49) {
    globSpeedR = map(value, 0, 127, 500, 1);
    globSpeedL = map(value, 0, 127, 500, 1);
  }
  if (number == 52) { gHue = map(value, 0, 127, 0, 255); }
  if (number == 53) { gHueDelta = value, 0, 127, 0, 255; }
  if (number == 50) {
    LetAtOnceR = map(value, 0, 127, 1, 64);
    LetAtOnceL = map(value, 0, 127, 1, 64);
  }
  if (number == 51) {OffsetLed = value;}
}

void doDelay(unsigned long t1, unsigned long t2, unsigned long delayTime) {
  unsigned long t3;
  if (t1 > t2) {
    t3 = (4294967295 - t1 + t2);
  } else {
    t3 = t2 - t1;
  }
  if (t3 < delayTime) {
    delayMicroseconds(delayTime - t3);
  }
}

void usbtask() {
  unsigned long t1;
  Usb.Task();
  t1 = micros();
  if (Usb.getUsbTaskState() == USB_STATE_RUNNING) {
    MIDI_poll();
  }
  yield();
}