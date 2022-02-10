/* ## Universidade Federal de Ouro Preto
## Docentes: Ananda Mendes Souza(19.1.4030) e Rômulo de Oliveira Carneiro(19.1.4107)
## Bacharelado em Ciência da Computação - Estrutura de Dados II */

#include "./HPP/admin.hpp"
#include "./HPP/userGeral.hpp"

int main () {
  int opcao;

  cout << "\t\t   Escolha seu tipo de usuario:\t\t\t " << "\n";

  cout << "\t\t\t[1] - Usuário Geral\t\t\t " << "\n";
  cout << "\t\t\t[2] - Administrador\t\t\t\t " << "\n";
  cout << "\t\t\t[3] - Sair\t\t\t\t " << "\n";

  cout << "Tipo: ";
  cin >> opcao;
  switch (opcao) {
    case 1: {
      UserGeral user ("Usuario geral", 0, 0.0, 0, 1, "admin", "admin");
      user.acessarSistema(user);
      break;
    }
    case 2: {
      Administrador administrador("Administrador", 20, 5000.0, 8, 1, "admin", "admin");
      administrador.acessarSistema(administrador);
      break;
    }
    case 3: {
      break;
    }
    default:
      cout << "Esta opcao é invalida" << endl;
  };

  return 0;
}