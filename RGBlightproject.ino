const int ldrPin = A0;
const int redPin = 11;
const int greenPin = 9;
const int bluePin = 10;

const int dark = 700;

void setup() {
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
Serial.begin(9600);
}

void loop() {
int lightLevel = analogRead(ldrPin); // 0 = bright, 1023 = dark
Serial.println(lightLevel);

if (lightLevel > dark) {
int brightness = map(lightLevel, dark, 1023, 50, 255);
brightness = constrain(brightness, 0, 255);

fadeColors(brightness);
} else {
// Turn off RGB when it's too bright
fadeColors(0);
}

delay(50);
}

// Function to fade RGB colors based on brightness
void fadeColors(int brightness) {
analogWrite(redPin, brightness); // Red gets brighter
analogWrite(greenPin, 255 - brightness); // Green fades out
analogWrite(bluePin, brightness / 2); // Blue stays dimmer
}
