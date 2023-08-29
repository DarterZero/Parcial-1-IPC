#include <stdio.h>
#include <stdlib.h>

int main(){
    int op, N1, N2, Res;
    do {
        FILE *archivo = fopen("salida.txt", "r");
        if (archivo == NULL) {
            printf("No se ha podido abrir el archivo para leer.\n");
            return 1;
        }
        printf("\n----------------------\n");
        printf("    %cque desea hacer?\n", 168);
        printf("1 - Lanzar dados\n");
        printf("2 - Ver el historial\n");
        printf("3 - Borrar historial\n");
        printf("4 - Salir\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
            N1 = rand () % 7;
            N2 = rand () % 7;
            Res = N1 + N2;
            FILE *archivo = fopen("salida.txt", "a");
            if (archivo == NULL) {
                printf("No se pudo abrir el archivo para escribir.\n");
                return 1; 
            }
            fprintf(archivo, "\nDado 1: %d, Dado 2: %d, Resultado: %d", N1, N2, Res);
            fclose(archivo);
            printf("Dado 1: %d, Dado 2: %d, Resultado: %d\n", N1, N2, Res);
            if(Res == 8){
                printf("Ganaste\n");
            } else if(Res == 7){
                printf("Perdiste\n");
            } else {
                printf("Vuelve a lanzar\n");
            }
            break;
            case 2:
                printf("Historial de tiradas\n");
                char linea[100];
                while (fgets(linea, sizeof(linea), archivo) != NULL) {
                    printf("%s", linea);
                }
                fclose(archivo);

            break;
            case 3:
                archivo = fopen("salida.txt", "w");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1;
                }
                fclose(archivo);
                printf("Historial borrado.\n");
                break;
            case 4:
                printf("Saliendo");
            break;
            default:
                printf("esa no es una opcion, marque otra vez");
        }
    } while(op != 4);
    return 0; 
}