void dataStore(int tmpvar){
  int preset = tmpvar * 50;
  dueFlashStorage.write(preset + 0,FTB1);
  dueFlashStorage.write(preset + 1,FTB2);
  dueFlashStorage.write(preset + 2,LetAtOnceR);
  dueFlashStorage.write(preset + 3,LetAtOnceL);
  dueFlashStorage.write(preset + 4,globSpeedR);
  dueFlashStorage.write(preset + 5,globSpeedL);
  dueFlashStorage.write(preset + 6,globSpeedgHue);
  dueFlashStorage.write(preset + 7,PotPal);
  dueFlashStorage.write(preset + 8,gHue);
  dueFlashStorage.write(preset + 9,autogHue);
  for (int i=16;i<41;i++){
    dueFlashStorage.write(preset + i,MIDInote[i]);
  }
}

void dataStoreRead(int tmpvar){
  int preset = tmpvar * 50;
  FTB1 = dueFlashStorage.read(preset + 0);
  FTB2 = dueFlashStorage.read(preset + 1);
  LetAtOnceR = dueFlashStorage.read(preset + 2);
  LetAtOnceL = dueFlashStorage.read(preset + 3);
  globSpeedR= dueFlashStorage.read(preset + 4);
  globSpeedL= dueFlashStorage.read(preset + 5);
  globSpeedgHue= dueFlashStorage.read(preset + 6);
  PotPal= dueFlashStorage.read(preset + 7);
  gHue= dueFlashStorage.read(preset + 8);
  autogHue= dueFlashStorage.read(preset + 9);
  for (int i=16;i<41;i++){
    MIDInote[i] = dueFlashStorage.read(preset + i);
  }
}

void dispPreset(){
  delay(100);
  printf("\nDisplay Presets\n");
  for (int preset = 0;preset<16;preset++){
    // printf("byte preset%d[] = {",preset);
    printf ("case %d:",preset);
    printf ("t0=%d;",dueFlashStorage.read((preset*50) + 0));
    printf ("t1=%d;",dueFlashStorage.read((preset*50) + 1));
    printf ("t2=%d;",dueFlashStorage.read((preset*50) + 2));
    printf ("t3=%d;",dueFlashStorage.read((preset*50) + 3));
    printf ("t4=%d;",dueFlashStorage.read((preset*50) + 4));
    printf ("t5=%d;",dueFlashStorage.read((preset*50) + 5));
    printf ("t6=%d;",dueFlashStorage.read((preset*50) + 6));
    printf ("t7=%d;",dueFlashStorage.read((preset*50) + 7));
    printf ("t8=%d;",dueFlashStorage.read((preset*50) + 8));
    printf ("t9=%d;",dueFlashStorage.read((preset*50) + 9));
    // printf ("tM[127];");
    for (int i = 16; i<41;i++){      
      printf ("tM[%i] = %d;",i,dueFlashStorage.read((preset*50) + i));
    }
    printf ("break;\n");
  }
}

void initPresets(){  
    Serial.println("No Presets in Flash");
    byte t0;byte t1;byte t2;byte t3;int t4;int t5;int t6;byte t7;uint8_t t8;bool t9;bool tM[127];
    for (int tmpvar = 0;tmpvar<16;tmpvar++){
      int preset = tmpvar*50;
      if (dueFlashStorage.read(preset) == 255) {
        // delay(10);
        printf ("Writing %d",tmpvar);
        switch (tmpvar){          
          case 0:t0=20;t1=20;t2=8;t3=8;t4=100;t5=100;t6=44;t7=1;t8=174;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 1;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 1;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 1:t0=126;t1=126;t2=63;t3=63;t4=5;t5=5;t6=44;t7=1;t8=204;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 1;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 1;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 2:t0=126;t1=126;t2=63;t3=63;t4=104;t5=104;t6=44;t7=1;t8=139;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 1;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 3:t0=126;t1=126;t2=63;t3=63;t4=104;t5=104;t6=44;t7=1;t8=125;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 1;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 4:t0=126;t1=126;t2=63;t3=63;t4=104;t5=104;t6=44;t7=1;t8=131;t9=1;tM[16] = 1;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 5:t0=126;t1=126;t2=63;t3=63;t4=104;t5=104;t6=44;t7=1;t8=204;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 1;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 6:t0=127;t1=127;t2=8;t3=8;t4=100;t5=100;t6=44;t7=1;t8=214;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 1;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 7:t0=126;t1=126;t2=63;t3=63;t4=5;t5=5;t6=44;t7=1;t8=206;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 1;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 8:t0=126;t1=126;t2=63;t3=63;t4=5;t5=5;t6=44;t7=1;t8=136;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 1;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 1;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 9:t0=126;t1=126;t2=63;t3=63;t4=5;t5=5;t6=44;t7=1;t8=12;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 1;tM[32] = 0;tM[33] = 1;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 10:t0=126;t1=126;t2=63;t3=63;t4=5;t5=5;t6=44;t7=1;t8=218;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 1;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 11:t0=127;t1=127;t2=8;t3=8;t4=100;t5=100;t6=44;t7=1;t8=77;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 1;tM[39] = 0;tM[40] = 0;break;
          case 12:t0=127;t1=127;t2=8;t3=8;t4=100;t5=100;t6=44;t7=1;t8=229;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 1;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 13:t0=127;t1=127;t2=8;t3=8;t4=100;t5=100;t6=44;t7=1;t8=62;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 1;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 14:t0=127;t1=127;t2=8;t3=8;t4=100;t5=100;t6=44;t7=1;t8=205;t9=1;tM[16] = 0;tM[17] = 1;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          case 15:t0=127;t1=127;t2=8;t3=8;t4=100;t5=100;t6=44;t7=1;t8=10;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 1;tM[24] = 0;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 0;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
          default:t0=20;t1=20;t2=8;t3=8;t4=100;t5=100;t6=44;t7=1;t8=178;t9=1;tM[16] = 0;tM[17] = 0;tM[18] = 0;tM[19] = 0;tM[20] = 0;tM[21] = 0;tM[22] = 0;tM[23] = 0;tM[24] = 1;tM[25] = 0;tM[26] = 0;tM[27] = 0;tM[28] = 0;tM[29] = 0;tM[30] = 0;tM[31] = 0;tM[32] = 1;tM[33] = 0;tM[34] = 0;tM[35] = 0;tM[36] = 0;tM[37] = 0;tM[38] = 0;tM[39] = 0;tM[40] = 0;break;
        }
        dueFlashStorage.write(preset + 0,t0);
        dueFlashStorage.write(preset + 1,t1);
        dueFlashStorage.write(preset + 2,t2);
        dueFlashStorage.write(preset + 3,t3);
        dueFlashStorage.write(preset + 4,t4);
        dueFlashStorage.write(preset + 5,t5);
        dueFlashStorage.write(preset + 6,t6);
        dueFlashStorage.write(preset + 7,t7);
        dueFlashStorage.write(preset + 8,t8);
        dueFlashStorage.write(preset + 9,t9);
        for (int i = 16; i<41;i++){
          dueFlashStorage.write(preset + i,tM[i]);
        }
      } // else {noteOn(tmpvar, 3);}
    }    
} 