
#include <Servo.h>

Servo servo7, servo8, servo9, servo10, servo11, servo12; // create servo object to control a servo
int var1, var2, var3, var4, var5, var6, var7, var8;    // variables to store the servo position
int but4 = 4, but5 = 5, but6 = 6;
int starttime, endtime;
/* servo7 and servo10 represent the arm core motors 
 * servo8 and servo11 represent the nearest joints to the core
 * servo9 and servo12 represent the the last joints*/
void setup() {
  servo7.attach(7);
  servo8.attach(8);    // attaches the first servo on pin 8 to the servo object
  servo9.attach(9);    // attaches the second servo on pin 9 to the servo object
  servo10.attach(10);  // attaches the third servo on pin 10 to the servo object
  servo11.attach(11);  // attaches the fourth servo on pin 11 to the servo object
  servo12.attach(12);  // attaches the fifth servo on pin 12 to the servo object
  pinMode(but4, INPUT);
  pinMode(but5, INPUT);
  pinMode(but6, INPUT);
  servo7.write(0);
  servo10.write(0);
  /* the initial position for the core motors is 0 degrees which is the lowest 
     point and the heighest point when the arm is lifted is 180 degrees*/ 
  servo8.write(0);
  servo11.write(0);
  /* the initial position for the shoulders is 0 degrees which is the tightest angle 
     the shoulder can get and 180 is the widest it can get*/ 
  servo9.write(90);
  servo12.write(90);
  /* the initial position for the hands is 90 degrees which is a midpoint 
     between 0 and 180 which the is capable of doing*/ 
}

void loop() {
  
  if(digitalRead(but4) == HIGH){

    for(var2=0; var2<=90; var2+=1){  // move the whole are to be parallel with the ground
      servo7.write(var2);
      servo10.write(var2);
      delay(15);
    }
    for(var3=0; var3<=35; var3+=1){ // open the shoulder 35 degrees
      servo8.write(var3);
      servo11.write(var3);
      delay(15);
    }
    starttime = millis();
    endtime = starttime;
    while((endtime - starttime)<=7000){ // swing the hands back and forth for 5 seconds as welcoming sign
      for(var1=90; var1>=0; var1-=1){
        servo9.write(var1);
        servo12.write(var1);
        delay(15);
      }
      for(var1=0; var1<=90; var1+=1){
        servo9.write(var1);
        servo12.write(var1);
        delay(15);
      }
      endtime = millis();
    }
    for(var3=35; var3>=0; var3-=1){ // back to the initial position
      servo8.write(var3);
      servo11.write(var3);
      delay(15);
    }
    for(var2=90; var2>=0; var2-=1){ // back to the initial position
      servo7.write(var2);
      servo10.write(var2);
      delay(15);
    }
  }

  else if(digitalRead(but5) == HIGH){
    for(var4=0; var4<=180; var4+=1){
      servo7.write(var4);
      servo10.write(var4);
      delay(15);
    }
    starttime = millis();
    endtime = starttime;
    while((endtime - starttime)<=7000){
      for(var5=0; var5<=180; var5+=1){
        servo8.write(var5);
        servo11.write(var5);
        delay(15);
      }
      for(var5=180; var5>=0; var5-=1){
        servo8.write(var5);
        servo11.write(var5);
        delay(15);
      }
      endtime = millis();
    }
    for(var4=180; var4>=0; var4-=1){
      servo7.write(var4);
      servo10.write(var4);
      delay(15);
  }
  }
  else if(digitalRead(but6) == HIGH){
    for(var6=0; var6<=180; var6+=1){
      servo7.write(var6);
      servo10.write(var6);
      delay(15);
      }
    for(var7=0; var7<=90; var7+=1){
      servo8.write(var7);
      servo11.write(var7);
      delay(15);
      }
    for(int counter=1; counter<=3; counter+=1){
      for(var8=90; var8>=0; var8-=1){
        servo9.write(var8);
        servo12.write(var8);
        delay(15);
      }
      for(var8=0; var8<=90; var8+=1){
        servo9.write(var8);
        servo12.write(var8);
        delay(15);
      }
    }
    for(var7=90; var7>=0; var7-=1){
      servo8.write(var7);
      servo11.write(var7);
      delay(15);
      }
    for(var6=180; var6>=0; var6-=1){
      servo7.write(var6);
      servo10.write(var6);
      delay(15);
      }
  }

}
