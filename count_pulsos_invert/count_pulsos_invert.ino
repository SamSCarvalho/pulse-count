unsigned long int IRQcount;
int countEvents = 0;
int pin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  attachInterrupt(digitalPinToInterrupt(pin), IRQcounter, FALLING);
//  TCCR1A = 0;                        // confira timer para operação normal pinos OC1A e OC1B desconectados
//  TCCR1B = 0;                        // limpa registrador
//  TCCR1B |= (1<<CS10)|(1 << CS12);   // configura prescaler para 1024: CS12 = 1 e CS10 = 1
 
//  TCNT1 = 0xC2F7;                    // incia timer com valor para que estouro ocorra em 1 segundo
                                     // 65536-(16MHz/1024/1Hz) = 49911 = 0xC2F7
//  TIMSK1 |= (1 << TOIE1);   
}

void IRQcounter() {
  if (IRQcount == 32768) {
    IRQcount = 0;
    Serial.print("One Second: ");
  }
  IRQcount++;
}

void loop() {
  // put your main code here, to run repeatedly:
}

//ISR(TIMER1_OVF_vect) // interrupção do TIMER1 
//{
//  TCNT1 = 0xC2F7; // Renicia TIMER
//  cli();//disable interrupts
//  unsigned long int result = IRQcount;
//  countEvents++;
//  IRQcount = 0;
//  sei();//enable interrupts
//  Serial.print(F("Event: "));
//  Serial.print(countEvents);
//  Serial.print(F(" Counted Pulses = "));
//  Serial.println(result);
//}
