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

## Instruções de Uso

1. **Clone o repositório**:
    ```sh
    git clone https://github.com/yuriccosta/temporizador_one_shot
    cd https://github.com/yuriccosta/temporizador_one_shot
    ```

2. **Configure o ambiente de desenvolvimento**:
    - Instale a extensão do vscode: Raspberry Pi Pico e configure o ambiente conforme instruções.
    - Instale a extensão do vscode: Wokwi e configure o ambiente conforme instruções.

3. **Compile o código**:
    - Abra o projeto no VS Code.
    - Aperte no botão Compile da extensão do Pico SDK.

4. **Carregue o código na Bitdoglab**:
    - Conecte a Bitdoglab ao computador.
    - Entre no modo de gravação.
    - Aperte no botão Run da extensão do Pico SDK.

5. **Rode no wokwi integrado ao vscode**:
    - Abra o arquivo diagram.json.
    - Aperte no botão Run da extensão do Wokwi.

6. **Executando o código**:
    - Pressione o botão para ligar os LEDs.
    - Observe os LEDs desligando em sequência após os intervalos de 3 segundos.
