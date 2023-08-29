#include <stdio.h>
#include <math.h>

int main(){
    int op, i, j, posM, pos; 
    double Cal[5], g, Var, Aux[5], Mayor, Media, Mediana, Moda, Rango, De;
    do {
        FILE *archivo = fopen("salida.txt", "r");
        if (archivo == NULL) {
            printf("No se ha podido abrir el archivo para leer.\n");
            return 1;
        }
        printf("\n----------------------\n");
        printf("    %cque desea hacer?\n", 168);
        printf("1 - Calcular Calificaciones\n");
        printf("2 - Ver el historial\n");
        printf("3 - Borrar historial\n");
        printf("4 - Salir\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("ingrese 5 Calificaciones (0-100) de menor a mayor (presione ENTER despues de cada una):\n");
                for(i = 0; i < 5; i++){
                    scanf("%lf", &Cal[i]);
                    if(Cal[i] < 0 || Cal[i] > 100){
                        printf("Nota no valida, ingresela nuevamente\n");
                        i--;
                    }
                    if(Cal[i] < Cal[i-1]){
                        printf("no esta ingresando las notas en orden, ingreselas de nuevo\n");
                        i = -1;
                    }
                }
                Media = Cal[0];
                for(i = 1; i < 5; i++){
                    Media = Media + Cal[i];
                }
                Media = Media/5;
                Mediana = Cal[2];
                for(i = 0;i < 5;i++){
                    Aux[i] = 0;
                }
                for(i = 0; i < 5;i++){
                    g = Cal[i];
                    pos = i;
                    for(j = i; j < 5;j++){
                        if(Cal[j]==g){Aux[pos]++;}
                    }
                }
                Mayor = Aux[0];
                posM = 0;
                for(i = 0; i < 5;i++){
                    if(Aux[i] > Mayor){
                        posM = i;
                        Mayor = Aux[i];
                    }
                }
                Moda = Cal[posM];
                Rango = Cal[4] - Cal[0]; 
                Var =  pow(Cal[0] - Media,2) + pow(Cal[1] - Media,2) +pow(Cal[2] - Media,2) +pow(Cal[3] - Media,2) +pow(Cal[4] - Media,2);
                Var = Var/5;
                De = sqrt(Var);
            FILE *archivo = fopen("salida.txt", "a");
            if (archivo == NULL) {
                printf("No se pudo abrir el archivo para escribir.\n");
                return 1; 
            }
            fprintf(archivo, "Media: %.2lf, Mediana: %.2lf, Moda: %.2lf, Rango: %.2lf, Desv. Est.: %.2lf, Varianza: %.2lf\n", Media, Mediana, Moda, Rango, De, Var );
            fclose(archivo);
            printf("Media: %.2lf, Mediana: %.2lf, Moda: %.2lf, Rango: %.2lf, Desv. Est.: %.2lf, Varianza: %.2lf\n", Media, Mediana, Moda, Rango, De, Var);
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