#include <iostream>
#include <string>
using namespace std;

class Pessoa{
  private:
    string nome;
    int idade;
    float altura;
  public:
    Pessoa(string nome, int idade, float altura): nome(nome), idade(idade), altura(altura){}
    void SetNome(string nome){
      this->nome = nome;
    }
    void SetIdade(int idade){
      this->idade = idade;
    }
    void SetAltura(float altura){
      this->altura = altura;
    }
    string getNome(){
      return nome;
    }
    int getIdade(){
      return idade;
    }
    float getAltura(){
      return altura;
    }
    void Imprimir(){
      cout << "Nome:" << nome << " | " << "Idade:" << idade << " | " << "Altura:" << altura << endl;
    }
};

int main(){
  Pessoa novaPessoa("Maria", 24, 1.69), outraPessoa("João", 24, 1.96);
  novaPessoa.Imprimir();
  outraPessoa.Imprimir();
  
}