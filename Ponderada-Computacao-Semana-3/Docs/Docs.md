# Ponderada Semana 3 - Semáforo com Arduino

**Autor:** Pietro Alkmin
**Data:** 29 de Outubro de 2025
**Curso:** Engenharia de Computação - Inteli

---

## Descrição do Projeto

Este projeto implementa um semáforo funcional usando Programação Orientada a Objetos (POO) em C++ para Arduino. O sistema controla o fluxo de trânsito com a seguinte temporização:
- **Vermelho:** 6 segundos
- **Verde:** 4 segundos
- **Amarelo:** 2 segundos

A lógica de controle dos LEDs é encapsulada na classe `Led`, tornando o código organizado e reutilizável.

---

## Demonstração em Vídeo

O vídeo a seguir demonstra a montagem física e o funcionamento do semáforo.

**Arquivo local:** `Midia/Video.mp4`

---

## Componentes Utilizados

| Componente | Quantidade | Especificações |
|------------|------------|----------------|
| Arduino Uno | 1 | Microcontrolador ATmega328P, 5V |
| LED Vermelho | 1 | 5mm, 2V, 20mA |
| LED Verde | 1 | 5mm, 2V, 20mA |
| LED Amarelo | 1 | 5mm, 2V, 20mA |
| Resistor 220Ω | 3 | 1/4W, tolerância 5% |
| Protoboard | 1 | 830 pontos |
| Jumpers | ~10 | Macho-macho |
| Cabo USB | 1 | USB A para USB B |

**Justificativa do Resistor:** Foi utilizado um resistor de 220Ω para limitar a corrente e proteger os LEDs. O valor é o comercial mais próximo do cálculo ideal (150Ω), garantindo maior segurança.

---

## Montagem e Conexões

### Passo a Passo da Montagem

1.  **Posicionar LEDs:** Coloque os LEDs na protoboard, identificando o terminal ânodo (mais longo) e cátodo (mais curto).
2.  **Conectar Resistores:** Conecte um resistor de 220Ω em série com o ânodo de cada LED.
3.  **Conectar Pinos do Arduino:**
    - **LED Vermelho:** Conecte o resistor ao pino digital **6**.
    - **LED Verde:** Conecte o resistor ao pino digital **5**.
    - **LED Amarelo:** Conecte o resistor ao pino digital **3**.
4.  **Conectar GND:** Conecte o pino **GND** do Arduino à trilha negativa da protoboard. Em seguida, conecte todos os terminais cátodos dos LEDs a essa mesma trilha.

### Tabela de Conexões

| Arduino | Componente | Destino |
|---------|------------|---------|
| Pino 6 | Resistor 220Ω → LED Vermelho (ânodo) | - |
| Pino 5 | Resistor 220Ω → LED Verde (ânodo) | - |
| Pino 3 | Resistor 220Ω → LED Amarelo (ânodo) | - |
| GND | - | Cátodo de todos os LEDs |

---

## Código da Programação

O código utiliza uma classe `Led` para controlar cada LED de forma independente, simplificando a lógica principal no `loop`.

```cpp
// ====================================
// PONDERADA SEMANA 3 - SEMÁFORO
// Autor: Pietro Alkmin
// Data: 29/10/2025
// ====================================

// --- Definição de Pinos ---
#define YELLOW 3
#define GREEN  5
#define RED    6

// ====================================
// CLASSE LED (POO)
// ====================================
class Led {
public:
  // Construtor: recebe o número do pino
  explicit Led(uint8_t pin) : pin_(pin) {}
  
  // Configura o pino como saída
  void begin() { 
    pinMode(pin_, OUTPUT); 
  }
  
  // Liga o LED
  void on() { 
    digitalWrite(pin_, HIGH); 
  }
  
  // Desliga o LED
  void off() { 
    digitalWrite(pin_, LOW); 
  }
  
  // Liga o LED por um tempo específico e depois desliga
  void hold(unsigned long ms) { 
    on(); 
    delay(ms); 
    off(); 
  }

private:
  uint8_t pin_;  // Pino digital do LED
};

// ====================================
// INSTÂNCIAS DOS LEDs
// ====================================
Led ledRed(RED);       // LED Vermelho no pino 6
Led ledGreen(GREEN);   // LED Verde no pino 5
Led ledYellow(YELLOW); // LED Amarelo no pino 3

// ====================================
// SETUP - Executa uma vez no início
// ====================================
void setup() {
  // Inicializa os pinos dos LEDs como OUTPUT
  ledRed.begin();
  ledGreen.begin();
  ledYellow.begin();
}

// ====================================
// LOOP - Executa continuamente
// ====================================
void loop() {
  // Sequência do semáforo:
  ledGreen.hold(4000);   // Verde: 4 segundos
  ledYellow.hold(2000);  // Amarelo: 2 segundos
  ledRed.hold(6000);     // Vermelho: 6 segundos
}
```

---

## Como Executar

1.  **Abra a IDE do Arduino.**
2.  **Configure a Placa:** Vá em `Ferramentas > Placa` e selecione `Arduino Uno`.
3.  **Selecione a Porta:** Em `Ferramentas > Porta`, escolha a porta COM correspondente ao seu Arduino.
4.  **Copie e Cole o Código:** Insira o código acima em um novo sketch.
5.  **Carregue o Código:** Clique no botão `Carregar` (seta para a direita) para enviar o programa ao Arduino.
6.  **Verifique o Funcionamento:** O semáforo iniciará a sequência de luzes automaticamente.
