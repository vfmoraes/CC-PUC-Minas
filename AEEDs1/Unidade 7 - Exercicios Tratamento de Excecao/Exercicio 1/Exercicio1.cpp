#include <iostream>
#include <string>
using namespace std;

int main(){
  try{
    int dado;
    cout << "Digite o número de lançamento do dado" << endl;
    cin >> dado;
    if (dado < 1 || dado > 6){
      throw dado;
    }
    cout << "O valor digitado foi: " << dado << endl;
  }

  catch(int dado){
    printf("O número %d é inválido", dado);
  }
}