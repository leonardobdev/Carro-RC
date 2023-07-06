#include <SoftwareSerial.h>
SoftwareSerial bt(10, 9); // rx, tx do arduino

#define in1 2
#define in2 3
#define in3 4
#define in4 5

char c;

void setup() {

	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

	Serial.begin(9600);
	bt.begin(9600);

	Serial.println("running");

}

void loop() {

	while (!bt.available()) {}

	c = bt.read();
	Serial.println(c);

	switch (c) {
		case 'F': frente(); break;
		case 'L': esquerda(); break;
		case 'B': reverso(); break;
		case 'R': direita(); break;
		case 'G': rotacao_e(); break;
		case 'I': rotacao_d(); break;
		case 'x': parar(); break;
		case 'S': freio(); break;
		default: break;
	}
}

void ponte_h(bool a, bool b, bool c, bool d) {
	digitalWrite(in1, a);
	digitalWrite(in2, b);
	digitalWrite(in3, c);
	digitalWrite(in4, d);
}

void frente() {
	ponte_h(1, 0, 1, 0);
}
void reverso() {
	ponte_h(0, 1, 0, 1);
}
void direita() {
	ponte_h(1, 0, 0, 0);
}
void esquerda() {
	ponte_h(0, 0, 1, 0);
}
void rotacao_d() {
	ponte_h(1, 0, 0, 1);
}
void rotacao_e() {
	ponte_h(0, 1, 1, 0);
}
void parar() {
	ponte_h(0, 0, 0, 0);
}
void freio() {
	ponte_h(1, 1, 1, 1);
}