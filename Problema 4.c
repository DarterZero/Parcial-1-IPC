#include <stdio.h>
#include <math.h>

int main(){
    int op, i, primo, comp, Num, x;
    do {
        FILE *archivo = fopen("salida.txt", "r");
        if (archivo == NULL) {
            printf("No se ha podido abrir el archivo para leer.\n");
            return 1;
        }
        printf("\n----------------------\n");
        printf("    %cque desea hacer?\n", 168);
        printf("1 - Calcular si un numero es primo o compuesto\n");
        printf("2 - Ver el historial\n");
        printf("3 - Borrar historial\n");
        printf("4 - Salir\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
            x = 2;
            printf("Ingrese un numero entero\n");
            scanf("%d", &Num);
            if(Num == 0||Num == 1){
                printf("%d no es Primo ni Compuesto\n", Num);
                FILE *archivo = fopen("salida.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fprintf(archivo, "%d no es Primo ni Compuesto\n", Num);
                fclose(archivo);
            }else if(Num == 4){
                printf("%d es Compuesto\n", Num);
                FILE *archivo = fopen("salida.txt", "a");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fprintf(archivo, "%d es Compuesto\n", Num);
                fclose(archivo);
            } else{
            for(i = 2;i < Num / 2; i++){
                if(Num % i == 0){
                    x = 1;
                }
            }
            if(x != 1){x=0;}
            if (x == 1){
                printf("%d Es compuesto\n", Num);
                    FILE *archivo = fopen("salida.txt", "a");
                    if (archivo == NULL) {
                        printf("No se pudo abrir el archivo para escribir.\n");
                        return 1; 
                    }
                    fprintf(archivo, "%d Es compuesto\n", Num);
                    fclose(archivo);
            } else if( x == 0){
                printf("%d Es Primo\n", Num);
                    FILE *archivo = fopen("salida.txt", "a");
                    if (archivo == NULL) {
                        printf("No se pudo abrir el archivo para escribir.\n");
                        return 1; 
                    }
                    fprintf(archivo, "%d Es Primo\n", Num);
                    fclose(archivo);
            }
            }
            break;
            case 2:
                printf("Historial de calificaciones\n");
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