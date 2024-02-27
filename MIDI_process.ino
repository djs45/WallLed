void MidiTest() {
  for (int testnote = 16; testnote < 41; testnote++) {
    if (MIDInote[testnote] > 0) {
      if (MIDInoteF[testnote] == 0) {
        MIDInoteF[testnote] = 1;
        switch (testnote) {
          // 32 : Ring
          case 32: Scheduler.start(RandomRingLed<32>); break;
          case 33: Scheduler.start(vu1<33>); break;
          case 34: Scheduler.start(RainbowRing<34>); break;
          case 35: Scheduler.start(Pulse<35>); break;
          case 36: Scheduler.start(SpectrumWave<36>); break;  
          case 37: Scheduler.start(verticalVU<37>); break;  
          case 38: Scheduler.start(oldVU<38>); break; 
          //case 39: Scheduler.start(oldVU2<39>); break; 
          case 39: Scheduler.start(VUring<39>); break; 
          // 24 : Leds
          case 24: Scheduler.start(RandomLed<24>); break;
          case 25: Scheduler.start(vu2<25>); break;
          case 26: Scheduler.start(RandSeg<26>); break;
          case 27: Scheduler.start(ChenSeg<27>); break;
          case 28: Scheduler.start(infinit<28>); break;
          case 29: Scheduler.start(VUp3<29>); break;    
          case 30: Scheduler.start(vu5<30>); break;     
          case 31: Scheduler.start(VUseg<31>); break;     
            
          // 16 : Multi
          case 16: Scheduler.start(RandomLedAudio<16>); break;
          case 17: Scheduler.start(SpectrumWave2<17>); break;
          case 18: Scheduler.start(wave<18>); break;
          case 19: Scheduler.start(Strobo<19>); break;
          case 20: Scheduler.start(Flash<20>); break;
          case 21: ResetMIDInote(); MIDInote[testnote] = 100; Scheduler.start(wave2<21>); break;   
          case 22: Scheduler.start(vu3<22>); break;   
          case 23: Scheduler.start(vu4<23>); break;  
          //
          default:MIDInote[testnote]=0;break; 
        }
      }
    }
    if (MIDInote[testnote] == 0) { MIDInoteF[testnote] = 0; }
  }
  yield();
}