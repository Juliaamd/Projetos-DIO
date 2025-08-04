#include "utils.hpp"
#include <iostream>
#include <iomanip>

void verificarESacar(Conta* conta, float valor, std::ofstream& logFile) {
    std::cout << "\nTentando sacar R$" << std::fixed << std::setprecision(2) << valor
              << " da " << conta->getTipo() << "...\n";

    if (!conta->sacar(valor)) {
        std::cerr << "[LOG DE ERRO] Saldo insuficiente na " << conta->getTipo() << "!\n";
        logFile << "[ERRO] Saldo insuficiente na " << conta->getTipo() << "\n";
    } else {
        std::cout << "Saque realizado com sucesso. Novo saldo: R$"
                  << std::fixed << std::setprecision(2) << conta->getSaldo() << "\n";
    }
}

void realizarDeposito(Conta* conta) {
    float valor;
    std::cout << "Digite o valor para depósito na " << conta->getTipo() << ": R$";
    std::cin >> valor;
    conta->depositar(valor);
    std::cout << "Depósito realizado com sucesso. Saldo atual: R$"
              << std::fixed << std::setprecision(2) << conta->getSaldo() << "\n";
}
