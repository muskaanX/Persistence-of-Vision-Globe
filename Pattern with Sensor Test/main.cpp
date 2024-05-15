#include <Adafruit_NeoPixel.h>
#include <SPIFFS.h>
#include <FS.h>

#define LEFT_LED_PIN 23
#define RIGHT_LED_PIN 18
#define HALL_SENSOR_PIN 2
#define NUMPIXELS 64

// Adafruit_NeoPixel objects for both sides
Adafruit_NeoPixel leftStrip = Adafruit_NeoPixel(NUMPIXELS, LEFT_LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel rightStrip = Adafruit_NeoPixel(NUMPIXELS, RIGHT_LED_PIN, NEO_GRB + NEO_KHZ800);

// Arrays to hold image data
uint32_t leftImage[NUMPIXELS];
uint32_t rightImage[NUMPIXELS];

// Function to parse CSV and load image data
void loadImageData(const char* filename, uint32_t* imageArray) {
  File file = SPIFFS.open(filename, "r");
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  }

  int index = 0;
  while (file.available() && index < NUMPIXELS) {
    String line = file.readStringUntil('\n');
    int r, g, b;
    sscanf(line.c_str(), "%d,%d,%d", &r, &g, &b);
    imageArray[index] = leftStrip.Color(r, g, b);
    index++;
  }

  file.close();
}

void setup() {
  // Initialize Serial for debugging
  Serial.begin(115200);

  // Initialize the LED strips
  leftStrip.begin();
  leftStrip.show(); // Initialize all pixels to 'off'
  rightStrip.begin();
  rightStrip.show(); // Initialize all pixels to 'off'

  // Initialize the Hall effect sensor pin
  pinMode(HALL_SENSOR_PIN, INPUT);

  // Initialize SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Load image data from CSV files
  loadImageData("/left_image_rgb.csv", leftImage);
  loadImageData("/right_image_rgb.csv", rightImage);
}

void loop() {
  static int magnetCount = 0;

  int sensorState = digitalRead(HALL_SENSOR_PIN); // Reading Hall Effect state for positional accuracy

  // Check if a magnet is detected (signal is 'LOW')
  if (sensorState == LOW) {
    // Calculate the current column index based on the magnet count
    int columnIndex = magnetCount % NUMPIXELS;

    // Update the LEDs with the new column data
    leftStrip.setPixelColor(0, leftImage[columnIndex]);
    rightStrip.setPixelColor(0, rightImage[columnIndex]);
    
    // Update the LEDs to display 
    leftStrip.show();
    rightStrip.show();
    
    magnetCount++; // Increment the magnet count
    if (magnetCount >= NUMPIXELS) {
      magnetCount = 0; // Reset the magnet count after 64 magnets
    }

    delay(200); // Debounce delay to avoid multiple detections from a single magnet pass
  }
}
