# Semáforo com Raspberry Pi Pico

## Descrição
Este projeto implementa um sistema de semáforo simples utilizando a Raspberry Pi Pico e três LEDs (vermelho, amarelo e verde). O código alterna entre os estados do semáforo automaticamente a cada 3 segundos.

## Funcionamento

1. **Configuração dos LEDs:** Os pinos dos LEDs são inicializados como saída.
2. **Estado inicial:** O LED vermelho acende primeiro, indicando o estado inicial do semáforo.
3. **Timer periódico:** A função `add_repeating_timer_ms(-3000, repeating_timer_callback, NULL, &timer);` configura um temporizador que chama a função `repeating_timer_callback` a cada 3 segundos.
4. **Troca de estados:**
   - **Estado 0:** Vermelho → Amarelo  
   - **Estado 1:** Amarelo → Verde  
   - **Estado 2:** Verde → Vermelho  
5. **Loop principal:** O programa entra em um loop infinito imprimindo o estado do semáforo a cada segundo.

