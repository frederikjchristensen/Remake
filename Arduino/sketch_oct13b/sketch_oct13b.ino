//Define pins
const int pResistor = A0;

//Values
int value;
int RPM;
int revolutions;

//Setup serial communication and pins.
void setup(){
  Serial.begin(9600);
  pinMode(pResistor, INPUT);
}

void loop()
{
  value = analogRead(pResistor);
  Serial.print("#");
  Serial.print(value);
  Serial.print("!");

if (value < 920);
{
  //DO STUFF
}
}
