# Semáforo básico em Arduino (POO)

Este projeto implementa um **semáforo simples** usando **Programação Orientada a Objetos** em C++ para Arduino.
A ideia é encapsular a lógica de um LED (ligar, desligar, configurar pino) dentro de uma classe `Led`, deixando o `loop()` limpo e fácil de entender.

---

## Como foi feito

1. **Modelagem em POO**

   * Criamos uma **classe `Led`** com:

     * um **atributo** `pin_` (número do pino digital);
     * **métodos** `begin()` (configura pino como `OUTPUT`), `on()` (HIGH), `off()` (LOW) e `hold(ms)` (liga, espera, desliga).
   * Instanciamos três objetos `Led` (vermelho, verde e amarelo).
   * No `loop()`, executamos a sequência: **verde → amarelo → vermelho** com tempos definidos.

2. **Por que POO aqui?**

   * **Clareza:** o comportamento de “um LED” fica num só lugar.
   * **Reuso:** se você quiser outro LED/padrão, é só instanciar mais um `Led`.
   * **Evolução fácil:** depois dá para adicionar efeitos (piscar, PWM) sem bagunçar o `loop()`.

---

## Requisitos

* **Arduino IDE** (qualquer versão recente)
* Uma placa compatível (ex.: **Arduino Uno/Nano/Mega**)
* 3 LEDs (vermelho, verde, amarelo)
* 3 resistores (220–330 Ω)
* Jumpers e protoboard

---

## Ligações (Wiring)

* **LED VERMELHO** → pino **6** (via resistor) e GND
* **LED VERDE** → pino **5** (via resistor) e GND
* **LED AMARELO** → pino **3** (via resistor) e GND

> O lado **mais longo** do LED (ânodo) vai ao **pino digital** através do resistor; o lado **curto** (cátodo) vai ao **GND**.

---

## Código

Copie e cole no **Arduino IDE** e faça o upload:

```cpp
// --- pinos ---
#define YELLOW 3
#define GREEN  5
#define RED    6

// Classe mínima pra um LED
class Led {
public:
  explicit Led(uint8_t pin) : pin_(pin) {}
  void begin() { pinMode(pin_, OUTPUT); }
  void on()    { digitalWrite(pin_, HIGH); }
  void off()   { digitalWrite(pin_, LOW); }
  void hold(unsigned long ms) { on(); delay(ms); off(); }

private:
  uint8_t pin_;
};

// Instâncias
Led ledRed(RED);
Led ledGreen(GREEN);
Led ledYellow(YELLOW);

void setup() {
  ledRed.begin();
  ledGreen.begin();
  ledYellow.begin();
}

void loop() {
  ledGreen.hold(4000);  // verde 4s
  ledYellow.hold(2000); // amarelo 2s
  ledRed.hold(6000);    // vermelho 6s
}
```

---

## Como rodar

1. Abra o **Arduino IDE**.
2. Selecione a sua placa e porta em **Ferramentas → Placa/Porta**.
3. Cole o código acima em um novo sketch.
4. Clique em **Verificar** (compilar) e depois em **Carregar** (upload).

---

## Personalização

* **Tempos**: altere os valores em `hold(...)` no `loop()` (em milissegundos).
* **Pinos**: mude os `#define` (`RED`, `GREEN`, `YELLOW`) para os pinos que você estiver usando.
* **Efeito pisca-alerta** (exemplo rápido):

  ```cpp
  void pisca(Led& led, int vezes, unsigned long ms) {
    for (int i = 0; i < vezes; ++i) { led.on(); delay(ms); led.off(); delay(ms); }
  }
  ```

---

## Dúvidas comuns (Troubleshooting)

* **Nada acende:** confira a porta/placa no IDE e as ligações (ânodo no pino via resistor, cátodo no GND).
* **LED muito fraco:** verifique o valor do resistor (220–330 Ω é o usual).
* **Ordem errada:** troque os pinos nos `#define` ou ajuste a ordem das chamadas no `loop()`.

---

## Próximos passos (se quiser evoluir)

* Criar uma classe `Semaforo` que recebe três `Led` e controla a sequência.
* Adicionar **botão** para trocar de modo (normal ↔ pisca-alerta).
* Usar **`millis()`** no lugar de `delay()` para permitir tarefas em paralelo (sem bloquear).

---

Se quiser, eu deixo isso organizado em arquivos separados (`Led.h`/`Led.cpp`) ou adiciono um modo de **pisca-alerta** com um botão. Quer?
