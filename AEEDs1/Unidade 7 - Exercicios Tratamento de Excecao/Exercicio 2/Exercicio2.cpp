#include <iostream>
#include <string>
using namespace std;

class ExcecaoValorInvalidoDado{
  private:
    int dado;
  public:
    ExcecaoValorInvalidoDado(int dado): dado(dado){}
    string getMessage(){
      return "O número " + to_string(dado) + " é inválido";
    }
};

int main(){
  try{
    int dado;
    cout << "Digite o número de lançamento do dado" << endl;
    cin >> dado;
    if (dado < 1 || dado > 6){
      throw ExcecaoValorInvalidoDado(dado);
    }
    cout << "O valor digitado foi: " << dado << endl;
  }

  catch(ExcecaoValorInvalidoDado(dado)){
    cout << dado.getMessage() << endl;
  }
}