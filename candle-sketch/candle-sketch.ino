/*
  Sampled LED candle
*/

int dataRows[548] = {253, 253, 253, 253, 251, 252, 252, 253, 253, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 253, 253, 253, 253, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 254, 253, 253, 253, 253, 253, 253, 103, 103, 92, 124, 124, 241, 241, 133, 92, 253, 253, 114, 125, 125, 121, 121, 250, 250, 76, 76, 141, 169, 135, 135, 136, 136, 126, 121, 121, 127, 127, 147, 147, 155, 155, 160, 250, 250, 253, 253, 249, 249, 254, 249, 249, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 253, 253, 253, 253, 253, 252, 252, 254, 254, 254, 254, 250, 251, 251, 165, 165, 137, 137, 243, 253, 251, 251, 250, 250, 253, 253, 251, 251, 248, 218, 218, 222, 222, 246, 246, 252, 254, 254, 253, 253, 254, 254, 252, 252, 253, 253, 253, 254, 254, 253, 253, 238, 250, 250, 253, 253, 252, 252, 253, 253, 254, 254, 254, 253, 253, 253, 253, 253, 253, 254, 254, 254, 254, 253, 253, 254, 254, 254, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252, 252, 252, 252, 252, 253, 253, 254, 254, 253, 253, 253, 253, 253, 253, 253, 253, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252, 253, 253, 253, 253, 254, 254, 254, 254, 254, 254, 254, 253, 253, 253, 253, 253, 253, 254, 254, 253, 253, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252, 252, 252, 252, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 254, 254, 254, 254, 252, 252, 252, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 253, 253, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 254, 254, 253, 253, 252, 252, 248, 242, 242, 242, 242, 243, 243, 243, 250, 250, 251, 251, 254, 253, 253, 253, 253, 253, 253, 254, 254, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252, 252, 252, 252, 253, 253, 253, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253};
int rowIndex = 0;  // index into data rows

int outPin = 6;
int direction = 1;
int lastRow = 0; // last index in the data 
int fps = 1000/30;
int debug = 1;

void setup()
{
  lastRow = -1 + sizeof(dataRows) / sizeof(int);
  Serial.begin(4800);
  while (! Serial);
}

void loop() {
  // advance to the next position in the data array:
  analogWrite(outPin, dataRows[rowIndex]); 
  if (debug) {
    Serial.print("row value: ");
    Serial.print(dataRows[rowIndex]);
    Serial.print(", ");
    Serial.print(rowIndex);
    Serial.print(" of ");
    Serial.println(lastRow);
  }
  rowIndex += direction;
  // if we're at the end of the array...
  if (rowIndex >= lastRow) {
    direction = -1;
    rowIndex = lastRow;
    if (debug) {
      Serial.print("reached end, rowIndex is now");
      Serial.println(rowIndex);
    }
} else if(rowIndex <= 0) {
    direction = 1;
    rowIndex = 0;
    if (debug) {
      Serial.print("reached 0, rowIndex is now");
      Serial.println(rowIndex);
    }
  }

  delay(fps);  // shoot for 30fps ish
}


