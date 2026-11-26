#include <stdio.h>
#include <string.h>

#define MAX 100

struct Device
{
    int deviceID;
    char deviceType[20];

    float Vf, Ir, Vr;

    float maxVf, maxIr, maxVr;

    int outOfSpec;
};

int main()
{
    struct Device d[MAX];
    int n, i;

    printf("Enter the number of semiconductor devices: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX)
    {
        printf("Invalid number of devices!\n");
        return 1;
    }

    // Input details of all devices
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Device %d\n", i + 1);

        printf("Enter Device ID: ");
        scanf("%d", &d[i].deviceID);

        printf("Enter Device Type (Diode/BJT/MOSFET/LED): ");
        scanf("%19s", d[i].deviceType);

        // Validate device type
        while (strcmp(d[i].deviceType, "Diode") != 0 &&
               strcmp(d[i].deviceType, "BJT") != 0 &&
               strcmp(d[i].deviceType, "MOSFET") != 0 &&
               strcmp(d[i].deviceType, "LED") != 0)
        {
            printf("Invalid type! Enter Diode, BJT, MOSFET or LED: ");
            scanf("%19s", d[i].deviceType);
        }

        printf("Enter Forward Voltage (Vf) in volts: ");
        scanf("%f", &d[i].Vf);

        printf("Enter Reverse Leakage Current (Ir) in microamps: ");
        scanf("%f", &d[i].Ir);

        printf("Enter Rated Voltage (Vr) in volts: ");
        scanf("%f", &d[i].Vr);

        printf("\nEnter permissible maximum limits:\n");

        printf("Maximum Vf: ");
        scanf("%f", &d[i].maxVf);

        printf("Maximum Ir: ");
        scanf("%f", &d[i].maxIr);

        printf("Maximum Vr: ");
        scanf("%f", &d[i].maxVr);

        // Check operating limits
        d[i].outOfSpec =
            (d[i].Vf > d[i].maxVf) ||
            (d[i].Ir > d[i].maxIr) ||
            (d[i].Vr > d[i].maxVr);
    }

    // Display all device details
    printf("\n========== DEVICE DETAILS ==========\n");

    printf("%-8s %-10s %-10s %-10s %-10s %-15s\n",
           "ID", "Type", "Vf(V)", "Ir(uA)",
           "Vr(V)", "Status");

    for (i = 0; i < n; i++)
    {
        printf("%-8d %-10s %-10.2f %-10.2f %-10.2f %-15s\n",
               d[i].deviceID,
               d[i].deviceType,
               d[i].Vf,
               d[i].Ir,
               d[i].Vr,
               d[i].outOfSpec ?
               "OUT OF SPEC" : "WITHIN LIMIT");
    }

    // Display devices exceeding limits
    printf("\n===== OUT OF SPECIFICATION DEVICES =====\n");

    int found = 0;

    for (i = 0; i < n; i++)
    {
        if (d[i].outOfSpec)
        {
            found = 1;

            printf("\nDevice ID: %d", d[i].deviceID);
            printf("\nDevice Type: %s", d[i].deviceType);
            printf("\nExceeded parameters: ");

            if (d[i].Vf > d[i].maxVf)
                printf("Vf ");

            if (d[i].Ir > d[i].maxIr)
                printf("Ir ");

            if (d[i].Vr > d[i].maxVr)
                printf("Vr ");

            printf("\n");
        }
    }

    if (!found)
    {
        printf("No devices are Out of Specification.\n");
    }

    return 0;
}