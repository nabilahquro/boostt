int potentiometer = A0;
int feedback = A1;
int PWM = 3;
int pwm = 0;

void setup() {
  pinMode(potentiometer, INPUT);
  pinMode(feedback, INPUT);
  pinMode(PWM, OUTPUT);  
}

void loop() {  
  float voltage = analogRead(potentiometer);
  float output  = analogRead(feedback);

  if (voltage > output)
   {
    pwm = pwm+1;
    pwm = constrain(pwm, 0, 255);
   }

  if (voltage < output)
   {
    pwm = pwm-1;
    pwm = constrain(pwm, 0, 255);
   }

   analogWrite(PWM,pwm);
}
