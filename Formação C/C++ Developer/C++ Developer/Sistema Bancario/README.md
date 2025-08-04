# 💳 Sistema Bancário em C++

Este é um projeto prático de um sistema bancário simples, desenvolvido como parte da formação **C++ Developer** da DIO.

## 🚀 Funcionalidades

- Criar e manipular 4 tipos de contas:
  - Conta Corrente
  - Conta Salário
  - Conta Poupança
  - Conta Investimento
- Depósitos e saques com atualização de saldo
- Histórico detalhado das transações
- Registro de erros em um arquivo `log.txt`

## 📌 Tecnologias e conceitos aplicados

- Linguagem C++
- Programação Orientada a Objetos (POO)
- Uso de herança e classes abstratas
- Manipulação de arquivos (`ofstream`)
- Interface via terminal (`cin`, `cout`)
- Vetores (`std::vector`)
- Formatação com `ostringstream` e `iomanip`

## 📂 Estrutura do Projeto
SistemaBancario/
├── main.cpp # Função principal com menu e interação com usuário
├── Conta.hpp # Declaração das classes base e derivadas (contas)
├── Conta.cpp # Implementação dos métodos das classes de conta
├── utils.hpp # Declaração de funções auxiliares (saque, depósito)
├── utils.cpp # Implementação das funções auxiliares
└── log.txt # Arquivo gerado em tempo de execução para logs de erro
