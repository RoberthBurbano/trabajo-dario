const int luzVerde = 11;
const int luzRoja = 12;
const int luzAmarilla = 13;

/*Configuracion*/

void setup() {
  // Inicializamos los pines como salidas
  pinMode(luzVerde, OUTPUT);
  pinMode(luzRoja, OUTPUT);
  pinMode(luzAmarilla, OUTPUT);

  // Inicializamos la comunicación serial
  Serial.begin(9600);

  // Apagamos todas las luces al inicio
  apagarTodasLasLuces();
}

void loop() {
  if (Serial.available() > 0) {
    // Leemos el comando enviado desde el monitor serial
    char comando = Serial.read();

    // Validamos el comando y ejecutamos la acción correspondiente
    switch (comando) {
      case '1':
        encenderLuz(luzVerde);
        break;
      case '2':
        apagarLuz(luzVerde);
        break;
      case '3':
        encenderLuz(luzRoja);
        break;
      case '4':
        apagarLuz(luzRoja);
        break;
      case '5':
        encenderLuz(luzAmarilla);
        break;
      case '6':
        apagarLuz(luzAmarilla);
        break;
      case '7':
        encenderTodasLasLuces();
        break;
      case '8':
        apagarTodasLasLuces();
        break;
      case '9':
        modoIntermitente();
        break;
      default:
        Serial.println("Comando no reconocido.");
        break;
    }
  }
}

// Funciones auxiliares
void encenderLuz(int pin) {
  digitalWrite(pin, HIGH);
}

void apagarLuz(int pin) {
  digitalWrite(pin, LOW);
}

void encenderTodasLasLuces() {
  encenderLuz(luzVerde);
  encenderLuz(luzRoja);
  encenderLuz(luzAmarilla);
}

void apagarTodasLasLuces() {
  apagarLuz(luzVerde);
  apagarLuz(luzRoja);
  apagarLuz(luzAmarilla);
}

void modoIntermitente() {
  for (int i = 0; i < 10; i++) { // 10 ciclos de intermitencia
    encenderTodasLasLuces();
    delay(500); // Medio segundo encendido
    apagarTodasLasLuces();
    delay(500); // Medio segundo apagado
      }
}
