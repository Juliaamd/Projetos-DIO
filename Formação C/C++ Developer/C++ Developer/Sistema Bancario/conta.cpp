#include "Conta.hpp"
#include <sstream>
#include <iomanip>

Conta::Conta(float saldoInicial) : saldo(saldoInicial) {}

bool Conta::sacar(float valor) {
    if (valor <= saldo) {
        saldo -= valor;
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << "Saque: -R$" << valor;
        historico.push_back(oss.str());
        return true;
    }
    return false;
}

void Conta::depositar(float valor) {
    saldo += valor;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << "Depósito: +R$" << valor;
    historico.push_back(oss.str());
}

float Conta::getSaldo() const {
    return saldo;
}

void Conta::mostrarHistorico() const {
    std::cout << "\nHistórico da " << getTipo() << ":\n";
    for (const auto& linha : historico)
        std::cout << linha << std::endl;
}

ContaCorrente::ContaCorrente(float saldoInicial) : Conta(saldoInicial) {}

std::string ContaCorrente::getTipo() const {
    return "Conta Corrente";
}

ContaSalario::ContaSalario(float saldoInicial) : Conta(saldoInicial) {}

std::string ContaSalario::getTipo() const {
    return "Conta Salário";
}

ContaPoupanca::ContaPoupanca(float saldoInicial) : Conta(saldoInicial) {}

std::string ContaPoupanca::getTipo() const {
    return "Conta Poupança";
}

ContaInvestimento::ContaInvestimento(float saldoInicial) : Conta(saldoInicial) {}

std::string ContaInvestimento::getTipo() const {
    return "Conta Investimento";
}
