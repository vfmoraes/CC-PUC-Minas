#include <iostream>
using namespace std;

class AnimalEstimacao{
    private:
    string nome;
    string raca;
    public:
    void caminha(){}
    AnimalEstimacao(string nome, string raca){}
};

class Cachorro: public AnimalEstimacao{
    public:
    void latir(){
        printf("Latindo AU AU\n");
    }
    Cachorro(string nome, string raca):AnimalEstimacao(nome,raca){}
};

class Gato: public AnimalEstimacao{
    public:
    void mia(){
        printf("Mia MEOW MEOW\n");
    }
    Gato(string nome, string raca):AnimalEstimacao(nome,raca){}
};

int main(){
    Cachorro dog("Toto", "Labrador");
    dog.latir();
    Gato cat("Bisteca", "Laranja");
    cat.mia();
    
}