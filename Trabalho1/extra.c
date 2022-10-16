#include <string.h>
#include <stdbool.h>

//****************** Checa se é uma data válida, inclui validação de ano bissexto
int validarData(int dia, int mes, int ano){
  //Validação de Ano
  if(ano < 0)
    return false;

  //Validação de dias e meses
  if (dia > 31 || dia <= 0 || mes <= 0 || mes > 12){
		return false;
	}
    
  else{
    if (mes != 2) {
      if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if (dia > 30){
					return false;
				}
      } 
    } 
    else{
      if(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)){
				if (dia > 29){
					return false;
				}
			}
			else if (dia > 28){
				return false;
			}
    }
  }

  return true;
}

//****************** Função que retorna o mês em inteiro dada a string de data
int mesInt (char validNasc[]){
  int identificador=0;
  int mes, str_count=0;
  
  for(int i=0;validNasc[i]!='\0';i++){ 
    if(validNasc[i] == '/'){
      if(identificador == 2)
        return false;
      else if(str_count == 0 || str_count > 2)
        return false;
      else if(identificador == 0)
          identificador++;
        else if(str_count == 2){
            if(identificador == 1){
              mes = ((validNasc[i-2] - 48) * 10) + (validNasc[i-1] - 48);
              return mes;
            }
        }
        else if (identificador == 1){
          mes = validNasc[i-1] - 48;
          return mes;
        }
      str_count = 0;
    }
    else
      str_count++;
  }

  return false;
}

//****************** Função que retorna o dia em inteiro dada a string de data
int diaInt(char validNasc[]){
  int dia, str_count=0;
  
  for(int i=0;validNasc[i]!='\0';i++){ 
    if(validNasc[i] == '/')
      if(str_count == 2){
        dia = ((validNasc[i-2] - 48) * 10) + (validNasc[i-1] - 48);
        break;
      }
      else{
        dia = validNasc[i-1] - 48;
        break;
      }
    else
      str_count++;
  }

  return dia;
}

//****************** Função que retorna o ano em inteiro dada a string de data
int anoInt(char validNasc[]){
  int ano = 0, index, soma, strCount = 0;
  
  for(index = strlen(validNasc)-1; validNasc[index] != '/'; strCount++, index--){
    soma = validNasc[index]-48; // Isolando um algarismo
    for(int i = 0; i < strCount; i++){
      soma *= 10; // Várias multiplicações por 10 para encontrar seu valor real, ex: 2015, o valor 2 vai ser multiplicado até ser 2000
    }
    ano += soma; // Colocando o valor real na variável que será a saída
  }
  if(strCount < 2 || strCount > 4){
    return -1;
  }

  return ano;
}

//****************** Se houver letras minusculas transformará em maiuscula para padronização do modelo das strings
void transformMaiusculo(char string[]){
  for(int i=0;string[i]!='\0';i++)
    if(string[i]>=97 && string[i]<=122)
      string[i] -= 32;
}