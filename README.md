# Temporizador One Shot - Controle de LEDs

Este projeto implementa um temporizador **de um disparo (one-shot)** usando a função `add_alarm_in_ms()` do Pico SDK para controlar LEDs com um botão.

## Requisitos

- Microcontrolador **Raspberry Pi Pico W**
- 3 LEDs (**azul, vermelho e verde**)
- 3 Resistores de **330Ω**
- 1 Botão (**Pushbutton**)
- Ambiente de desenvolvimento **VS Code** com **Pico SDK**
- Simulação no **Wokwi** integrada ao VS Code

## Descrição

- Ao pressionar o **botão**, todos os LEDs são ligados.
- Após **3 segundos**, o LED azul é desligado.
- Após mais **3 segundos**, o LED vermelho é desligado.
- O LED verde se apaga após mais **3 segundos**.
- O botão **só pode ser pressionado novamente** quando todos os LEDs estiverem apagados.

### Instruções

- Utiliza **call-backs** para controlar os LEDs de forma assíncrona.
- Implementação de **software debounce** (opcional).
- Proteção para evitar múltiplos acionamentos enquanto a sequência ainda está em execução.

### Instruções de uso
- Basta pressionar o botão uma única vez que irá ocorrer o que foi descrito
- Se quiser pode pressionar diversas vezes durante o funcionamento que nada irá ocorrer.


