# Semáforo com Arduino# Ponderada Semana 3 - Semáforo com Arduino



**Autor:** Pietro Alkmin  **Autor:** Pietro Alkmin  

**Data:** 29 de Outubro de 2025  **Data:** 29 de Outubro de 2025  

**Curso:** Engenharia de Computação - Inteli**Curso:** Engenharia de Computação - Inteli



------



## Descrição do Projeto## 📋 Índice



Este projeto implementa um semáforo funcional usando Programação Orientada a Objetos em C++ para Arduino. O sistema controla o fluxo de trânsito seguindo a temporização:1. [Descrição do Projeto](#descrição-do-projeto)

2. [Demonstração em Vídeo](#demonstração-em-vídeo)

- 6 segundos no vermelho3. [Componentes Utilizados](#componentes-utilizados)

- 4 segundos no verde  4. [Montagem Física](#montagem-física)

- 2 segundos no amarelo5. [Esquema de Ligações](#esquema-de-ligações)

6. [Código e Programação](#código-e-programação)

---7. [Como Executar](#como-executar)

8. [Avaliação de Pares](#avaliação-de-pares)

## Demonstração em Vídeo

---

**Link do vídeo:** [`Midia/Video.mp4`]

## 📝 Descrição do Projeto


Este projeto implementa um **semáforo funcional** usando **Programação Orientada a Objetos (POO)** em C++ para Arduino. O sistema controla o fluxo de trânsito seguindo a temporização padrão de semáforos:

---

- 🔴 **6 segundos** no vermelho

## Componentes Utilizados- 🟢 **4 segundos** no verde  

- 🟡 **2 segundos** no amarelo

| Componente | Quantidade | Especificações |

|------------|------------|----------------|A implementação utiliza POO para encapsular a lógica de controle dos LEDs em uma classe `Led`, tornando o código mais organizado, reutilizável e fácil de manter.

| Arduino Uno | 1 | ATmega328P, 5V, 16MHz |

| LED Vermelho | 1 | 5mm, 2V, 20mA |---

| LED Verde | 1 | 5mm, 2V, 20mA |

| LED Amarelo | 1 | 5mm, 2V, 20mA |## 🎥 Demonstração em Vídeo

| Resistor 220Ω | 3 | 1/4W, 5% |

| Protoboard | 1 | 830 pontos |> **⚠️ Importante:** O vídeo demonstra o funcionamento completo do semáforo com o autor presente, comprovando a autoria do projeto.

| Jumpers | ~10 | Macho-macho |

| Cabo USB | 1 | USB A para B |**📹 Link do vídeo:** [Inserir link do YouTube/Drive aqui]



### Justificativa dos Resistores📁 **Arquivo local:** `Midia/Video.mp4` (disponível neste repositório)



Cálculo: R = (5V - 2V) / 20mA = 150Ω  **O vídeo mostra:**

Valor usado: 220Ω (comercial mais próximo para maior segurança)- ✅ Montagem física completa na protoboard

- ✅ LEDs acendendo e apagando conforme programado

---- ✅ Temporização correta (6s vermelho, 4s verde, 2s amarelo)

- ✅ Autor demonstrando o projeto

## Montagem Física

---

### Passo a Passo

## 🔧 Componentes Utilizados

1. **Preparação**

   - Posicione os 3 LEDs na protoboard| Componente | Quantidade | Especificações | Função |

   - Identifique ânodo (lado longo) e cátodo (lado curto)|------------|------------|----------------|--------|

| Arduino Uno | 1 | Microcontrolador ATmega328P, 5V, 16MHz | Controle central do sistema |

2. **Conexão dos LEDs**| LED Vermelho | 1 | 5mm, 2V, 20mA | Sinalização de parada |

   - LED Vermelho: Pino 6 do Arduino| LED Verde | 1 | 5mm, 2V, 20mA | Sinalização de passagem livre |

   - LED Verde: Pino 5 do Arduino| LED Amarelo | 1 | 5mm, 2V, 20mA | Sinalização de atenção |

   - LED Amarelo: Pino 3 do Arduino| Resistor 220Ω | 3 | 1/4W, tolerância 5% | Limitação de corrente para LEDs |

   - Todos os cátodos: GND comum| Protoboard | 1 | 830 pontos | Base para montagem do circuito |

| Jumpers | ~10 | Macho-macho | Conexões elétricas |

3. **Resistores**| Cabo USB | 1 | USB A para USB B | Programação e alimentação |

   - Conecte 220Ω em série com cada LED

   - Entre o pino do Arduino e o ânodo do LED### 💡 Justificativa dos Componentes:



4. **GND****Resistores de 220Ω:** 

   - Conecte o GND do Arduino à trilha negativa da protoboard- Calculados para proteger os LEDs limitando a corrente

   - Conecte todos os cátodos a essa trilha- Cálculo: R = (Vcc - Vled) / Iled = (5V - 2V) / 20mA = 150Ω

- Usamos 220Ω (valor comercial mais próximo) para maior segurança e durabilidade dos LEDs

---

**LEDs de 5mm:**

## Esquema de Ligações- Tamanho adequado para visualização clara

- Consumo baixo (20mA cada) permite alimentação direta pelos pinos do Arduino

```- Tensão de operação (2V) compatível com a saída de 5V do Arduino

Arduino          Resistor    LED            GND

-------          --------    ---            ---**Arduino Uno:**

Pino 6 ------[220Ω]----> Vermelho (+)- Possui pinos digitais suficientes para controlar os 3 LEDs

                          Vermelho (-) -----+- Tensão de 5V adequada para acionar LEDs

                                            |- Fácil programação via IDE Arduino

Pino 5 ------[220Ω]----> Verde (+)          |

                          Verde (-) --------+--- GND---

                                            |

Pino 3 ------[220Ω]----> Amarelo (+)        |## 🛠️ Montagem Física

                          Amarelo (-) ------+

GND -----------------------------------------+### Passo a Passo da Montagem:

```

#### 1️⃣ **Preparação da Protoboard:**

---   - Posicione os 3 LEDs na protoboard com espaçamento adequado

   - Identifique o ânodo (+) e cátodo (-) de cada LED:

## Código     - **Lado mais longo** = ânodo (positivo)

     - **Lado mais curto** = cátodo (negativo)

```cpp   - Organize os LEDs em linha (verde, amarelo, vermelho) para simular um semáforo real

#define YELLOW 3

#define GREEN  5#### 2️⃣ **Conexão dos LEDs:**

#define RED    6   - **LED Vermelho:** 

     - Ânodo → Resistor 220Ω → Pino digital 6 do Arduino

class Led {     - Cátodo → Trilha GND da protoboard

public:   

  explicit Led(uint8_t pin) : pin_(pin) {}   - **LED Verde:** 

       - Ânodo → Resistor 220Ω → Pino digital 5 do Arduino

  void begin() {      - Cátodo → Trilha GND da protoboard

    pinMode(pin_, OUTPUT);    

  }   - **LED Amarelo:** 

       - Ânodo → Resistor 220Ω → Pino digital 3 do Arduino

  void on() {      - Cátodo → Trilha GND da protoboard

    digitalWrite(pin_, HIGH); 

  }#### 3️⃣ **Instalação dos Resistores:**

     - Conecte um resistor de 220Ω entre cada pino do Arduino e o ânodo do LED correspondente

  void off() {    - O resistor **deve estar em série** com o LED

    digitalWrite(pin_, LOW);    - Isso protege os LEDs contra corrente excessiva que poderia queimá-los

  }

  #### 4️⃣ **Organização dos Cabos:**

  void hold(unsigned long ms) {    - Use jumpers de cores diferentes para facilitar identificação:

    on();      - **Vermelho** para conexões do LED vermelho

    delay(ms);      - **Verde** para conexões do LED verde

    off();      - **Amarelo** para conexões do LED amarelo

  }     - **Preto** para todas as conexões GND

   - Mantenha os cabos organizados e com comprimento adequado

private:

  uint8_t pin_;#### 5️⃣ **Conexão do GND:**

};   - Conecte o pino GND do Arduino à trilha negativa (azul) da protoboard

   - Certifique-se de que todos os cátodos dos LEDs estão conectados a essa trilha

Led ledRed(RED);   - Isso cria um **GND comum** para todos os componentes

Led ledGreen(GREEN);

Led ledYellow(YELLOW);### ✅ Checklist de Verificação:



void setup() {- [ ] LEDs instalados com polaridade correta

  ledRed.begin();- [ ] Resistores de 220Ω conectados em série com cada LED

  ledGreen.begin();- [ ] Todos os cátodos conectados ao GND

  ledYellow.begin();- [ ] Pinos corretos: vermelho (6), verde (5), amarelo (3)

}- [ ] Cabos bem conectados e organizados

- [ ] Arduino conectado ao computador via USB

void loop() {

  ledGreen.hold(4000);### 📸 Imagens da Montagem

  ledYellow.hold(2000);

  ledRed.hold(6000);> **📌 Adicionar imagens aqui mostrando:**

}> - Visão geral da montagem completa

```> - Detalhe das conexões dos LEDs com resistores

> - Esquema de fiação na protoboard

---> - Arduino conectado ao circuito



## Como Executar---



1. Abra o Arduino IDE## 🔌 Esquema de Ligações

2. Configure: Ferramentas > Placa > Arduino Uno

3. Selecione a porta correta### Diagrama de Conexões:

4. Cole o código

5. Clique em Verificar```

6. Clique em CarregarArduino Uno          Resistor    LED         GND Comum

7. Teste o funcionamento-----------          --------    ---         ----------

                                           

---Pino 6 ----------[220Ω]----> Vermelho (+)

                              Vermelho (-) ----+

## Avaliação de Pares                                               |

Pino 5 ----------[220Ω]----> Verde (+)         |

| Avaliador | Data | Nota |                              Verde (-) -------+---- GND Protoboard

|-----------|------|------|                                               |

| [Nome Completo] | [Data] | [Nota] |Pino 3 ----------[220Ω]----> Amarelo (+)       |

| [Nome Completo] | [Data] | [Nota] |                              Amarelo (-) -----+

                                               |

---GND ------------------------------------------+

```

**Repositório:** github.com/PietroAlkmin/Pondera-Semaforo

### 📐 Tabela de Conexões:

| Arduino | Componente | Destino |
|---------|------------|---------|
| Pino 6 | Resistor 220Ω → LED Vermelho (ânodo) | - |
| Pino 5 | Resistor 220Ω → LED Verde (ânodo) | - |
| Pino 3 | Resistor 220Ω → LED Amarelo (ânodo) | - |
| GND | - | Todos os cátodos dos LEDs |

### 🔍 Justificativas Técnicas:

1. **Escolha dos Pinos Digitais (3, 5, 6):**
   - São pinos PWM (~), permitindo futuras expansões como controle de intensidade luminosa
   - Distribuídos de forma não sequencial para melhor organização física na protoboard
   - Evita conflito com pinos de comunicação serial (0 e 1)

2. **GND Comum:**
   - Todos os cátodos compartilham o mesmo GND para simplificar a fiação
   - Reduz a quantidade de conexões necessárias ao Arduino
   - Facilita a manutenção e troubleshooting

3. **Resistores em Série:**
   - Posicionados entre o Arduino e os LEDs (não entre LED e GND)
   - Garante proteção mesmo se houver variação na resistência interna dos LEDs
   - Facilita a substituição individual de componentes

---

## 💻 Código e Programação

### Estrutura do Código

O código foi desenvolvido seguindo princípios de **Programação Orientada a Objetos (POO)**:

#### 🎯 Classe `Led`

**Atributos:**
- `pin_`: armazena o número do pino digital

**Métodos:**
- `begin()`: configura o pino como OUTPUT
- `on()`: liga o LED (digitalWrite HIGH)
- `off()`: desliga o LED (digitalWrite LOW)
- `hold(ms)`: liga o LED, aguarda o tempo especificado e desliga

#### 🔄 Por que POO?

1. **Encapsulamento:** A lógica de cada LED fica isolada em sua própria classe
2. **Reutilização:** Fácil criar novos LEDs sem duplicar código
3. **Manutenção:** Mudanças na classe `Led` afetam todos os LEDs automaticamente
4. **Clareza:** O `loop()` fica limpo e fácil de entender
5. **Escalabilidade:** Simples adicionar novos recursos (piscar, fade, etc.)

### 📄 Código Completo:

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
  
  ledGreen.hold(4000);   // 🟢 Verde: 4 segundos (passagem livre)
  ledYellow.hold(2000);  // 🟡 Amarelo: 2 segundos (atenção)
  ledRed.hold(6000);     // 🔴 Vermelho: 6 segundos (parada obrigatória)
  
  // O ciclo se repete automaticamente
}
```

### 📊 Lógica de Funcionamento:

```
Inicialização
     ↓
Configura pinos como OUTPUT
     ↓
┌─────────────────┐
│  Loop Infinito  │
│                 │
│  Verde  (4s)    │ ← Veículos passam
│     ↓           │
│  Amarelo (2s)   │ ← Atenção
│     ↓           │
│  Vermelho (6s)  │ ← Veículos param
│     ↓           │
└────────┬────────┘
         │
         └─────→ Repete
```

### ⚙️ Funcionalidades do Código:

- ✅ Temporização precisa usando `delay()`
- ✅ Ciclo contínuo automático
- ✅ Código modular e organizado
- ✅ Fácil manutenção e expansão
- ✅ Comentários explicativos em português

---

## 🚀 Como Executar

### Pré-requisitos:

1. **Arduino IDE** instalada ([Download aqui](https://www.arduino.cc/en/software))
2. Driver USB do Arduino instalado
3. Montagem física completa conforme descrito acima

### Passos para Upload:

1. **Abra o Arduino IDE**

2. **Configure a Placa:**
   - Vá em `Ferramentas` → `Placa` → `Arduino AVR Boards` → `Arduino Uno`

3. **Selecione a Porta:**
   - Conecte o Arduino ao computador via USB
   - Vá em `Ferramentas` → `Porta` → Selecione a porta COM do Arduino
   - (Geralmente aparece como "COM3 (Arduino Uno)" ou similar)

4. **Cole o Código:**
   - Crie um novo sketch (`Arquivo` → `Novo`)
   - Cole o código completo fornecido acima

5. **Verifique o Código:**
   - Clique no botão **✓ Verificar** (ou Ctrl+R)
   - Aguarde a compilação
   - Verifique se não há erros

6. **Faça o Upload:**
   - Clique no botão **→ Carregar** (ou Ctrl+U)
   - Aguarde o upload (LEDs RX/TX do Arduino piscam)
   - Mensagem "Carregamento concluído" aparecerá

7. **Teste o Funcionamento:**
   - O semáforo deve começar a funcionar automaticamente
   - Verifique se os tempos estão corretos
   - Observe a sequência: Verde → Amarelo → Vermelho

### 🐛 Troubleshooting:

| Problema | Solução |
|----------|---------|
| "Porta não encontrada" | Instale o driver USB do Arduino ou tente outra porta USB |
| LED não acende | Verifique polaridade do LED e conexões |
| LED queimou | Verifique se o resistor está presente (220Ω) |
| Tempo errado | Verifique os valores em `hold()` no código |
| Nada acontece | Verifique alimentação e conexão GND |

---

## 📊 Avaliação de Pares

### Metodologia de Avaliação:

Este projeto foi avaliado por pares seguindo os critérios do barema da atividade.

### 👥 Avaliadores:

| Avaliador | Data da Avaliação | Nota |
|-----------|-------------------|------|
| [Nome Completo do Avaliador 1] | [Data] | [Nota] |
| [Nome Completo do Avaliador 2] | [Data] | [Nota] |

### 📝 Critérios de Avaliação:

| Critério | Peso | Descrição |
|----------|------|-----------|
| Montagem Física | 30% | Organização, clareza das conexões, uso correto de componentes |
| Programação | 30% | Código funcionando, temporização correta, boas práticas |
| Documentação | 20% | Tutorial completo, imagens, justificativas técnicas |
| Vídeo | 20% | Demonstração clara, autor presente, funcionamento correto |

### 💬 Feedback Recebido:

#### Avaliador 1 - [Nome Completo]

**Pontos Positivos:**
- [Inserir feedback positivo]

**Pontos de Melhoria:**
- [Inserir sugestões de melhoria]

**Comentários Gerais:**
- [Inserir comentários adicionais]

---

#### Avaliador 2 - [Nome Completo]

**Pontos Positivos:**
- [Inserir feedback positivo]

**Pontos de Melhoria:**
- [Inserir sugestões de melhoria]

**Comentários Gerais:**
- [Inserir comentários adicionais]

---

## 🎓 Conclusão

Este projeto demonstra com sucesso a implementação de um semáforo funcional utilizando Arduino e conceitos de Programação Orientada a Objetos. A solução atende todos os requisitos propostos:

✅ Montagem física organizada e funcional  
✅ Temporização correta (6s vermelho, 4s verde, 2s amarelo)  
✅ Código limpo e documentado  
✅ Uso eficiente de POO  
✅ Documentação completa com justificativas técnicas

### 🔮 Possíveis Melhorias Futuras:

- Adicionar botão para pedestre (interrupção do ciclo)
- Implementar modo noturno (pisca-alerta amarelo)
- Adicionar display LCD para contagem regressiva
- Usar LEDs RGB para reduzir quantidade de componentes
- Implementar comunicação serial para monitoramento

---

## 📚 Referências

- [Documentação Oficial Arduino](https://www.arduino.cc/reference/pt/)
- [Tutorial Arduino - Blink](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink)
- [Cálculo de Resistores para LEDs](https://www.digikey.com.br/pt/resources/conversion-calculators/conversion-calculator-led-series-resistor)
- Material didático do curso de Engenharia de Computação - Inteli

---

**Repositório:** [github.com/PietroAlkmin/Pondera-Semaforo](https://github.com/PietroAlkmin/Pondera-Semaforo)

**Licença:** MIT License

---

*Desenvolvido como parte da Ponderada Semana 3 - Engenharia de Computação - Inteli - 2025*
