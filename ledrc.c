// Pin dove collegherai il segnale della ricevente
#define RC_PIN 2

// Pin per le luci di posizione
#define POSITION_LIGHTS_PIN 13
#define STROBE_LIGHTS_PIN 12
#define BEACON_LIGHTS_PIN 11

// Valore minimo per considerare il segnale "ON"
#define SIGNAL_THRESHOLD 1500

void setup() {
  // Imposta i pin delle luci come output
  pinMode(POSITION_LIGHTS_PIN, OUTPUT);
  pinMode(STROBE_LIGHTS_PIN, OUTPUT);
  pinMode(BEACON_LIGHTS_PIN, OUTPUT);

  // Imposta il pin della ricevente come input
  pinMode(RC_PIN, INPUT);

  // Avvia la comunicazione seriale per debugging (opzionale)
  Serial.begin(9600);
}

void loop() {
  // Legge il valore del segnale dal pin della ricevente
  int signal = pulseIn(RC_PIN, HIGH, 25000); // Legge la durata dell'impulso

  // Debugging (mostra il segnale sulla seriale)
  Serial.println(signal);

  // Se il segnale è attivo, esegui le sequenze di luci
  if (signal > SIGNAL_THRESHOLD) {
    // Sequenza: 3 lampeggi in 2 secondi
    for (int i = 0; i < 3; i++) {
      digitalWrite(POSITION_LIGHTS_PIN, HIGH);
      digitalWrite(STROBE_LIGHTS_PIN, HIGH);
      digitalWrite(BEACON_LIGHTS_PIN, HIGH);
      delay(200); // Lampeggio (200 ms acceso)
      digitalWrite(POSITION_LIGHTS_PIN, LOW);
      digitalWrite(STROBE_LIGHTS_PIN, LOW);
      digitalWrite(BEACON_LIGHTS_PIN, LOW);
      delay(467); // Pausa (per un totale di circa 2s)
    }

    // Pausa di 0.7 secondi
    delay(700);

    // Luci accese per 1 secondo
    digitalWrite(POSITION_LIGHTS_PIN, HIGH);
    digitalWrite(STROBE_LIGHTS_PIN, HIGH);
    digitalWrite(BEACON_LIGHTS_PIN, HIGH);
    delay(1000);

    // Luci spente per 0.7 secondi
    digitalWrite(POSITION_LIGHTS_PIN, LOW);
    digitalWrite(STROBE_LIGHTS_PIN, LOW);
    digitalWrite(BEACON_LIGHTS_PIN, LOW);
    delay(700);
  } else {
    // Spegni tutte le luci se il segnale non è attivo
    digitalWrite(POSITION_LIGHTS_PIN, LOW);
    digitalWrite(STROBE_LIGHTS_PIN, LOW);
    digitalWrite(BEACON_LIGHTS_PIN, LOW);
  }
}
