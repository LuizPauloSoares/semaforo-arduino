# 🚦 Semáforo Inteligente com Arduino

Sistema de semáforo automatizado para carros e pedestres, com sensor de luminosidade, sensor ultrassônico de presença, botão de travessia, display LCD e alertas sonoros.

## 📋 Sobre o projeto

Este projeto simula o funcionamento de um semáforo de trânsito real, integrando múltiplos sensores para tornar o sistema mais inteligente e responsivo:

- **Semáforo para carros** (vermelho, amarelo, verde)
- **Semáforo para pedestres** (vermelho, verde)
- **Botão de travessia** para o pedestre solicitar a abertura do sinal
- **Sensor de luminosidade (LDR)** para detectar ambientes escuros
- **Sensor ultrassônico (HC-SR04)** para detectar distância/presença
- **Display LCD 16x2 (I2C)** para exibir mensagens de status
- **Buzzer** para alertas sonoros durante a contagem regressiva

## 🔧 Componentes utilizados

| Componente | Quantidade |
|---|---|
| Arduino (Uno ou similar) | 1 |
| Display LCD 16x2 com módulo I2C | 1 |
| Sensor ultrassônico HC-SR04 | 1 |
| Sensor de luminosidade (LDR) | 1 |
| Buzzer | 1 |
| LED vermelho | 2 |
| LED amarelo | 1 |
| LED verde | 2 |
| Botão (push button) | 1 |
| Resistores (220Ω para LEDs) | conforme necessário |
| Protoboard e jumpers | conforme necessário |

## 🔌 Pinagem

| Componente | Pino no Arduino |
|---|---|
| LED Carro Vermelho | 7 |
| LED Carro Amarelo | 6 |
| LED Carro Verde | 5 |
| LED Pedestre Vermelho | 4 |
| LED Pedestre Verde | 3 |
| Botão de travessia | 2 |
| Buzzer | 10 |
| Sensor ultrassônico - Trig | 12 |
| Sensor ultrassônico - Echo | 11 |
| Sensor de luminosidade (LDR) | A0 |
| Display LCD I2C - SDA | A4 |
| Display LCD I2C - SCL | A5 |

> O endereço I2C do display usado no código é `0x27`. Caso o seu módulo use outro endereço, rode um sketch de I2C Scanner para identificar o endereço correto e ajuste na linha `LiquidCrystal_I2C lcd(0x27, 16, 2);`.

## ⚙️ Como funciona

1. **Estado padrão**: o semáforo para carros fica aberto (verde) e o dos pedestres fechado (vermelho).
2. **Ambiente escuro**: se o sensor de luminosidade detectar pouca luz, o sistema exibe um aviso no LCD e pisca o LED amarelo, sinalizando atenção redobrada (modo noturno).
3. **Botão pressionado**: ao pressionar o botão de travessia (respeitando um intervalo mínimo de 5 segundos desde a última travessia), o semáforo de carros fecha progressivamente (verde → amarelo → vermelho) e libera a passagem do pedestre.
4. **Contagem regressiva**: durante a travessia, o LCD e o buzzer avisam a contagem regressiva de 10 a 1 antes do sinal do pedestre fechar novamente.
5. **Sensor ultrassônico**: mede continuamente a distância de objetos/pessoas próximas ao semáforo e emite alertas sonoros diferentes dependendo da proximidade.

## 📚 Bibliotecas necessárias

Antes de compilar, instale pela Arduino IDE (**Sketch → Incluir Biblioteca → Gerenciar Bibliotecas**):

- `LiquidCrystal I2C` (por Frank de Brabander ou similar)

## ▶️ Como usar

1. Monte o circuito seguindo a tabela de pinagem acima.
2. Abra o arquivo `.ino` na Arduino IDE.
3. Instale a biblioteca `LiquidCrystal_I2C` caso ainda não tenha.
4. Selecione a placa e a porta correta em **Ferramentas**.
5. Faça o upload do código para o Arduino.
6. Abra o **Monitor Serial** (9600 baud) para acompanhar os logs do sistema.

## 🚧 Melhorias futuras

- [ ] Adicionar pull-up/pull-down explícito no botão para evitar leituras falsas
- [ ] Migrar para ESP32 com controle via WiFi
- [ ] Adicionar contagem regressiva também no semáforo de carros
- [ ] Registrar histórico de travessias

## 👤 Autor

Luiz Paulo Soares
- [LinkedIn](https://www.linkedin.com/in/luiz-paulo-soares/)
- [Instagram](https://instagram.com/lu1z_st)

## 📄 Licença

Este projeto é livre para fins de estudo e aprendizado.
