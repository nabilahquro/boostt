
//Program to Code for Buck Converter with Input voltage = 12V and Adjustable Output voltage = -3V to -18VThis code will generate a PWM (Pulse Width Modulation)signal of 200kHz. 



#define TOP 79                          // Fosc = Fclk/(N*(1+TOP)); Fclk = 16MHz, Fosc = 200kHz

#define CMP_VALUE_HALF_DUTY 40           // 50% duty cycle

#define Inputpin A5                        // Input pin of potentiometer at A5

#define PWM 9                            // PWM(Pulse Width Modulation) wave at pin 9 

float Mapping_output();            // function declaration  


float Mapping_output(){                            // function definition 

int Input_Read = analogRead(Inputpin);                     
//reading analog voltage from potentiometer and converting it to digital values in between 0 to 1023

float Compare_voltage = (((Input_Read*(1.0)/1024)*15)+3);   
// mapping the digital value into analog volatge of 5V to 9V

return(Compare_voltage);                                   // return the calculated output voltage

}


void setup() {

  // put your setup code here, to run once: 

pinMode(PWM,OUTPUT);                        //set 9 pin as output 

pinMode(Inputpin,INPUT);                    // set A5 pin as input

TCCR1A = 0;                                 //reset the register

TCCR1B = 0;                                 //reset the register

TCNT1 = 0;                                   //reset the register

TCCR1A |= (1<<COM1A1);                       // set output at non inverting mode

TCCR1A |= (1<<WGM11);                        // selecting Fast PWM(pulse width modulation) mode

ICR1 = TOP;                                   // setting frequency to 10KHz

TCCR1B |= (1<< CS10)|(1<<WGM12)|(1<<WGM13);      //Timer Starts

OCR1A = CMP_VALUE_HALF_DUTY;                      // setting PWM of 50% duty cycle

delay(1000);                                    // delay for compensating the hardware transient time with software

}


void loop() {

  // put your main code here, to run repeatedly:  

float Output_voltage = Mapping_output();                                        // getting desired output volatge

float Desired_Duty_cycle = (1- (Output_voltage/(Output_voltage+12)));        
//calculating duty cycle as per the desired output voltage D = Vout/Vin

int OCR_value = (79*Desired_Duty_cycle);                                      //calculating OCR values as per the desired duty cycle

OCR1A = OCR_value;                            

}
