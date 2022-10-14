#include <string.h>
#include <stdbool.h>

//****************** Checa se é uma data válida, inclui validação de ano bissexto
int validarData(int dia, int mes, int ano){
  //Validação de Ano
  if(ano <= 0)
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
  int ano, tam;
  
  tam = strlen(validNasc);
  tam--;
  ano = ((validNasc[tam-3]-48)*1000) + ((validNasc[tam-2]-48)*100) + ((validNasc[tam-1]-48)*10) + (validNasc[tam]-48);

  return ano;
}

//****************** Se houver letras minusculas transformará em maiuscula para padronização do modelo das strings
void transformMaiusculo(char string[]){
  for(int i=0;string[i]!='\0';i++)
    if(string[i]>=97 && string[i]<=122)
      string[i] -= 32;
}