class CriaCopia {
public static void main (String[] args){
Arq.openRead("DocumentoOriginal.txt");
int inteiro1 = Arq.readInt();
int inteiro2 = Arq.readInt();
int inteiro3 = Arq.readInt();
int inteiro4 = Arq.readInt();
int inteiro5 = Arq.readInt();
Arq.close();

Arq.openWrite("DocumentoCopia.txt");
Arq.println(inteiro1);
Arq.println(inteiro2);
Arq.println(inteiro3);
Arq.println(inteiro4);
Arq.println(inteiro5);

Arq.close();
}
}

