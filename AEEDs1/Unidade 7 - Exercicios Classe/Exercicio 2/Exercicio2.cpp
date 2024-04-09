#include <iostream>
#include <string>
using namespace std;

class Relogio{
  private:
    int horas, minutos, segundos;
  public:
    void setHora(int horas, int minutos, int segundos){
      this->horas = horas;
      this->minutos = minutos;
      this->segundos = segundos;
    }
    string getHora(){
      char horaStr[9];
      sprintf(horaStr, "%02d:%02d:%02d", horas, minutos, segundos);
      return string(horaStr);
    }
    void AvancaHora(){
      segundos++;
      if(segundos == 60){
        segundos = 0;
        minutos++;
        }
      if(minutos == 60){
        minutos = 0;
        horas++;
      }
      if(horas == 24){
        horas = 0;
      }
    }
};

int main(){
  Relogio relogio;
  string horas;
  relogio.setHora(23, 59, 59);
  horas = relogio.getHora();
  cout << horas << endl;
  relogio.AvancaHora();
  horas = relogio.getHora();
  cout << horas << endl;
  relogio.AvancaHora();
  horas = relogio.getHora();
  cout << horas << endl;
}