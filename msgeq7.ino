void readMSGEQ7() {
  bool newReading = MSGEQ7.read();
  if (newReading) {
    audioval[0] = mapNoise(MSGEQ7.get(MSGEQ7_0));
    audioval[1] = mapNoise(MSGEQ7.get(MSGEQ7_1));
    audioval[2] = mapNoise(MSGEQ7.get(MSGEQ7_2));
    audioval[3] = mapNoise(MSGEQ7.get(MSGEQ7_3));
    audioval[4] = mapNoise(MSGEQ7.get(MSGEQ7_4));
    audioval[5] = mapNoise(MSGEQ7.get(MSGEQ7_5));
    audioval[6] = mapNoise(MSGEQ7.get(MSGEQ7_6));
  }
  // byte tmpaudioval = (audioval[0] + audioval[1]) / 2;
  byte tmpaudioval = audioval[0];
  // if (audiovalP[EQbpm] > 0) {
  //   audiovalP[EQbpm] = audiovalP[EQbpm] - 1;
  // }
  // Serial.println(audioval[EQbpm]);
  //
  if (tmpaudioval > 127) {
    if (tmpaudioval > tmpaudiovalP) {
      audiovalPi = 1;
      audiovalPt = 1;
      tmpaudiovalP = tmpaudioval;
    } else {
      audiovalPi = 0;
      tmpaudiovalP = tmpaudioval;
    }
    if (audiovalPi == 0 and audiovalPt == 1) {
      float tmpBPM = 60000.0 / float(millis() - oldBPMtime);
      if (tmpBPM < 180) {  // tmpBPM > 60 and
        BPM = tmpBPM;
        oldBPMtime = millis();
        if (bpmDEBUG) {
          Serial.println(BPM);
          // fill_solid(ledsR, NUM_LEDSR, CRGB::White);
        }
        audiovalPt = 0;
      }
    }
  }
  // if (audioval[EQbpm] > audiovalP[EQbpm] and audioval[EQbpm] > 127) { //127
  //   audiovalP[EQbpm] = audioval[EQbpm];
  //   oldBPMtime = BPMtime;
  //   BPMtime = millis();
  //   float tmpBPM = 60000.0 / float (BPMtime - oldBPMtime);
  //   if (tmpBPM > 60 and tmpBPM < 180) {
  //     BPM = tmpBPM;
  //   }
  //   if (bpmDEBUG) {
  //     Serial.println(BPM);
  //     fill_solid(ledsR, NUM_LEDSR, CRGB::White);
  //   }
  // }
  //
  ledsR[0] = CRGB::Black;
}