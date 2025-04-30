#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    const char* broker = "34.94.22.125"; // Your GCP MQTT IP
    const char* topic = "ledControl";
    char command[256];

    printf("MQTT LED Control\n");
    printf("1: Turn ON\n");
    printf("2: Turn OFF\n");
    printf("3: Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            snprintf(command, sizeof(command),
                     "mosquitto_pub -h %s -t %s -m \"ON\"", broker, topic);
            system(command);
            printf("Published: ON\n");
        } else if (choice == 2) {
            snprintf(command, sizeof(command),
                     "mosquitto_pub -h %s -t %s -m \"OFF\"", broker, topic);
            system(command);
            printf("Published: OFF\n");
        } else if (choice == 3) {
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid input. Try 1, 2, or 3.\n");
        }
    }

    return 0;
}
