# 🧩 Jogo do Labirinto em C

O jogo é simples e pode ser usado diretamente no terminal.  
Ele utiliza funções básicas em C para manipular matrizes e controlar os movimentos do jogador com as teclas W/A/S/D 

O labirinto é pequeno, mas funcional:  
- Indica quando você concluiu o jogo ao chegar na saída `E`.  
- Quando você pisa em uma armadilha `^`, perde uma vida.  
- O sistema é simples, mas pode ser aprimorado para labirintos maiores, com mais armadilhas e novos desafios.  

## Como jogar
Compile e execute no terminal:
```bash
# Linux/macOS
gcc labirinto.c -o labirinto
./labirinto

# Windows (MinGW)
gcc labirinto.c -o labirinto.exe
labirinto.exe
