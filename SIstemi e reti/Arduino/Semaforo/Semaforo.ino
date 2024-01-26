#define red1 12
#define yellow1 11
#define green1 10
#define red2 7
#define yellow2 6
#define green2 5

int tgre = 4000;
int tyel = 2000;
int tred = 2500;

void setup() {
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);
}

void loop() {
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, HIGH);
  delay(tred);
  digitalWrite(red2, LOW);
  digitalWrite(green2, HIGH);
  delay(tgre);
  digitalWrite(green2, LOW);
  digitalWrite(yellow2, HIGH);
  delay(tyel);


  digitalWrite(yellow2, LOW);
  digitalWrite(red2, HIGH);
  delay(tred);
  digitalWrite(red1, LOW);
  digitalWrite(green1, HIGH);
  delay(tgre);
  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);
  delay(tyel);
}