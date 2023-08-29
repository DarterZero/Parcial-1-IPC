#include <stdio.h>
#include <math.h>

int main(){
    int op ; 
    double Prec, IVA, SinIVA;
    do {
        FILE *archivo = fopen("salida.txt", "r");
        if (archivo == NULL) {
            printf("No se ha podido abrir el archivo para leer.\n");
            return 1;
        }
        printf("\n----------------------\n");
        printf("    %cque desea hacer?\n", 168);
        printf("1 - Calcular el iva que se le agrego al producto\n");
        printf("2 - Ver el historial\n");
        printf("3 - Borrar historial\n");
        printf("4 - Salir\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
            printf("Ingrese el Precio del producto\n");
            scanf("%lf", &Prec);
            SinIVA = Prec * 100 / 112;
            IVA = Prec - SinIVA;
            FILE *archivo = fopen("salida.txt", "a");
            if (archivo == NULL) {
                printf("No se pudo abrir el archivo para escribir.\n");
                return 1; 
            }
            fprintf(archivo, "El Precio sin IVA es de : %.2lf\nSe esta pagando %.2lf de IVA\n", SinIVA, IVA);
            fclose(archivo);
            printf("El Precio sin IVA es de : %.2lf\nSe esta pagando %.2lf de IVA\n", SinIVA, IVA);
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