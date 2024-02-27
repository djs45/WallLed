//39
template<int tmpnote> void infinit() {
  int strip = 0;
  int esp = 1;
  int couleur = 213;  //gHue

  // up from middle
  for (int led = NUM_LEDS / 2; led < NUM_LEDS; led = led + esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  strip++;

  // down from top
  for (int led = NUM_LEDS - 1; led > NUM_LEDS / 2; led = led - esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  strip++;

  // down from middle
  for (int led = NUM_LEDS / 2; led > -1; led = led - esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  strip++;

  // up from bottom
  for (int led = 0; led < NUM_LEDS / 2; led = led + esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  strip++;

  //up from middle
  for (int led = NUM_LEDS / 2; led < NUM_LEDS; led = led + esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  strip++;

  // down from top
  for (int led = NUM_LEDS - 1; led > NUM_LEDS / 2; led = led - esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }

  // down from middle
  for (int led = NUM_LEDS / 2; led > -1; led = led - esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  strip--;

  // up from bottom
  for (int led = 0; led < NUM_LEDS / 2; led = led + esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  strip--;

  //up from middle
  for (int led = NUM_LEDS / 2; led < NUM_LEDS; led = led + esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  strip--;

  // down from top
  for (int led = NUM_LEDS - 1; led > NUM_LEDS / 2; led = led - esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  strip--;

  // down from middle
  for (int led = NUM_LEDS / 2; led > -1; led = led - esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  strip--;

  // up from bottom
  for (int led = 0; led < NUM_LEDS / 2; led = led + esp) {
    if (MIDInoteF[tmpnote] == 0) {
      break;
    }
    leds[strip][led].setHSV(couleur, 255, 255);
    delay(globSpeedL);
    // yield();
  }
  // yield();
  MIDInoteF[tmpnote] = 0;
}