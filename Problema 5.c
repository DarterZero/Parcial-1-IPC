#include <stdio.h>
#include <math.h>

int main(){
    int op, i, respuesta[6], Puntuacion;
    char Nombre[15];
    do {
        FILE *archivo = fopen("Puntuaciones.txt", "r");
        if (archivo == NULL) {
            printf("No se ha podido abrir el archivo para leer.\n");
            return 1;
        }
        printf("\n----------------------\n");
        printf("    %cque desea hacer?\n", 168);
        printf("1 - Jugar a las adivinanzas\n");
        printf("2 - Ver el historial de jugadores\n");
        printf("3 - Borrar historial de jugadores\n");
        printf("4 - Salir\n");
        scanf("%d", &op);

        switch(op) {
            case 1:
            Puntuacion = 0;
            for(i = 0; i < 6; i++){respuesta[i]=0;}
                printf("Tengo agujas pero no se coser, tengo numeros pero no se leer, las horas te doy, %cSabes quien soy?\n", 168);
                printf("Blanca por dentro, verde por fuera. Si no sabes, espera. %cQue es?\n", 168);
                printf("Antes huevecito, despues capullito y mas tarde volare como un pajarito. %cSabes quien soy?\n", 168);
                printf("Soy bonito por delante y algo feo por detras, me transformo a cada instante ya que imito a los demas. %cSabes quien soy?\n", 168);
                printf("Oro parece, plata no es. Abran las cortinas y veran lo que es.\n\n");
                printf("Posibles respuestas:\n");
                printf("1 - La mariposa.\n");
                printf("2 - El reloj.\n");
                printf("3 - El platano.\n");
                printf("4 - La pera.\n");
                printf("5 - El espejo.\n\n");
                printf("Escriba el numero de la respuesta para la adivinanza acontinuacion:\n");
                printf("Pregunta 1\n");
                scanf("%d", &respuesta[1]);
                printf("Pregunta 2\n");
                scanf("%d", &respuesta[2]);
                printf("Pregunta 3\n");
                scanf("%d", &respuesta[3]);
                printf("Pregunta 4\n");
                scanf("%d", &respuesta[4]);
                printf("Pregunta 5\n");
                scanf("%d", &respuesta[5]);

                for(i = 1; i < 6; i++){
                    if(respuesta[i] < 1||respuesta[i] > 5){
                        printf("Esa no era una opcion, Ingresela nuevamente\n");
                        i--;
                    }
                }
                if(respuesta[1] == 2){
                    Puntuacion++;
                } 
                if(respuesta[2] == 4){
                    Puntuacion++;
                }
                if(respuesta[3] == 1){
                    Puntuacion++;
                }
                if(respuesta[4] == 5){
                    Puntuacion++;
                }
                if(respuesta[5] == 3){
                    Puntuacion++;
                }
                    printf("Escriba su apodo(solo una palabra, max 20 letras)\n");
                    scanf("%s", &Nombre);
                    printf("%s saco %d Puntos\n", Nombre, Puntuacion);
                    FILE *archivo = fopen("Puntuaciones.txt", "a");
                    if (archivo == NULL) {
                        printf("No se pudo abrir el archivo para escribir.\n");
                        return 1; 
                    }
                    fprintf(archivo, "%s saco %d Puntos\n", Nombre, Puntuacion);
                    fclose(archivo);
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
                archivo = fopen("Puntuaciones.txt", "w");
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