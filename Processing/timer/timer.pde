int last;
boolean counting = false;
int sec = 0;
int min = 0;
int outMS;

void setup() {
  last = millis();
}

void draw() {
  background(0);
  if (counting) {
    int ms = millis()-last;
    if (ms >= 59000) {
      last = millis();
      min++;
    }
    int sec = ms/1000;
    outMS = int((((ms*0.001) - int(ms*0.001))*1000));
    text(outMS, 51, 20);
    text(sec, 30, 20);
    text(min, 10, 20);
  } else {
    int ms = millis()-millis();
    int sec = ms/1000;
    int min = sec/60;
    text(ms, 50, 20);
    text(sec, 30, 20);
    text(min, 10, 20);
  }
}

void keyPressed() {
  if (key == 'b') {
    counting = !counting;
    last = millis();
    min = 0;
  } 
}