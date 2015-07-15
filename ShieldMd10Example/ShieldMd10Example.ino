/*******************************************************************************
 *
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTY AND SUPPORT
 * IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
 * DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ********************************************************************************
 *
 * SHIELD-MD10 EXAMPLE SOURCE CODE
 *
 *
 *
 * DESCRIPTION:
 *
 * This is an example to control the motor by using SHIELD-MD10.
 * The speed of the motor will ramp up from 0 to full speed,
 * and then ramp down back to 0 in both CW and CCW direction.
 *
 *
 *
 * AUTHOR   : Kong Wai Weng
 * COMPANY  : Cytron Technologies Sdn Bhd
 * REVISION : 1.0
 * DATE     : 22/10/2012
 *
 *******************************************************************************/



/*******************************************************************************
 * IO DEFINITION                                                                *
 *******************************************************************************/

// PWM is connected to pin 3.
const int pinPwm = 3;

// DIR is connected to pin 2.
const int pinDir = 2;



/*******************************************************************************
 * PRIVATE GLOBAL VARIABLES                                                     *
 *******************************************************************************/

// Speed of the motor.
static int iSpeed = 0;

// Acceleration of the motor.
static int iAcc = 1;


/*******************************************************************************
 * FUNCTIONS                                                                    *
 *******************************************************************************/

// The setup routine runs once when you press reset.
void setup() {                
  // Initialize the PWM and DIR pins as digital outputs.
  pinMode(pinPwm, OUTPUT);
  pinMode(pinDir, OUTPUT);
}



// The loop routine runs over and over again forever.
void loop() {
  
  // Control the motor according to the speed value.
  // Positive speed value = CW,
  // Negative speed value = CCW.
  if (iSpeed >= 0) {
    analogWrite(pinPwm, iSpeed);
    digitalWrite(pinDir, LOW);
  } 
  else {
    analogWrite(pinPwm, -iSpeed);
    digitalWrite(pinDir, HIGH);
  }
  
  // Increase/Decrease the speed according to the acceleration.
  iSpeed += iAcc;
  
  // Change the acceleration sign when full speed is reached.
  if ((iSpeed >= 255) || (iSpeed <= -255)) {
    iAcc = -iAcc;
  }
  
  
  delay(10);
}

