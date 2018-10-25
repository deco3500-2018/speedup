float pressLength_milliSeconds = 0;
int optionOne_milliSeconds = 100;
int optionTwo_milliSeconds = 500;            
int buttonPin = 2;

int ledPin_Option_1 = 13;
int ledPin_Option_2 = 12;

void setup(){
  pinMode(buttonPin, INPUT_PULLUP);     

  //set the LEDs pins as outputs
  pinMode(ledPin_Option_1, OUTPUT); 
  pinMode(ledPin_Option_2, OUTPUT); 

  Serial.begin(9600);                                     
}


void loop() {

  while (digitalRead(buttonPin) == LOW ){ 
    delay(100);   
    pressLength_milliSeconds = pressLength_milliSeconds + 100;   

    Serial.print("ms = ");
    Serial.println(pressLength_milliSeconds);
  }

 
  if (pressLength_milliSeconds >= optionTwo_milliSeconds){
    digitalWrite(ledPin_Option_2, HIGH);  
    digitalWrite(ledPin_Option_1, LOW);   
  } 

  else if(pressLength_milliSeconds >= optionOne_milliSeconds){
    digitalWrite(ledPin_Option_1, HIGH);  
    digitalWrite(ledPin_Option_2, LOW);   
  }

  pressLength_milliSeconds = 0;
}
