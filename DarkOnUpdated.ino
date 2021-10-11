int sensorValue;
int distance;

#define DETECTION_THRESHOLD_LOWER 280
#define DETECTION_THRESHOLD_UPPER 512

#define DARKMODE_OPERATION_THRESHOLD 1000

int state_flag = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  sensorValue = analogRead(A0);

  // Sensor in Light Mode
  if (sensorValue >= DETECTION_THRESHOLD_LOWER && sensorValue <= DETECTION_THRESHOLD_UPPER)
  {
    Serial.print("Distance: ");
    distance = 28250 / (sensorValue - 229.5);
    Serial.print(distance);
    Serial.println("cm");
  }

  // Sensor in Dark Mode
  if (state_flag == 0 && sensorValue > DARKMODE_OPERATION_THRESHOLD)
  {
    state_flag = 1;
  }

  if (state_flag == 1 && sensorValue >= DETECTION_THRESHOLD_LOWER && sensorValue <= DETECTION_THRESHOLD_UPPER)
  {
    state_flag = 2;
  }

  if (state_flag == 2 && sensorValue > DARKMODE_OPERATION_THRESHOLD)
  {
    state_flag = 0;
    Serial.print("Object Detected");
  }
  delay(200);
}
