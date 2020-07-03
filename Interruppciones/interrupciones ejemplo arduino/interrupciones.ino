const int PINsalida = 10; // se elije el pin de emulacion de señal cuadrada  
const int LEDPin = 13;    // se elije el pin de led 
const int PINentrada = 2;   // se elije el pin por el cual se leera la interrupcon
volatile int state = LOW; //se elije el estado inicial del led
 
void setup() {
   pinMode(PINsalida, OUTPUT);  // se configuran los pines seleccionados
   pinMode(LEDPin, OUTPUT);
   pinMode(PINentrada, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(PINentrada), blink, CHANGE); // se configura la interrupciones diciendo por que pin se leera y que subrutina se hara cuando se leea 
}
 
void loop() {
   //esta parte es para emular la salida
   digitalWrite(PINsalida, HIGH);   //se crea la señal cuadrada de salida
   delay(1000);       
   digitalWrite(PINsalida, LOW);
   delay(1000);
}
 
void blink() {    //cuandose ee la interrupcion se ejecuta esta funcion
   state = !state;      // se cambia el estado del pin
   digitalWrite(LEDPin, state); //se le pasa el estado al LED
}
