#include <iostream>
using namespace std;

class Forma{
  public:
  ~Forma(){}

  virtual double perimetro() = 0;
  virtual double area() = 0;
  virtual void imprimir() = 0;

  static void mostrarForma(Forma* forma){
    forma->imprimir();
    printf("Perimetro: %.2lf\n", forma->perimetro());
    printf("Area: %.2lf\n", forma->area());
  }
};

class Retangulo: public Forma{
  
  protected:
  double base, altura;

  public:
  Retangulo(double b, double a): base(b), altura(a){}
  ~Retangulo(){}

  double area(){
    return base * altura;
  }
  double perimetro(){
    return (base + altura) * 2;
  }

  void imprimir(){
    printf("Retangulo, base: %.2lf, altura: %lf\n", base, altura);
  }
};

class Quadrado: public Retangulo{
  public:
  Quadrado(double l):Retangulo(l,l){}

  void imprimir(){
    printf("Quadrado, lado: %.2lf\n", base);
  }
};

class Circulo: public Forma{
  protected:
  int raio;

  public:
  Circulo(int raio){
    this->raio = raio;
  }

  double area(){
    return 2 * 3,14 * raio * raio;
  }
  
  double perimetro(){
    return 2 * 3,14 * raio;
  }

  void imprimir(){
    printf("Circulo, raio: %.2lf\n", raio);
  }

};

int main(){
  Retangulo retangulo(10,5);
  Quadrado quadrado(4);
  Circulo circulo(1);

  Forma::mostrarForma(&retangulo);
  Forma::mostrarForma(&quadrado);
  Forma::mostrarForma(&circulo);
}