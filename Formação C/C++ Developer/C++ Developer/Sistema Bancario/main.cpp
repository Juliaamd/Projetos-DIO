#include <iostream>
#include <vector>
#include <fstream>
#include "Conta.hpp"
#include "utils.hpp"

int main() {
    std::vector<Conta*> contas;

    contas.push_back(new ContaCorrente(0));
    contas.push_back(new ContaSalario(0));
    contas.push_back(new ContaPoupanca(0));
    contas.push_back(new ContaInvestimento(0));

    std::ofstream logFile("log.txt");  

    int escolha;
    do {
        std::cout << "\n--- Menu ---\n";
        std::cout << "0 - Sair\n";
        std::cout << "1 - Sacar da Conta Corrente\n";
        std::cout << "2 - Sacar da Conta Salário\n";
        std::cout << "3 - Sacar da Conta Poupança\n";
        std::cout << "4 - Sacar da Conta Investimento\n";
        std::cout << "5 - Depositar na Conta Corrente\n";
        std::cout << "6 - Depositar na Conta Salário\n";
        std::cout << "7 - Depositar na Conta Poupança\n";
        std::cout << "8 - Depositar na Conta Investimento\n";
        std::cout << "9 - Mostrar histórico de todas as contas\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        if (escolha >= 1 && escolha <= 4) {
            float valor;
            std::cout << "Digite o valor para saque: R$";
            std::cin >> valor;
            verificarESacar(contas[escolha - 1], valor, logFile);
        } 
        else if (escolha >= 5 && escolha <= 8) {
            realizarDeposito(contas[escolha - 5]);
        }
        else if (escolha == 9) {
            for (auto conta : contas) {
                conta->mostrarHistorico();
            }
        }
        else if (escolha != 0) {
            std::cout << "Opção inválida, tente novamente.\n";
        }
    } while (escolha != 0);

    logFile.close();

    for (auto c : contas)
        delete c;

    return 0;
}
