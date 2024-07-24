//#include <Servo.h>      // Thư viện điều khiển servo
//
//// Khai báo đối tượng myservo dùng để điều khiển servo
//Servo myservo;
//
//int servoPin = 12;       // Khai báo chân điều khiển servo
//
//void setup ()
//{
//    // Cài đặt chức năng điều khiển servo cho chân servoPin
//    myservo.attach(servoPin);
//    
//    Serial.begin(9600); // Mở giao tiếp Serial ở baudrate 9600
//}
//
//void loop ()
//{
//    // Xoay servo đến góc 180 độ
//    myservo.write(180);
//    Serial.println("Servo position: 180");
//    delay(1000); // Đợi 1 giây
//
//    // Xoay servo trở lại góc 0 độ
//    myservo.write(0);
//    Serial.println("Servo position: 0");
//    delay(1000); // Đợi 1 giây
//}
//====================================================================

//// Khai báo các chân kết nối đèn LED
//int ledPin1 = 2;
//int ledPin2 = 3;
//int ledPin3 = 4;
//int ledPin4 = 5;
//
//void setup() {
//    // Cài đặt các chân LED là OUTPUT
//    pinMode(ledPin1, OUTPUT);
//    pinMode(ledPin2, OUTPUT);
//    pinMode(ledPin3, OUTPUT);
//    pinMode(ledPin4, OUTPUT);
//}
//
//void loop() {
//    // Bật đèn LED 1
//    digitalWrite(ledPin1, HIGH);
//    delay(500); // Đợi 0.5 giây
//    // Tắt đèn LED 1
//    digitalWrite(ledPin1, LOW);
//    delay(500); // Đợi 0.5 giây
//
//    // Bật đèn LED 2
//    digitalWrite(ledPin2, HIGH);
//    delay(500); // Đợi 0.5 giây
//    // Tắt đèn LED 2
//    digitalWrite(ledPin2, LOW);
//    delay(500); // Đợi 0.5 giây
//
//    // Bật đèn LED 3
//    digitalWrite(ledPin3, HIGH);
//    delay(500); // Đợi 0.5 giây
//    // Tắt đèn LED 3
//    digitalWrite(ledPin3, LOW);
//    delay(500); // Đợi 0.5 giây
//
//    // Bật đèn LED 4
//    digitalWrite(ledPin4, HIGH);
//    delay(500); // Đợi 0.5 giây
//    // Tắt đèn LED 4
//    digitalWrite(ledPin4, LOW);
//    delay(500); // Đợi 0.5 giây
//}
// =============================================================

//// Khai báo các chân kết nối với module L298N
//int enA = 10;  // Chân PWM điều khiển tốc độ động cơ 1
//int in1 = 8;  // Chân điều khiển hướng động cơ 1
//int in2 = 9;  // Chân điều khiển hướng động cơ 1
//int enB = 11;  // Chân PWM điều khiển tốc độ động cơ 2
//int in3 = 7; // Chân điều khiển hướng động cơ 2
//int in4 = 6; // Chân điều khiển hướng động cơ 2
//
//void setup() {
//    // Cài đặt các chân là OUTPUT
//    pinMode(enA, OUTPUT);
//    pinMode(in1, OUTPUT);
//    pinMode(in2, OUTPUT);
//    pinMode(enB, OUTPUT);
//    pinMode(in3, OUTPUT);
//    pinMode(in4, OUTPUT);
//}
//
//void loop() {
//
//
//    // Quay động cơ 1 theo hướng ngược lại và động cơ 2 theo hướng ngược lại
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, HIGH);
//    digitalWrite(in3, HIGH);
//    digitalWrite(in4, LOW);
//    analogWrite(enA, 255); // Tốc độ động cơ 1 (tối đa)
//    analogWrite(enB, 255); // Tốc độ động cơ 2 (tối đa)
//
//}

//==============================================================================

//// Định nghĩa các chân kết nối của cảm biến siêu âm HC-SR04
//const int trigPin = A0; // Chân Trigger
//const int echoPin = A1; // Chân Echo
//
//void setup() {
//  // Khởi động serial monitor
//  Serial.begin(9600);
//  
//  // Cài đặt chế độ cho các chân
//  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);
//}
//
//void loop() {
//  // Phát tín hiệu từ chân Trigger
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//
//  // Đọc tín hiệu từ chân Echo
//  long duration = pulseIn(echoPin, HIGH);
//
//  // Tính khoảng cách dựa trên thời gian tín hiệu phản hồi
//  long distance = duration * 0.034 / 2;
//
//  // In khoảng cách ra Serial Monitor
//  Serial.print("Khoảng cách: ");
//  Serial.print(distance);
//  Serial.println(" cm");
//
//  // Chờ một khoảng thời gian ngắn trước khi đo lại
//  delay(500);
//}

