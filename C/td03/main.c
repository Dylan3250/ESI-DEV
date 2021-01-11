#include "newfunctions.h"

int main() {
    const char sentence1[] = "Hello";
    char sentence2[(sizeof (sentence1) / sizeof (char)) + 1];
    char sentence3[12];

    printf("Nombre de char dans 'l'array 'Hello' : %lld\n",
           newStrlen("Hello"));

    printf("World = World : %d\n",  newStrcmp("world", "world"));
    printf("Hello < HelloTest : %d\n",  newStrcmp("Hello", "HelloTest"));
    printf("HelloTest > Hello : %d\n", newStrcmp("HelloTest", "Hello"));

    newStrcpy(sentence2, sentence1); // Hello
    printf("Tableau vide après copie : %s\n", sentence2);

    newStrncpy(sentence3, sentence1, 3); // Hel
    printf("Tableau vide après 3 copies : %s\n", sentence3);

    newStrcat(sentence3, sentence1); // HelHello
    printf("Tableau vide après concaténation : %s\n", sentence3);

    newStrncat(sentence3, sentence1, 3); // HelHelloHel
    printf("Tableau vide après concaténation de 3 : %s\n", sentence3);

    printf("Phrase après découpe : ");
    char toSplit[] = "Hey how are you ?";
    char * token;
    token = newStrtok (toSplit, " ");
    while (token != NULL) {
        printf ("%s | ", token);
        token = newStrtok(NULL, " ");

    }
    printf("\n");
    return 0;
}
