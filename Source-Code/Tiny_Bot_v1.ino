/*
Tiny Bot: an LDR based light following robot, or avoidance bot
 if you switch the drive function around.
 Hardware is based off the Light Bot by born 2 craft

 TODO:
 Add IR control
 Clean up code
 ##############################
 Written by:
 Reece May 
 rev1 12/15/14
 https://bariumelectronics.blogspot.com

You may use the code and modify it as long as you keep the above
and make edit notes bellow and put it on github here:
https://github.com/ReeceM/Tiny-Bot.git
 */

#define Rmtr 1
#define Lmtr 0
#define Rsens 3
#define Lsens 2
#define drive_time 100

int Rav, Lav = 0;

void setup(){

  pinMode(Rmtr, OUTPUT); 
  pinMode(Lmtr, OUTPUT);
  pinMode(Rsens, INPUT);
  pinMode(Lsens, INPUT);

}

void ADread(){
  Rav, Lav = 0;   //clear the average to prevent errors

  for(int q = 0; q < 20; q++){ //loop to create average

    Rav += analogRead(Rsens);
    Lav += analogRead(Lsens);
  }

  Rav /= 19;
  Lav /= 19;
}

void drive_RIGHT(){
  digitalWrite(Lmtr, 0);

  digitalWrite(Rmtr, 1);
  delay(drive_time);
  digitalWrite(Rmtr, 0);
  delay(drive_time);
}

void drive_LEFT(){
  digitalWrite(Rmtr, 0);

  digitalWrite(Lmtr, 1);
  delay(drive_time);
  digitalWrite(Lmtr, 0);
  delay(drive_time);
}

void loop(){

  ADread();
  if(Rav < Lav){
    drive_RIGHT();
    //drive_LEFT();  //use this to avoid light
  }
  ADread();
  if(Lav < Rav){
    drive_LEFT();
    //drive_RIGHT();  //use this to avoid light
  }
}
