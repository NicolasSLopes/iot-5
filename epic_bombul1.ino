// Pinos dos LEDs
int ledVerde = 8;
int ledAmarelo = 9;
int ledVermelho = 10;

// Pino do sensor LM35
int sensorTemp = A0;

// Variáveis
int leitura;
float tensao;
float temperatura;

void setup() {
  // Configurando os LEDs como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  // Inicia o monitor serial
  Serial.begin(9600);
}

void loop() {
  // Ler o valor do sensor
  leitura = analogRead(sensorTemp);

  // Converter a leitura para tensão
  tensao = leitura * 5.0 / 1024.0;

  // Converter a tensão para temperatura
  // O LM35 fornece 10 mV para cada 1 °C
  temperatura = tensao * 100;

  // Mostrar a temperatura no Monitor Serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // Apagar todos os LEDs
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  // Verificar a faixa de temperatura
  if (temperatura < 20) {
    // Baixa temperatura
    digitalWrite(ledVerde, HIGH);
  }
  else if (temperatura < 30) {
    // Temperatura intermediária
    digitalWrite(ledAmarelo, HIGH);
  }
  else {
    // Alta temperatura
    digitalWrite(ledVermelho, HIGH);
  }

  // Esperar 1 segundo antes da próxima leitura
  delay(1000);
}