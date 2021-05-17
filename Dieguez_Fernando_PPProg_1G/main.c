#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} Notebook;

float aplicarDescuento(int precio);
int contarCaracteres(char str[], char caracter);
void orderByName(Notebook notebooks[], int size);
int swapNotebook(Notebook *NotebookA, Notebook *NotebookB);




int main()
{
    Notebook notebooks[3] {{1,"celeron","intel",101},{2,"buldozer","amd",103},{1,"sempron","intel",99}};
    float descuento = aplicarDescuento(100);
    printf("descuento: %.2f!\n", descuento);

    char myStr[10] = "Fernando";
    int contarN = 0;
    contarN = contarCaracteres(myStr, 'n');
    printf("caracteres: %d!\n", contarN);

    for(int i = 0; i < 3; i++){
        printf("notebook: %d\t%s\t%s%f!\n", notebooks[i].id, notebooks.procesador, notebooks.marca, notebooks.precio);
    }
    printf("\n\n", contarN);
    orderByName(notebooks, 3);
    for(int i = 0; i < 3; i++){
        printf("notebookOrd: %d\t%s\t%s%f!\n", notebooks[i].id, notebooks.procesador, notebooks.marca, notebooks.precio);
    }
    return 0;
}


float aplicarDescuento(int precio)
{
    float resultado;
    resultado = precio -= precio * 5 / 100;
    return resultado;
}

int contarCaracteres(char str[], char caracter)
{
    int ret = 0;
    if (str != NULL)
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == caracter)
            {
                ret++;
            }
        }
    }
    return ret;
}


void orderByName(Notebook notebooks[], int size)
{
    if (notebooks != NULL && 3 > 0)
    {
        for(int i = 0; i < 3-1; i++)
        {
            for(int j = i+1; j < 3 ; j++)
            {
                char nameA[20];
                strcpy(nameA,notebooks[i].marca);
                stringToLower(nameA);
                char nameB[20];
                strcpy(nameB,notebooks[j].marca);
                stringToLower(nameB);


                if (strcmp(nameA,nameB) > 0)
                {
                    swapNotebook(&notebooks[i],&notebooks[j]);
                }
                else if (strcmp(nameA,nameB) == 0){
                    int prizeA = notebooks[i].precio;
                    int prizeB = notebooks[j].precio;
                    if (prizeA > prizeB){
                        swapNotebook(&notebooks[i],&notebooks[j]);
                    }
                }
            }
        }
    }
}

int swapNotebook(Notebook *NotebookA, Notebook *NotebookB)
{
    int ret = 0;
    if (NotebookA != NULL && NotebookB != NULL)
    {
        Notebook aux;
        aux = *NotebookA;
        *NotebookA = *NotebookB;
        *NotebookB = aux;
        ret = 1;
    }
    return ret;
}