// =========================================================
// code xe tránh vật cản 

#include <Servo.h> // Thư viện điều khiển servo

// Khai báo đối tượng myservo dùng để điều khiển servo
Servo myservo;

int servoPin = 12; // Chân điều khiển servo

// Định nghĩa các chân kết nối của cảm biến siêu âm HC-SR04
const int trigPin = A0; // Chân Trigger
const int echoPin = A1; // Chân Echo

// Khai báo các chân kết nối với module L298N
int enA = 10; // Chân PWM điều khiển tốc độ động cơ 1
int in1 = 9; // Chân điều khiển hướng động cơ 1
int in2 = 8; // Chân điều khiển hướng động cơ 1
int enB = 11; // Chân PWM điều khiển tốc độ động cơ 2
int in3 = 7; // Chân điều khiển hướng động cơ 2
int in4 = 6; // Chân điều khiển hướng động cơ 2

// Khai báo các chân kết nối đèn LED
int ledPin1 = 2;
int ledPin2 = 3;
int ledPin3 = 4;
int ledPin4 = 5;

void setup() {
  // Khởi động serial monitor
  Serial.begin(9600);
  
  // Cài đặt chế độ cho các chân
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  
  // Cài đặt chức năng điều khiển servo cho chân servoPin
  myservo.attach(servoPin);
  myservo.write(90); // Cảm biến siêu âm luôn hướng về phía trước
}

void loop() {
  // Kiểm tra khoảng cách phía trước
  int distanceCenter = measureDistance(90);

  if (distanceCenter < 30) {
    stopCar();
    int distanceLeft = measureDistance(150);
    int distanceRight = measureDistance(30);

    if (distanceLeft > 30 && distanceRight > 30) {
      // Nếu cả hai hướng đều không có vật cản, chọn ngẫu nhiên một hướng để rẽ
      if (distanceLeft > distanceRight) {
        turnLeft();
      } else {
        turnRight();
      }
    } else if (distanceLeft > 30) {
      // Nếu chỉ hướng trái không có vật cản
      turnLeft();
    } else if (distanceRight > 30) {
      // Nếu chỉ hướng phải không có vật cản
      turnRight();
    } else {
      // Nếu tất cả các hướng đều có vật cản, lùi lại
      moveBackward();
      delay(1000); // Lùi lại một khoảng thời gian
      stopCar();
    }
  } else {
    // Không có vật cản, tiếp tục di chuyển về phía trước
    moveForward();
  }

}

int measureDistance(int angle) {
  myservo.write(angle);
  delay(500); // Thời gian đủ để servo di chuyển đến vị trí mới
  
  // Phát tín hiệu từ chân Trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Đọc tín hiệu từ chân Echo
  long duration = pulseIn(echoPin, HIGH);

  // Tính khoảng cách dựa trên thời gian tín hiệu phản hồi
  long distance = duration * 0.034 / 2;
  
  // In khoảng cách ra Serial Monitor
  Serial.print("Khoảng cách tại góc ");
  Serial.print(angle);
  Serial.print(" là: ");
  Serial.print(distance);
  Serial.println(" cm");

  return distance;
}

void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255); // Tốc độ động cơ 1 (tối đa)
  analogWrite(enB, 255); // Tốc độ động cơ 2 (tối đa)
  Serial.println("Xe di chuyển về phía trước.");
}

void stopCar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("Xe dừng lại.");
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255); // Tốc độ động cơ 1 (tối đa)
  analogWrite(enB, 255); // Tốc độ động cơ 2 (tối đa)
  Serial.println("Xe lùi lại.");
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255); // Tốc độ động cơ 1 (tối đa)
  analogWrite(enB, 255); // Tốc độ động cơ 2 (tối đa)
  Serial.println("Xe rẽ trái.");
  delay(500); // Thời gian đủ để xe rẽ
  stopCar();
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255); // Tốc độ động cơ 1 (tối đa)
  analogWrite(enB, 255); // Tốc độ động cơ 2 (tối đa)
  Serial.println("Xe rẽ phải.");
  delay(500); // Thời gian đủ để xe rẽ
  stopCar();
}


