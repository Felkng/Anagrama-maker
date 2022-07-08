#include <stdio.h>
#include <string.h>
void quantificador(char anagrama[]){ //choose == 0 -> quantidade de anagramas existente // choose == 1 -> quantidade de anagramas repetidos
    char clone[10];
    int repetida[10];
    int i,j,n, o;
    int size,multi_repeat=1, resultado=0;
    size = strlen(anagrama);
    for(i=0;i<10;i++) //tira o lixo de memória do vetor repetida[]
        repetida[i]=0;
    for(i=0;anagrama[i] != '\0';i++){ //copia a palavra
        clone[i] = anagrama[i];
    }
    for(i=0,n=0;clone[i] != '\0'; i++){ //verifica se todas as letras sao iguais
        if(clone[i]==anagrama[0]){
            n++;
        }
    }
    for(i=0,j=0;clone[i] != '\0';j++){
        for(i=0;i<size;i++){
            if(clone[j]==anagrama[i] && anagrama[i] != '\n'){ //verifica se tem letras repetidas
                repetida[j]++;
                anagrama[i] = '\n';
            }
        }
        i=0;
        if(j==size)
            break;
    }
    for(i=0;i<10;i++){ //multiplicador de letras repetidas
        if(repetida[i] != 0)
            multi_repeat *= repetida[i];
    }
    for(i=size;i>0;i--){ //fatorial da palavra
        if(i==size){
            size=i*1;
            i--;
        }
        if(i==0)
            break;
        size *= i;
    }
    o = multi_repeat;
    if(size==1) //avalia se a palavra fornecida tem apenas uma letra, se sim, a palavra não tem repetição
        resultado=0;
    else if(n==strlen(anagrama) && n > 1)  //avalia se a palavra fornecida tem todas as letras iguais, se sim, apenas 1 dos anagramas não é repetição
        resultado = size-1;
    else if(n != strlen(anagrama)){ //avalia a quantidade de repetições em um anagrama complexo
        i = size;
        resultado = i/o;
        resultado = size - resultado;
    }
    if(multi_repeat==1) //avalia se a palavra fornecida não tem nenhuma repetição
        resultado=0;
    for(i=0;clone[i] != '\0';i++){ //recupera a palavra (útil apenas caso deseje retornar o anagrama)
        anagrama[i] = clone[i];
    }
    printf("Total de anagramas: %d\nTotal de anagramas repetidos: %d",size,resultado);
    }





int main(){
    char anagram[10];
    int i=0, posicao=1, n=0,z=1;
    int tamanho,piu=1,j,f;
    char change[10], trocador, x,l;
    scanf("%s",anagram);
    fflush(stdin);
    tamanho = strlen(anagram);
    for(i=0;anagram[i]!= '\0';i++){ //copia o anagrama
        change[i] = anagram[i];
    }
    for(i=tamanho-1;i>0;i--){ //quantidade permutação dos termos depois da "casa 0"
        piu *= i;
    }
    f=tamanho;
    for(i=tamanho-1 ; f>0 ; f--){
        for(n=piu;n>0;n--){
            printf("%s",change); //imprime o anagrama
            printf(" ");
            if(posicao==i){
                trocador = change[1];                                             //lógica das trocas -->  (ex de 5 letras)
                change[1] = change[posicao];                                      //                     X a b c d         (faz-se a troca dos termos depois de X
                change[posicao] = trocador;                                       //                     X b a c d
                posicao = 1;                                                      //                     X b c a d
            }                                                                     //                     X b c d a
            else{                                                                 //                     X a c d b (por fim, o ultimo termo troca com o 1º depois de X
                trocador = change[posicao];                                       //                     X b c d a (e recomeça o processo, porque posicao = i)
                change[posicao] = change[posicao+1];
                change[posicao+1] = trocador;
                if(posicao<i){
                posicao++;
            }
            }
        }
        printf("\n");
        printf("\n");
        posicao=1;
        for(j=0;j<10;j++){                                                    // recupera a palavra original para ser usada na próxima operação (troca da primeira letra)
            change[j] = anagram[j];
        }
            trocador = change[0];                                            //A primeira letra é trocada de acordo com o valor de Z -->  A x b c d
            change[0] = anagram[z];
            change[z] = trocador;
            z++;
    }
    quantificador(anagram);                                                //Imprime a quantidade de anagramas e a quantidade de repetições
    return 0;
}
