//Name: Diana Kim
//project name: sensor controlled computer operations
//Version 1.0

const int trigger1 = 4;
const int echo1 = 5;
long time_taken;
int dist,distM;


void setup() {
  Serial.begin(9600);
  
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  
}

void calculate_distance(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  time_taken = pulseIn(echo, HIGH);
  dist = time_taken*0.034/2;
  if (dist>50)
  dist = 50;
}

void loop() {
  calculate_distance(trigger1, echo1);
  distM = dist;
  
  Serial.println(distM);

  if (distM > 20 && distM < 50)
  {Serial.println("Play/Pause"); delay (500);}

  if ((distM > 10 && distM  < 20)) 
  {Serial.println("Backwards 10"); delay (500);}

  if (distM >0 && distM <10)
  {Serial.println("Forward 10"); delay (500);}

  delay(200);
}
