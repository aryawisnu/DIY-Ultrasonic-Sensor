bool triggered = false;
bool Trig_in_state =  false;

void setup() {
  DDRD |= B00111000;  
  DDRB |= B00000100;  
  PCICR |= (1 << PCIE0);  
  PCMSK0 |= (1 << PCINT0);  
  PCMSK0 |= (1 << PCINT1);                                             
}

void loop() {
  if(triggered)
  {
  delayMicroseconds(150);    
  PORTD &= B11011111; 
  PORTD |= B00001000;   
  PORTD &= B11101111;   
  delayMicroseconds(12);
  PORTD &= B11110111;   
  PORTD |= B00010000;  
  delayMicroseconds(12);
  PORTD |= B00001000;  
  PORTD &= B11101111;   
  delayMicroseconds(12);
  PORTD &= B11110111;   
  PORTD |= B00010000;  
  delayMicroseconds(12);
  PORTD |= B00001000;   
  PORTD &= B11101111;  
  delayMicroseconds(12);
  PORTD &= B11110111;  
  PORTD |= B00010000;   
  delayMicroseconds(12);
  PORTD |= B00001000;   
  PORTD &= B11101111;  
  delayMicroseconds(12);
  PORTD &= B11110111;  
  PORTD |= B00010000;  
  delayMicroseconds(12);
  PORTD |= B00001000;  
  PORTD &= B11101111;   
  delayMicroseconds(12);
  PORTD &= B11110111;  
  PORTD |= B00010000;  
  delayMicroseconds(12);
  PORTD |= B00001000;   
  PORTD &= B11101111;   
  delayMicroseconds(12);
  PORTD &= B11110111;   
  PORTD |= B00010000;   
  delayMicroseconds(12);
  PORTD |= B00001000;   
  PORTD &= B11101111;   
  delayMicroseconds(12);
  PORTD &= B11110111;   
  PORTD |= B00010000;   
  delayMicroseconds(12);
  PORTD |= B00001000;   
  PORTD &= B11101111;   
  delayMicroseconds(12);
  PORTD &= B11000111;  
  PORTB |= B00000100;   
  triggered = false; 
  }
}

ISR(PCINT0_vect){
  if(PINB & B00000001){ 
    Trig_in_state = true;
  }
  else if(Trig_in_state)
  {
    triggered = true;    
    Trig_in_state = false;   
  }
  PORTB &= 11111011; 
}
