# CP2_Edge
Turma: 1ESPH Integrantes: Arthur Fellipe, Eduardo Pires, Leonardo Munhoz

LINK DO WOKWI: https://wokwi.com/projects/395243571270880257

## Componentes Utilizados:

Sensores:

- Sensor de temperatura e umidade DHT22
- Sensor de luz (sensor analógico, como o LDR)

Display:
- Liquid Crystal (LCD) 16x2
- LEDs e buzzer:
- LED verde
- LED amarelo
- LED vermelho
- Buzzer

Conexão:
- Placa Arduino
- Tábua de ensaio
- Fios de ligação em ponte

## Montagem
1 - Coloque o sensor DHT22 e o sensor de luz na placa de ensaio.

2 - Conecte o sensor DHT22 ao Arduino da seguinte forma:
- VCC para 5V
- GND para GND
- DATA para D6 (DHTPIN)

3 - Conecte o sensor de luz ao Arduino da seguinte forma:
- VCC para 5V
- GND para GND
- OUT para A0 (sensor de luz)

4 - Linke o LCD e conecte-o ao Arduino da seguinte forma:
- VSS para GND
- VDD para 5V
- RS para D12
- EN ao DPIN 11
- D4 ao DPIN 10
- D5 ao DPIN 9
- D6 ao DPIN 8
- D7 ao DPIN 7
- LE para 5V

5 - Conecte os LEDs e a campainha ao Arduino da seguinte forma:
- LED verde:
Perna longa (ânodo) para D4 (LED verde)
Perna curta (cátodo) para um resistor de 220 ohms e depois para GND
- LED amarelo:
Perna longa (ânodo) para D3 (LED amarelo)
Perna curta (cátodo) para um resistor de 220 ohms e depois para GND
- LED vermelho:
Perna longa (ânodo) para D2 (redLED)
Perna curta (cátodo) para um resistor de 220 ohms e depois para GND
- Buzzer:
Uma perna para D5 (campainha)
Outra perna para um resistor de 220 ohms e depois para GND

6 - Alimente a placa Arduino usando uma fonte de alimentação apropriada (USB, bateria ou adaptador de energia).

7 - Carregue o código fornecido na placa Arduino.

![image](https://github.com/tultaa/CP2_Edge/assets/78042666/f53b9ec3-a25b-4f18-8981-1d2c9fefdd56)

  
Agora, você deve ter um circuito funcional que exibe informações de temperatura, umidade e nível de luz no LCD, junto com alertas de LED e campainha com base no nível de luz.
O código também utiliza diversas variáveis ​​para armazenar dados, como temperatura, umidade e valores de luz, bem como variáveis ​​para controlar o tempo do display e dos LEDs, o código estará aqui no github, na pasta cp2edge.
