/*
########################################
# Pin 1  = seriel                      #
# Pin 2  = seriel                      #
# Pin 3  = Motor                       #
# Pin 4  = Motor                       #
# Pin 5  = Motor                       #
# Pin 6  = Motor                       #
# Pin 7  = Motor                       #
# Pin 8  = Motor                       #
# Pin 9  = Lichtschranke               #
# Pin 10 = Lichtschranke               #
# Pin 10 = Lichtschranke               #
# Pin 10 = Lichtschranke               #
# Pin 10 = Lichtschranke               #
# A0     =                             #
# A1     =                             #
# A2     =                             #
# A3     =                             #
# A4     = SDA                         #
# A5     = SCL                         #
########################################
*/



#define UP 1
#define DOWN -1
#define STOP 0


const byte Motoren[]= {3,2,5,4,7,6}; // mit define ordnet man den einzelnden Pins namen zu 

void setup (){
    for(byte n=0;n<7;n++) 
      pinMode(Motoren[n],OUTPUT);
fahren(0,DOWN);
delay(2000);
fahren(0,STOP);
delay(2000);
fahren(0,UP);
delay(2000);
fahren(0,STOP);
}

void loop () {
  
  
  

}

void fahren (byte Motor,int richtung) {  
  
   
   switch (richtung) { 
  
     case -1:
        digitalWrite(Motoren[1+Motor*2],0);
        digitalWrite(Motoren[Motor*2],1);
        break;
     case 0:
        digitalWrite(Motoren[1+Motor*2],0);
        digitalWrite(Motoren[Motor*2],0);
        break;
     case 1:
        digitalWrite(Motoren[Motor*2],0);
        digitalWrite(Motoren[1+Motor*2],1);
        break;
   }
}
