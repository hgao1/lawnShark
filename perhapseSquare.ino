/* FOR THE MOTOR */
//int M1 = 2;
//int M2 = 3;


/* FOR THE WHEELS */ 
int FL1 = 13;
int FL2 = 12;
int FR1 = 9;
int FR2 = 8;

int BL1 = A2; 
int BL2 = A1; 
int BR1 = 4; 
int BR2 = 7; 

int ENA = 6;
int ENB = 5; 

int ENA_B = 10; 
int ENB_B = 11; 

int command; 
boolean command_ready = false; 
// Max speed: 255
int speedCar = 255; 
int turning = 125; 
int speed_Coeff = 2; 
// Timing: 
unsigned long startMillis; 
unsigned long currentMillis; 
const unsigned long period = 3000; 
// Variables: 
float put_distance = 2 * 305 ; //approx 2 feet in mm
float wheel = 151 ; //feet in mm 
float rotation = 0  ; 
float timeLim = 0 ;

void calculateTime() { 
  rotation = put_distance / wheel ; 
  timeLim = rotation * 0.47 ; 
  timeLim = timeLim * 1000 ; 
  timeLim = round(timeLim); 
  
  Serial.println(timeLim); 
}

void setup() {
  //starting motors: 
 // pinMode(M1, OUTPUT);
  // pinMode(M2, OUTPUT);

  //setting up wheels:
  pinMode(FR1, OUTPUT);
  pinMode(FR2, OUTPUT);

  pinMode(FL1, OUTPUT);
  pinMode(FL2, OUTPUT);
  
  pinMode(BL1, OUTPUT);
  pinMode(BL2, OUTPUT);  
  
  pinMode(BR1, OUTPUT);
  pinMode(BR2, OUTPUT);

  //setting up enable motors: 
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT); 
  pinMode(ENA_B, OUTPUT);
  pinMode(ENB_B, OUTPUT); 

  Serial.begin(9600); 
  Serial.println("I'm going to move in a square") ; 
  calculateTime() ; 
  
  delay(1000); 
  startMillis = millis(); // initial start time 

}

void forwardRight(){
    //digitalWrite(M1, HIGH);
    //digitalWrite(M2, HIGH); 
    
    digitalWrite(FR1, HIGH); 
    digitalWrite(FR2, LOW);
    analogWrite(ENB, turning); 
    
    digitalWrite(FL1, HIGH);
    digitalWrite(FL2, LOW);
    analogWrite(ENA, speedCar); 

    digitalWrite(BR1, LOW); 
    digitalWrite(BR2, HIGH);
    analogWrite(ENB_B, speedCar); 

    digitalWrite(BL1, HIGH);
    digitalWrite(BL2, LOW);
    analogWrite(ENA_B, turning); 
    Serial.println("Going Forward Right"); 
}


void stop(){
    //digitalWrite(M1, LOW);
    //digitalWrite(M2, LOW);
    
    digitalWrite(FR1, LOW); 
    digitalWrite(FR2, LOW);
    
    digitalWrite(FL1, LOW); 
    digitalWrite(FL2, LOW);

    digitalWrite(BR1, LOW); 
    digitalWrite(BR2, LOW);
    
    digitalWrite(BL1, LOW); 
    digitalWrite(BL2, LOW);

    Serial.println("You've stopped");
}
void forward(){
    //digitalWrite(M1, HIGH);
    //digitalWrite(M2, HIGH);
    
    digitalWrite(FR1, HIGH); 
    digitalWrite(FR2, LOW);
    analogWrite(ENB, speedCar); 

    digitalWrite(FL1, HIGH);
    digitalWrite(FL2, LOW);
    analogWrite(ENA, speedCar); 

    digitalWrite(BR1, LOW); 
    digitalWrite(BR2, HIGH);
    analogWrite(ENB_B, speedCar); 

    digitalWrite(BL1, HIGH);
    digitalWrite(BL2, LOW);
    analogWrite(ENA_B, speedCar);
    
    Serial.println("Forward"); 
}
void back(){
  digitalWrite(FR1, LOW); 
  digitalWrite(FR2, HIGH);
  analogWrite(ENB, speedCar); 

  digitalWrite(FL1, LOW);
  digitalWrite(FL2, HIGH);
  analogWrite(ENA, speedCar); 
  
  digitalWrite(BR1, HIGH); 
  digitalWrite(BR2, LOW);
  analogWrite(ENB_B, speedCar); 

  digitalWrite(BL1, LOW);
  digitalWrite(BL2, HIGH);
  analogWrite(ENA_B, speedCar); 
    
  Serial.println("Going Back");
}


void loop() {
  currentMillis = millis(); 
  
  if ( currentMillis - startMillis > timeLim) {
    for (int i = 0; i <= 20; i++) {
      forwardRight();    
    }
    startMillis = currentMillis; 
  }
  else{
    forward(); 
  }
}
