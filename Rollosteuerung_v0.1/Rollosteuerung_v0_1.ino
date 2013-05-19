/*
Arduino Pin belegung :
12V Spanungs versorgeung 
#################################################
#Pin 0	= serial				#
#Pin 1	= serial				#
#Pin 2	= TasterHome				#
#Pin 3	= MotorUp1				#
#Pin 4	= TasterAkt.1				#
#Pin 5	= MotorDown1				#
#Pin 6	= MotorUp2				#
#Pin 7	= TasterAkt.2				#
#Pin 8	= RolloTaster1				#
#Pin 9	= MotorDown2				#
#Pin 10	= RolloTaster2				#
#Pin 11	= 					#
#Pin 12	= 					#
#Pin 13	= 					#
#A0	= 					#
#A1	= 					#
#A2	= 					#
#A3	= 					#
#A4	= 					#
#A5	= 					#
#################################################
#Hier ist eine tabellen wo man sich das passende#
#PWM signal raussuchen kann, das PWM gibt vor 	#
#mit was für einer Spannung die Motoren 	#
#versorgt werden sollen.			#
#						#
# PWM:   Volt:					#
#  32 =  1,30V					#
#  33 =  1,34V					#
#  35 =  1,43V					#
#  40 =  1,63V					#
#  50 =  2,04V					#
#  60 =  2,45V					#
#  70 =  2,86V					#
#  80 =  3,27V					#
#  90 =  3,68V					#
# 100 =  4,09V					#
# 110 =  4,50V					#
# 120 =  4,91V					#
# 130 =  5,32V					#
# 140 =  5,73V					#
# 150 =  6,14V					#
# 160 =  6,55V					#
# 170 =  6,96V					#
# 180 =  7,37V					#
# 190 =  7,78V					#
# 200 =  8,19V					#
# 210 =  8,60V					#
# 220 =  9,01V					#
# 230 =  9,42V					#
# 240 =  9,83V					#
# 250 = 10,24V					#
# 255 = 10,45V					#
#################################################
*/

//Steuerungs Taster Belegungen

#define TasterHome 2 
#define TasterAkt1 4
#define TasterAkt2 7

//Rollo 1

#define MotorUp1 3
#define MotorDown1 5
#define RolloTaster1 8

//Rollo 2

#define MotorUp2 6
#define MotorDown2 9
#define RolloTaster2 10 

//Configuration 
//Rollo Motor ausgangs Spannung
#define RolloVolt 120

void setup() {

  Serial.begin(9600); // Diehnt nur zur Kontrollen kann hinterher wider gelöscht werden 
  pinMode(TasterHome, INPUT_PULLUP);
  pinMode(TasterAkt1, INPUT_PULLUP);
  pinMode(TasterAkt2,INPUT_PULLUP);
    
  pinMode(MotorUp1, OUTPUT);
  pinMode(MotorDown1, OUTPUT);
  pinMode(RolloTaster1, INPUT_PULLUP);

  pinMode(MotorUp2, OUTPUT);
  pinMode(MotorDown2, OUTPUT);
  pinMode(RolloTaster2, INPUT_PULLUP);

}

void loop() {
  //Rolo fährt auf die Home Position
  if(digitalRead(TasterHome) == LOW)
  {  

    digitalWrite(TasterHome, HIGH);
    int Home = 0;
    while(Home == 0)
    {
      Serial.println("Faehrt auf die Home Position"); // zur kontrolle
      if(digitalRead(RolloTaster1) == HIGH) //Über prüft ob der "Taster1Up" High ist. 
      {
        digitalWrite(MotorDown1, LOW);
        analogWrite(MotorUp1, RolloVolt); //Hardware PWM auf die H-brücke um die geschwindigkeit zu regeln möglich von 0-255 
      } 

      else
      { 
        digitalWrite(MotorUp1, LOW);
        Home = 1;
      }

    }
    Serial.println("Rolo ist auf der Home Position"); // zur kontrolle
  }
  //Rolo fährt runter 
  if(digitalRead(TasterAkt1) == LOW)
  {
    if(digitalRead(RolloTaster1) == LOW) //Über prüft ob der "Taster1Up" auf low gezogen ist. 
    {
      digitalWrite(MotorUp1, LOW);
      analogWrite(MotorDown1, RolloVolt); //Hardware PWM auf die H-brücke um die geschwindigkeit zu regeln möglich von 0-255 
      Serial.println("Rolo faehrt runter!"); // zur kontrolle
      delay(20000); 
      digitalWrite(MotorDown1, LOW);
      Serial.println("Rolo ist aus!"); // zur kontrolle
    } 
    else
    {
      Serial.println("Bitte erst auf die Home Position fahren!");
      digitalWrite(MotorUp1, LOW);
      digitalWrite(MotorDown1, LOW);
    }
  }
}


