//Bibliotecas Utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura do Veiculo
typedef struct Veiculo {
  char placa[8];
  char marca[50];
  char modelo[50];
  int ano;
  float preco;
  char tipo[10];
  char obs[100];
} Veiculo;

//Função do Menu Principal
void menu(){
  puts("Menu Principal:");
  puts("1 - Listar todos os veiculos");
  puts("2 - Pesquisar um veiculo");
  puts("3 - Cadastrar um veiculo");
  puts("4 - Editar um veiculo");
  puts("5 - Excluir um veiculo");
  puts("6 - Sair do programa");
}

//Função que realiza a persistência das informações no arquivo veiculos.txt
void SalvarArquivo(Veiculo veiculos[], int total){
    FILE * arquivo = fopen("veiculos.txt", "w");
    if (arquivo != NULL){
    fprintf(arquivo, "%d\n", total);
    for (int i = 0; i < total; i++){
        fprintf(arquivo, "%s;%s;%s;%d;%.2f;%s;%s\n", veiculos[i].placa, veiculos[i].marca, veiculos[i].modelo, veiculos[i].ano, veiculos[i].preco, veiculos[i].tipo, veiculos[i].obs);
        }
    }
    fclose(arquivo);
}

//Função para Listar os Veiculos
void listarVeiculos (Veiculo veiculos[], int total){
  printf("Total de Veiculos encontrados: %d\n", total);
  for (int i = 0; i < total; i++){
    printf("Veiculo %d\n", i +1);
    printf("Placa: %s\n", veiculos[i].placa);
    printf("Marca: %s\n", veiculos[i].marca);
    printf("Modelo: %s\n", veiculos[i].modelo);
    printf("Ano: %d\n", veiculos[i].ano);
    printf("Preco: R$ %.2f\n", veiculos[i].preco);
    printf("Tipo: %s\n", veiculos[i].tipo);
    printf("Observacao adicional: %s\n", veiculos[i].obs);
    printf("\n");
  }
}

//Função para Pesquisar os Veículos
void pesquisaVeiculos (Veiculo veiculos[], int total){
  char pesquisaPlaca[8];
  int encontrarVeiculo = 0;
  puts("Digite a placa do veiculo que deseja pesquisar sobre:");
  scanf("%s", pesquisaPlaca);
  int tam = 0;
  tam = strlen(pesquisaPlaca);
  while (tam != 7){
      puts("Placa Invalida, digite novamente (7 caracteres):");
      scanf("%s", pesquisaPlaca);
      tam = strlen(pesquisaPlaca);
  }
  for (int i = 0; i < total; i++){
    if(strcmp(pesquisaPlaca, veiculos[i].placa) == 0){
      printf("\nVeiculo Encontrado!\n");
      printf("Placa: %s\n", veiculos[i].placa);
      printf("Marca: %s\n", veiculos[i].marca);
      printf("Modelo: %s\n", veiculos[i].modelo);
      printf("Ano: %d\n", veiculos[i].ano);
      printf("Preco: R$ %.2f\n", veiculos[i].preco);
      printf("Tipo: %s\n", veiculos[i].tipo);
      printf("Observacao adicional: %s\n", veiculos[i].obs);
      printf("\n");
      encontrarVeiculo = 1;
    }
  }

  //Caso nenhum veículo seja encontrado
  if (!encontrarVeiculo){
    puts("Veiculo nao encontrado no sistema");
  }
}

//Função para Cadastrar Veículos
void cadastraVeiculos(Veiculo veiculos[], int *total){
  //Verifica se há espaço reservado na memória para novos veículos
  if (*total >= 100){
    puts("Nao e possivel cadastrar mais veiculos, exclua algum da memoria");
    return;
  }

  //Cria um novo objeto para o veiculo novo
  Veiculo veiculonovo;
  puts("Digite a placa do veiculo que deseja cadastrar (7 caracteres):");
  scanf("%s", veiculonovo.placa);
  int tam = 0;
  tam = strlen(veiculonovo.placa);
  while (tam != 7){
      puts("Placa Invalida, digite novamente (7 caracteres):");
      scanf("%s", veiculonovo.placa);
      tam = strlen(veiculonovo.placa);
  }

  //Verifica se a placa digitada já existe
  for (int i = 0; i < *total; i++){
    if(strcmp(veiculonovo.placa, veiculos[i].placa) == 0){
      puts("Placa de veiculo ja cadastrada no sistema, use uma placa nao cadastrada");
      return;
    }
  }

  puts("Digite a Marca do novo veiculo:");
  scanf("%s", veiculonovo.marca);
  puts("Digite o Modelo do novo veiculo:");
  scanf("%s", veiculonovo.modelo);
  puts("Digite o Ano do novo veiculo:");
  scanf("%d", &veiculonovo.ano);
  puts("Digite o Preco do novo veiculo:");
  scanf("%f", &veiculonovo.preco);
  puts("Digite o Tipo de Veiculo cadastrado");
  scanf("%s", veiculonovo.tipo);
  puts("Deseja acrescescentar alguma informacao adicional? Caso nao, digite X\n");
  scanf(" %[^\n]", veiculonovo.obs);

  //Adiciona o veiculo novo a próxima posição livre do Array e incrementa o total de veiculos existentes
  veiculos[*total] = veiculonovo;
  (*total)++;
  SalvarArquivo(veiculos, *total);
  puts("Veiculo cadastrado com sucesso!");
}

