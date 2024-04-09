#include <iostream>
#include <string>
using namespace std;

class Carro{
  private:
    float combustivel = 0;
  public:
    void Abastecer(float combustivel){
      this->combustivel+=combustivel;
      if (this->combustivel > 50){
        this->combustivel = 50;
      }
    }
    string Mover(int distancia){
      float combustivelconsumido = distancia / 15.0, combustivelrestante = combustivel - combustivelconsumido;
      string stringMover = "Distância percorrida: " + to_string(distancia) + " | Gasolina restante: " + to_string(combustivelrestante) + "\n";
      return stringMover;
    }
};

int main(){
  Carro carro1, carro2;
  string informacao;
  carro1.Abastecer(20);
  informacao = carro1.Mover(200);
  cout << informacao;
  carro2.Abastecer(30);
  informacao = carro2.Mover(400);
  cout << informacao;
}