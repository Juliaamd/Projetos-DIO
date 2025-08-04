#ifndef UTILS_HPP
#define UTILS_HPP

#include <fstream>
#include "Conta.hpp"

void verificarESacar(Conta* conta, float valor, std::ofstream& logFile);
void realizarDeposito(Conta* conta);

#endif
