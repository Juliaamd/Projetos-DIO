#ifndef CONTA_HPP
#define CONTA_HPP

#include <iostream>
#include <string>
#include <vector>

class Conta {
protected:
    float saldo;
    std::vector<std::string> historico;

public:
    Conta(float saldoInicial);
    virtual std::string getTipo() const = 0;
    virtual bool sacar(float valor);
    virtual void depositar(float valor);
    float getSaldo() const;
    virtual void mostrarHistorico() const;
    virtual ~Conta() {}
};

class ContaCorrente : public Conta {
public:
    ContaCorrente(float saldoInicial);
    std::string getTipo() const override;
};

class ContaSalario : public Conta {
public:
    ContaSalario(float saldoInicial);
    std::string getTipo() const override;
};

class ContaPoupanca : public Conta {
public:
    ContaPoupanca(float saldoInicial);
    std::string getTipo() const override;
};

class ContaInvestimento : public Conta {
public:
    ContaInvestimento(float saldoInicial);
    std::string getTipo() const override;
};

#endif

            realizarDeposito(contas[escolha - 5]);
        }
        else if (escolha == 9) {
            for (auto conta : contas) {
                conta->mostrarHistorico();
            }
        }
        else if (escolha != 0) {
            cout << "Opção inválida, tente novamente.\n";
        }
    } while (escolha != 0);

    logFile.close();

    for (auto c : contas)
        delete c;

    return 0;
}