//Função para Editar Veículos
void editaVeiculos(Veiculo veiculos[], int total){
  char pesquisaPlaca[8];
  int encontrarVeiculo = 0;
  puts("Digite a placa do veiculo que pretende editar:");
  scanf("%s", pesquisaPlaca);
  int tam = 0;
  tam = strlen(pesquisaPlaca);
  while (tam != 7){
      puts("Placa Invalida, digite novamente (7 caracteres):");
      scanf("%s", pesquisaPlaca);
      tam = strlen(pesquisaPlaca);
  }

  //Pesquisa se existe um veículo com aquela placa
  for (int i = 0; i < total; i++){
    if(strcmp(pesquisaPlaca, veiculos[i].placa) == 0){
      //Mostra as informações do veículo pesquisado
      printf("\nVeiculo Encontrado!\n");
      printf("Placa: %s\n", veiculos[i].placa);
      printf("Marca: %s\n", veiculos[i].marca);
      printf("Modelo: %s\n", veiculos[i].modelo);
      printf("Ano: %d\n", veiculos[i].ano);
      printf("Preco: R$ %.2f\n", veiculos[i].preco);
      printf("Tipo: %s\n", veiculos[i].tipo);
      printf("Observacao adicional: %s\n", veiculos[i].obs);
      printf("\n");
      //O usuário insere as novas informações do veículo
      puts("Insira as novas informacoes do veiculo pesquisado:");
      printf("Marca:");
      scanf("%s", veiculos[i].marca);
      printf("Modelo:");
      scanf("%s", veiculos[i].modelo);
      printf("Ano:");
      scanf("%d", &veiculos[i].ano);
      printf("Preco:");
      scanf("%f", &veiculos[i].preco);
      printf("Tipo:");
      scanf("%s", veiculos[i].tipo);
      printf("Deseja acrescescentar alguma informacao adicional? Caso nao, digite X\n");
      scanf(" %[^\n]", veiculos[i].obs);

      SalvarArquivo(veiculos, total);
      puts("Veiculo editado com sucesso!");
      encontrarVeiculo = 1;
    }
  }

  //Caso nenhum veículo seja encontrado
  if (!encontrarVeiculo){
    puts("Veiculo nao encontrado no sistema");
  }
}

//Função para Excluir Veículos
void excluiVeiculos(Veiculo veiculos[], int * total){
  char pesquisaPlaca[8], confirmacao;
  int encontrarVeiculo = 0, posicaoVeiculo;
  puts("Digite a placa do veiculo que pretende excluir:");
  scanf("%s", pesquisaPlaca);
  int tam = 0;
  tam = strlen(pesquisaPlaca);
  while (tam != 7){
      puts("Placa Invalida, digite novamente (7 caracteres):");
      scanf("%s", pesquisaPlaca);
      tam = strlen(pesquisaPlaca);
  }

  //Pesquisa se existe um veículo com aquela placa
  for (int i = 0; i < *total; i++){
    if(strcmp(pesquisaPlaca, veiculos[i].placa) == 0){
      //Mostra as informações do veículo pesquisado
      printf("\nVeiculo Encontrado!\n");
      printf("Placa: %s\n", veiculos[i].placa);
      printf("Marca: %s\n", veiculos[i].marca);
      printf("Modelo: %s\n", veiculos[i].modelo);
      printf("Ano: %d\n", veiculos[i].ano);
      printf("Preco: R$ %.2f\n", veiculos[i].preco);
      printf("Tipo: %s\n", veiculos[i].tipo);
      printf("Observacao adicional: %s\n", veiculos[i].obs);
      printf("\n");

      puts("Tem certeza que pretende excluir este veiculo? (S/N)");
      scanf(" %c", &confirmacao);
      if(confirmacao == 'S' || confirmacao == 's'){
        posicaoVeiculo = i;
        encontrarVeiculo = 1;
      } else{
        return;
      }
    }
  }

  //Caso nenhum veículo seja encontrado
  if (!encontrarVeiculo){
    puts("Veiculo nao encontrado no sistema");
  } else {
    //Move veiculos em posições a frente para trás, gerando a exclusão
    for (int i = posicaoVeiculo; i < *total - 1; i++){
      veiculos[i] = veiculos[i+1];
    }
    puts("Veiculo excluido com sucesso!");
    (*total)--;
    SalvarArquivo(veiculos, *total);
  }
}

//Código principal
int main (){
  Veiculo veiculos[100];
  int total = 0, escolha;

  //Ler o arquivo veiculos.txt no inicio do programa
  FILE * arquivo = fopen("veiculos.txt", "r");
  if (arquivo == NULL){
    puts("Impossivel continuar. Nao foi possivel ler o arquivo de veiculos :(");
    return 0;
  }
  fscanf(arquivo, "%d", &total);
  for (int i = 0; i < total; i++){
    fscanf(arquivo, " %[^;];%[^;];%[^;];%d;%f;%[^;];%[^\n]", veiculos[i].placa,veiculos[i].marca,veiculos[i].modelo,&veiculos[i].ano,&veiculos[i].preco,veiculos[i].tipo,veiculos[i].obs);
  }
  fclose(arquivo);

  //Menu Principal sempre aparece até que saia do programa
    do {
    menu();
    scanf("%d", &escolha);
    switch(escolha){
      case 1:
        listarVeiculos(veiculos, total);
        break;
      case 2:
        pesquisaVeiculos(veiculos, total);
        break;
      case 3:
        cadastraVeiculos(veiculos,&total);
        break;
      case 4:
        editaVeiculos(veiculos, total);
        break;
      case 5:
        excluiVeiculos(veiculos, &total);
        break;
      case 6:
        puts("Obrigado por usar nosso programa! Tenha um excelente dia :)");
        break;
      default:
        puts("Escolha invalida, tente digitar um dos números do Menu Principal");
    }
  } while (escolha != 6);


  return 0;
}
